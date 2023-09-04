/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:16:23 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/09 13:27:30 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	jumper;
	char			*src_pointer;

	jumper = 0;
	src_pointer = (char*)s;
	while (jumper < n)
	{
		if (src_pointer[jumper] == c)
			return (src_pointer + jumper);
		jumper++;
	}
	return (NULL);
}
