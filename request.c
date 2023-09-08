#include "server.h"

void *readRequest(struct epoll_event epollTrigueredEvent, int debugg) {
    char buffer[READ_BUFF_SIZE];
    int oldLength = 0;
    int readBytes = 0;
    char *request = NULL;

    if (debugg)
        ft_putendl(
            "--------------------- Reading connection content "
            "---------------------");

    while ((readBytes = read(epollTrigueredEvent.data.fd, buffer,
                             READ_BUFF_SIZE)) > 0) {
        if (!request) {
            request = ft_strnew(readBytes);
            ft_memcpy(request, buffer, readBytes);
            oldLength += readBytes;
        } else {
            request = ft_realloc(request, oldLength, oldLength + readBytes);
            ft_memcpy(request + oldLength, buffer, readBytes);
            oldLength += readBytes;
        }
    }
    if (debugg) {
        ft_putstr(request);
        ft_putendl(
            "--------------------- FINISHEEEEEEED READING "
            "---------------------");
    }

    return request;
}
