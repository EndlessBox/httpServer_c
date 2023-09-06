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

    if ((status = getaddrinfo(NULL, "3490", &config, &servInfo))) {
        printf("getaddrinfo error: %s\n", gai_strerror(status));
        return (1);
    }
    while (servInfo) {
        if (((socketFD = socket(servInfo->ai_family, servInfo->ai_socktype, servInfo->ai_protocol)) < 0)) {
            perror("socket creation failed");
            return 1;
        }

        int optval = 1;

        if (setsockopt(socketFD, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) < 0) {
            perror("setsocketopt error");
            return 1;
        }

        if (bind(socketFD, servInfo->ai_addr, servInfo->ai_addrlen) < 0)  {
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

    if((epollFD = epoll_create1(SEND_NO_FLAG)) < 0) {
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
        perror("epoll_ctl add socket connection fd error");
        return 1;
    }

    struct epoll_event *epollTrigueredEvents;
    if (!(epollTrigueredEvents = malloc(sizeof(struct epoll_event) * MAX_EPOLL_WAIT_BUFFER))) {
        perror("epoll triguered events allocation error");
        return 1;
    }

    while (1) {
        int triggueredEvents;
        int jumper = -1;

        triggueredEvents = epoll_wait(epollFD, epollTrigueredEvents, MAX_EPOLL_WAIT_BUFFER, EPOLL_BLOCK_UNDEFINITELY);
        while(++jumper < triggueredEvents) {
            uint32_t isEpollErr = epollTrigueredEvents[jumper].events & EPOLLERR;
            uint32_t isEpollHangUp = epollTrigueredEvents[jumper].events & EPOLLHUP;
            uint32_t isEpollNotAvai = !(epollTrigueredEvents[jumper].events & EPOLLIN);

            if (isEpollErr || isEpollHangUp || isEpollNotAvai) {
                ft_putstr_fd("closing connection fd", STDERR_FILENO);
                close(epollTrigueredEvents[jumper].data.fd);
                continue;
            } else if (epollTrigueredEvents[jumper].data.fd == socketFD) {
                // accept and push fd to epoll
            } else {
                // read data sent by connection (full read EPOLLET !!!!)
            }
        }

    }


    // struct sockaddr_storage inConnInfos;
    // socklen_t inConnInfosLength;
    // int inConnFD;

    // while (1) {
        // inConnInfosLength = sizeof(inConnInfos);
        // if ((inConnFD = accept(socketFD, (struct sockaddr*)&inConnInfos, &inConnInfosLength)) < 0) {
        //     perror("Accept error");
        //     continue;
        // }
        // printSocketAddr((struct sockaddr*)&inConnInfos);

        // if (!fork()) {
        //     close(socketFD);
        //     char *response = "HTTP/1.1 200 OK\nContent-type: text/html\n\n<h1>why are you gay ?</h1>\n\n";
        //     if (send(inConnFD, response, ft_strlen(response), SEND_NO_FLAG) < 0) {
        //         perror("Send error");
        //     }
        //     close(inConnFD);
        //     return 0;
        // }
        // close(inConnFD);
    // }
    return 0;
}