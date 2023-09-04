#include "server.h"

int main(void) {
    int status;
    struct addrinfo config;
    struct addrinfo *servinfo;
    int socketFD;

    ft_memset(&config, 0, sizeof config);
    config.ai_family = AF_UNSPEC;
    config.ai_socktype = SOCK_STREAM;
    config.ai_flags = AI_PASSIVE;

    if ((status = getaddrinfo(NULL, "3490", &config, &servinfo))) {
        printf("getaddrinfo error: %s\n", gai_strerror(status));
        return (1);
    }

    // void *addr;
    // char *ipver = "IPv4";
    // char ipstr[INET6_ADDRSTRLEN];

    // if (servinfo->ai_family == AF_INET) {
    //     addr = &((struct sockaddr_in *)servinfo->ai_addr)->sin_addr;
    //     inet_ntop(servinfo->ai_family, addr, ipstr, sizeof(ipstr));
    //     printf("%s: %s", ipver, ipstr);
    // }

    if ((socketFD = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol))) {
        printf("getaddrinfo error: %s\n", gai_strerror(status));
        return (1);
    }

    

    return 0;
}