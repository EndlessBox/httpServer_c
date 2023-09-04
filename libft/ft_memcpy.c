/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 09:19:51 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/10 10:34:09 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				jumper;
	unsigned char		*dst_pointer;
	const unsigned char	*src_pointer;

	jumper = 0;
	dst_pointer = dst;
	src_pointer = src;
	while (jumper < n)
	{
		dst_pointer[jumper] = src_pointer[jumper];
		jumper++;
	}
	return (dst);
}
