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

    if (listen(socketFD, MAX_PENDING_CONNECTIONS) < 0) {
        perror("Listening error");
        return 1;
    }

    struct sockaddr_storage inConnInfos;
    socklen_t inConnInfosLength;
    int inConnFD;

    while (1) {
        inConnInfosLength = sizeof(inConnInfos);
        if ((inConnFD = accept(socketFD, (struct sockaddr*)&inConnInfos, &inConnInfosLength)) < 0) {
            perror("Accept error");
            continue;
        }
        printSocketAddr((struct sockaddr*)&inConnInfos);

        if (!fork()) {
            close(socketFD);
            char *response = "HTTP/1.1 200 OK\nContent-type: text/html\n\n<h1>why are you gay ?</h1>\n\n";
            if (send(inConnFD, response, ft_strlen(response), SEND_NO_FLAG) < 0) {
                perror("Send error");
            }
            close(inConnFD);
            return 0;
        }
        close(inConnFD);
    }
    return 0;
}