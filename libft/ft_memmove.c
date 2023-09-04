/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:04:53 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/12 15:10:52 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*holder;
	unsigned int	jumper;
	unsigned char	*dst_pointer;

	holder = ft_strndup(src, len);
	jumper = 0;
	dst_pointer = (unsigned char*)dst;
	if (len == 0)
		return ((unsigned char*)dst);
	while (jumper < len)
	{
		dst_pointer[jumper] = holder[jumper];
		jumper++;
	}
	return ((unsigned char*)dst);
}
