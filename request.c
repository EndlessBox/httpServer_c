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


int    verifyAndParseRequestLine(char *request, t_headers *headers) {
    void    *tmp = request;
    void    *delimiter;
    char    *token;

    if (!(delimiter = ft_strchr(tmp, SPACE_DELIMITER)))
        return 1;
    if (!(token = ft_strndup(tmp, delimiter - tmp)))
        return 1;

    if (ft_strcmp(token, S_GET) == 0)
        headers->method = GET;
    else if (ft_strcmp(token, S_POST) == 0)
        headers->method = POST;
    else
        return 1; // should be changed to better error handling !
    
    free(token);
    tmp = delimiter + 1;
    if (!(delimiter = ft_strchr(tmp, ' ')))
        return 1;
    if (!(headers->requestURI = ft_strndup(tmp, delimiter - tmp)))
        return 1;
    tmp = delimiter + 1;
    if (ft_strcmp(tmp, HTTP_1_1) != 0) {
        free(headers->requestURI);
        return 1;
    }

    return 0;
}
