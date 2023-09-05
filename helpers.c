#include "server.h"

void    printAddrInfo(struct addrinfo servInfo) {
    void *addr;
    char *ipver = "IPv4";
    char ipstr[INET6_ADDRSTRLEN];

    if (servInfo.ai_family == AF_INET) {
        addr = &((struct sockaddr_in *)servInfo.ai_addr)->sin_addr;
        inet_ntop(servInfo.ai_family, addr, ipstr, sizeof(ipstr));
        printf("%s: %s\n", ipver, ipstr);
    }
}

void    printSocketAddr(struct sockaddr *socketAddr) {
    void *addr = &(((struct sockaddr_in*)socketAddr)->sin_addr);
    char ipstr[INET6_ADDRSTRLEN];

    inet_ntop(socketAddr->sa_family, addr, ipstr, sizeof(ipstr));
    ft_putstr("new connection from : ");
    ft_putendl(ipstr);
}