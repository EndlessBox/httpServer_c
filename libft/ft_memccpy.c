/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 09:57:42 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/12 15:10:31 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	jumper;
	unsigned char	*pointer_dst;
	unsigned char	*pointer_src;
	unsigned char	c_clone;

	jumper = 0;
	pointer_src = (unsigned char*)src;
	pointer_dst = (unsigned char*)dst;
	c_clone = (unsigned char)c;
	while (jumper < n)
	{
		if (pointer_src[jumper] == c_clone)
		{
			pointer_dst[jumper] = c_clone;
			return ((unsigned char*)(dst + jumper + 1));
		}
		pointer_dst[jumper] = pointer_src[jumper];
		jumper++;
	}
	return (NULL);
}
