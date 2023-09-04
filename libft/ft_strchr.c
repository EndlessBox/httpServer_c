/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:00:14 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/06 14:00:15 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		jumper;
	char	*s_pointer;

	jumper = 0;
	s_pointer = (char*)s;
	if (c == '\0')
	{
		while (s_pointer[jumper] != '\0')
			jumper++;
		return (s_pointer + jumper);
	}
	while (s_pointer[jumper] != '\0')
	{
		if (s_pointer[jumper] == c)
			return (s_pointer + jumper);
		jumper++;
	}
	return (NULL);
}
