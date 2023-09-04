/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 14:14:38 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/11 15:18:06 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst_saver;
	size_t	size_src_saver;
	size_t	jumper;
	size_t	hopper;

	size_dst_saver = ft_strlen(dst);
	size_src_saver = ft_strlen(src);
	hopper = size_dst_saver;
	jumper = 0;
	if (size_dst_saver >= size)
		return (size + size_src_saver);
	while (src[jumper] && hopper < size - 1)
		dst[hopper++] = src[jumper++];
	dst[hopper] = '\0';
	return (size_dst_saver + size_src_saver);
}
