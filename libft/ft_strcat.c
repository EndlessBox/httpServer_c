/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:21:27 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/05 09:21:29 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int jumper;
	int hopper;

	jumper = ft_strlen(s1);
	hopper = 0;
	while (s2[hopper] != '\0')
	{
		s1[jumper++] = s2[hopper++];
	}
	s1[jumper] = '\0';
	return (s1);
}
