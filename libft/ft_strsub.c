/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:36:49 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/07 15:36:51 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *dest;

	if ((dest = (char*)malloc(sizeof(char) * (len + 1))))
	{
		dest[len] = '\0';
		ft_memmove(dest, s + start, len);
		return (dest);
	}
	else
		return (NULL);
}
