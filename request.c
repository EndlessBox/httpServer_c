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
        if (!request && readBytes) {
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
    if (!(delimiter = ft_strchr(tmp, SPACE_DELIMITER)))
        return 1;
    if (!(headers->requestURI = ft_strndup(tmp, delimiter - tmp)))
        return 1;
    tmp = delimiter + 1;
    if (ft_strncmp(tmp, HTTP_1_1, HTTP_VERSION_LENGTH) != 0) {
        free(headers->requestURI);
        return 1;
    }
    return 0;
}

int verifyAndStoreHeaderTokens(char **request, t_headers *s_headers) {
    while (ft_strlen(*request) > 1) {
        char *colonDelimiter;
        char *newLineDelimiter;

        if (!(colonDelimiter = ft_strchr(*request, COLON)) || !(newLineDelimiter = ft_strchr(*request, '\0')))
            return 1;
        if ((*(colonDelimiter + 1)) != SPACE_DELIMITER)
            return 1;
        appendNewToken(*request, colonDelimiter - (*request), colonDelimiter + 2, newLineDelimiter - colonDelimiter - 2, s_headers);
        request++;
    }
    return 0;
}

int appendNewToken(char *key, size_t keySize, char  *value, size_t valueSize, t_headers *s_headers) {
    t_tokens *s_tokens = s_headers->s_tokens;
    if (!s_tokens) {
        s_tokens = malloc(sizeof(t_tokens));
        s_tokens->next = NULL;
        s_tokens->tail = s_tokens;
        s_headers->s_tokens = s_tokens;
    } else {
        s_tokens->tail->next = malloc(sizeof(t_tokens));
        s_tokens->tail = s_tokens->tail->next;
        s_tokens->tail->next = NULL;

    }


    /*
     ********************************************************************************************
     * if it fails need to trigger a full free of the linked list ! either here or in parents !!!
     ********************************************************************************************
    */ 
    if (!(s_tokens->tail->key = ft_strndup(key, keySize)))
        return 1;
    if(!(s_tokens->tail->value = ft_strndup(value, valueSize)))
        return 1;
    return 0;
}


