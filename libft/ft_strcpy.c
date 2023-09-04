/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:47:00 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/04 20:47:03 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int jumper;

	jumper = 0;
	while (src[jumper] != '\0')
	{
		dst[jumper] = src[jumper];
		jumper++;
	}
	dst[jumper] = '\0';
	return (dst);
}
