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
#define HTTP_VERSION_LENGTH 8
#define SPACE_DELIMITER 32
#define NEW_LINE 10
#define COLON 58

#define PUT_NBR_DEBUGG(x, y) ft_putstr(x); ft_putnbr(y); ft_putchar('\n');
#define PUT_STR_DEBUGG(x, y) ft_putstr(x); ft_putendl(y);


/* Structs */
typedef struct      s_tokens {
// if finding a specific headers takes too much time, i might do some hash table or something, but will test this for now
    char            *key;
    char            *value;
    struct s_tokens *tail;
    struct s_tokens *next;
}                   t_tokens;

typedef struct      s_headers {
    int             method;
    char            *requestURI;
    char            *host;
    t_tokens        *s_tokens;
}                   t_headers;

/* Helper */
void    printAddrInfo(struct addrinfo servInfo);
void    printSocketAddr(struct sockaddr *socketAddr);
void    printTokens(t_tokens *s_tokens);
void    *readRequest(struct epoll_event epollTrigueredEvent, int debugg);
int     verifyAndParseRequestLine(char *request, t_headers *headers);
int     verifyAndStoreHeaderTokens(char **request, t_headers *s_headers);
int     appendNewToken(char *key, size_t keySize, char  *value, size_t valueSize, t_headers *s_headers);

#endif