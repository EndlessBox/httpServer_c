#ifndef H_SERVER_H
#define H_SERVER_H

/* Includes */
#include <arpa/inet.h>  // for inet_ntop
#include <errno.h>
#include <netdb.h>
#include <stdio.h>  // remove and use my own.
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "libft/libft.h"

/* Enums */
typedef enum   S_HTTP_METHODS{ GET, POST } T_HTTP_METHODS;

/* Defines */
#define SEND_NO_FLAG 0
#define MAX_EPOLL_WAIT_BUFFER 128
#define EPOLL_BLOCK_UNDEFINITELY -1
#define READ_BUFF_SIZE 1024
#define S_GET "GET"
#define S_POST "POST"
#define HTTP_1_1 "HTTP/1.1"
#define SPACE_DELIMITER 32

#define PUT_NBR_DEBUGG(x, y) ft_putstr(x); ft_putnbr(y); ft_putchar('\n');


/* Structs */
typedef struct      s_headers {
    int             method;
    char            *requestURI;
}                   t_headers;

/* Helper */
void    printAddrInfo(struct addrinfo servInfo);
void    printSocketAddr(struct sockaddr *socketAddr);
void    *readRequest(struct epoll_event epollTrigueredEvent, int debugg);
int     verifyAndParseRequestLine(char *request, t_headers *headers);

#endif