/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:24:01 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/09 13:32:09 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	jumper;
	unsigned char	*glorious;

	jumper = 0;
	glorious = b;
	while (jumper < len)
	{
		glorious[jumper] = c;
		jumper++;
	}
	return (b);
}
