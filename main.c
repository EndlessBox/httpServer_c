#include "server.h"

int main(void) {
    int status;
    struct addrinfo config;
    struct addrinfo *servInfo;
    int socketFD;
    struct addrinfo choosenServInfo;

    ft_memset(&config, 0, sizeof config);
    config.ai_family = AF_UNSPEC;
    config.ai_socktype = SOCK_STREAM;
    config.ai_flags = AI_PASSIVE;

    if ((status = getaddrinfo(NULL, "80", &config, &servInfo))) {
        printf("getaddrinfo error: %s\n", gai_strerror(status));
        return (1);
    }
    while (servInfo) {
        if (((socketFD = socket(servInfo->ai_family, servInfo->ai_socktype,
                                servInfo->ai_protocol)) < 0)) {
            perror("socket creation failed");
            return 1;
        }

        int optval = 1;

        if (setsockopt(socketFD, SOL_SOCKET, SO_REUSEADDR, &optval,
                       sizeof(int)) < 0) {
            perror("setsocketopt error");
            return 1;
        }

        if (bind(socketFD, servInfo->ai_addr, servInfo->ai_addrlen) < 0) {
            close(socketFD);
            if (!servInfo->ai_next) {
                perror("Failed to bind");
                return 1;
            }
            servInfo = servInfo->ai_next;
            continue;
        }
        break;
    }

    choosenServInfo = *servInfo;
    freeaddrinfo(servInfo);

    ft_putendl("Binded succefully");
    printAddrInfo(choosenServInfo);

    if (fcntl(socketFD, F_SETFL, O_NONBLOCK) < 0) {
        perror("Fcntl set non blocking error");
        return 1;
    }

    if (listen(socketFD, SOMAXCONN) < 0) {
        perror("Listening error");
        return 1;
    }

    int epollFD;
    struct epoll_event epollEvent;

    if ((epollFD = epoll_create1(SEND_NO_FLAG)) < 0) {
        perror("epoll instance creation error");
        return 1;
    }

    epollEvent.data.fd = socketFD;
    /*
     *  EPOLLIN : Associated file descriptor is available for read.
     *  EPOLLET : edge-triggered, read all before moving on.
     */
    epollEvent.events = EPOLLIN | EPOLLET;

    if (epoll_ctl(epollFD, EPOLL_CTL_ADD, socketFD, &epollEvent) < 0) {
        perror("epoll_ctl add listener socket epoll event error");
        return 1;
    }

    struct epoll_event *epollTrigueredEvents;
    if (!(epollTrigueredEvents =
              malloc(sizeof(struct epoll_event) * MAX_EPOLL_WAIT_BUFFER))) {
        perror("epoll triguered events allocation error");
        return 1;
    }

    while (1) {
        int triggueredEvents;
        int jumper = -1;

        triggueredEvents =
            epoll_wait(epollFD, epollTrigueredEvents, MAX_EPOLL_WAIT_BUFFER,
                       EPOLL_BLOCK_UNDEFINITELY);
        while (++jumper < triggueredEvents) {
            uint32_t isEpollErr =
                epollTrigueredEvents[jumper].events & EPOLLERR;
            uint32_t isEpollHangUp =
                epollTrigueredEvents[jumper].events & EPOLLHUP;
            uint32_t isEpollNotAvai =
                !(epollTrigueredEvents[jumper].events & EPOLLIN);

            if (isEpollErr || isEpollHangUp || isEpollNotAvai) {
                close(epollTrigueredEvents[jumper].data.fd);
                continue;
            } else if (epollTrigueredEvents[jumper].data.fd == socketFD) {
                // accept and push fd to epoll
                struct sockaddr_storage inConnInfos;
                socklen_t inConnInfosLength;
                struct epoll_event inEpollEvent;

                while (1) {
                    inConnInfosLength = sizeof(inConnInfos);
                    if ((inEpollEvent.data.fd =
                             accept(socketFD, (struct sockaddr *)&inConnInfos,
                                    &inConnInfosLength)) < 0)
                        break;

                    printSocketAddr((struct sockaddr *)&inConnInfos);
                    if (fcntl(inEpollEvent.data.fd, F_SETFL, O_NONBLOCK) < 0) {
                        perror(
                            "Fcntl set incoming connection socket non blocking "
                            "error");
                        return 1;
                    }
                    inEpollEvent.events = EPOLLIN | EPOLLET;
                    if (epoll_ctl(epollFD, EPOLL_CTL_ADD, inEpollEvent.data.fd,
                                  &inEpollEvent) < 0) {
                        perror(
                            "epoll add incoming connection socket epoll event "
                            "error");
                        return 1;
                    }
                }
            } else {
                int currentConnectionFD = epollTrigueredEvents[jumper].data.fd;
                t_headers   headers;
                char **request = ft_strsplit(readRequest(epollTrigueredEvents[jumper], 1), NEW_LINE);

                headers.s_tokens = NULL;
                if (verifyAndParseRequestLine(*request, &headers)) {
                    ft_putendl("Failed to parse request line, closing connection");
                    close(currentConnectionFD);
                }
                
                PUT_STR_DEBUGG("Request Line", *(request + 1))
                if (verifyAndStoreHeaderTokens(request + 1, &headers)) {
                    ft_putendl("Failed to parse header tokens, closing connection");
                    send(currentConnectionFD, "By", 2, 0);
                    close(currentConnectionFD);
                }

                printTokens(headers.s_tokens);


                char *response = "coonnection was man dakchi l kharej";
                send(currentConnectionFD, response, ft_strlen(response), 0);
                close(currentConnectionFD);
            }
        }
    }
    free(epollTrigueredEvents);
    close(socketFD);
    return 0;
}
