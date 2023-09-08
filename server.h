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

/* Defines */
#define SEND_NO_FLAG 0
#define MAX_EPOLL_WAIT_BUFFER 128
#define EPOLL_BLOCK_UNDEFINITELY -1
#define READ_BUFF_SIZE 1024

/* Helper */
void printAddrInfo(struct addrinfo servInfo);
void printSocketAddr(struct sockaddr *socketAddr);
void *readRequest(struct epoll_event epollTrigueredEvent, int debugg);

#endif