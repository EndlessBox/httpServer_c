/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <ybouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:33:52 by ybouladh          #+#    #+#             */
/*   Updated: 2020/10/24 10:09:37 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_next_line(const int fd, char **line)
{
	char			*tmp;
	int				length;
	static char		*rest;
	void			*holder;
	int				len_rest;

	if (BUFF_SIZE <= 0 || fd < 0 || BUFF_SIZE > MAX_INT)
		return (-1);
	if (rest && (holder = ft_strchr(rest, '\n')))
	{
		length = ft_strlenc(rest, '\n');
		if ((*line = ft_strnew(length)))
		{
			ft_strncpy(*line, rest, length);
			rest = holder + 1;
			return (1);
		}
	}
	tmp = ft_strnew(BUFF_SIZE);
	while (read(fd, tmp, BUFF_SIZE))
	{
		len_rest = ft_strlen(rest);
		if ((holder = ft_strchr(tmp, '\n')))
		{
			length = ft_strlenc(tmp, '\n');
			if (!(*line = ft_strnew(length + len_rest)))
				return (-1);
			ft_strncpy(*line, rest, len_rest);
			ft_strncpy(*line + len_rest, tmp, length);
			length = ft_strlen(tmp) - length - 1;
			free(rest);
			if (!(rest = ft_strnew(length)))
				return (-1);
			ft_strncpy(rest, holder + 1, length);
			free(tmp);
			return (1);
		}
		else
		{
			if (!(holder = ft_strnew(len_rest)))
				return (-1);
			ft_memcpy(holder, rest, len_rest);
			free(rest);
			if (!(rest = ft_realloc(holder, len_rest,
				len_rest + BUFF_SIZE + 1)))
				return (-1);
			ft_memcpy(rest + len_rest, tmp, BUFF_SIZE);
		}
	}
	free(tmp);
	return (0);
}

int		main(void)
{
	int fd;
	char *line;

	if ((fd = open("libft.h", O_RDONLY)))
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_putendl(line);
		}
	}
	return (0);
}