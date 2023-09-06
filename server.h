# ifndef H_SERVER_H
# define H_SERVER_H

/* Includes */
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include "libft/libft.h"
# include <stdio.h> // remove and use my own.
# include <arpa/inet.h> // for inet_top
# include <sys/epoll.h>
// # include <signal.h>

/* Defines */
# define SEND_NO_FLAG 0
# define MAX_EPOLL_WAIT_BUFFER 128
# define EPOLL_BLOCK_UNDEFINITELY -1


/* Helper */
void    printAddrInfo(struct addrinfo servInfo);
void    printSocketAddr(struct sockaddr *socketAddr);

#endif