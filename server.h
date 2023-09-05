# ifndef H_SERVER_H
# define H_SERVER_H

/* Includes */
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include "libft/libft.h"
# include <stdio.h> // remove and use my own.
# include <arpa/inet.h> // for inet_top
// # include <signal.h>

/* Defines */

# define MAX_PENDING_CONNECTIONS 10
# define SEND_NO_FLAG 0


/* Helper */
void    printAddrInfo(struct addrinfo servInfo);
void    printSocketAddr(struct sockaddr *socketAddr);

#endif