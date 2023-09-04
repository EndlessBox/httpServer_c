/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 10:09:31 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/09 13:39:15 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	jumper;
	unsigned int	hopper;

	jumper = ft_strlen(s1);
	hopper = 0;
	if (n <= ft_strlen(s2))
	{
		while (hopper < n)
			s1[jumper++] = s2[hopper++];
	}
	else
	{
		while (s2[hopper] != '\0')
			s1[jumper++] = s2[hopper++];
	}
	s1[jumper] = '\0';
	return (s1);
}
