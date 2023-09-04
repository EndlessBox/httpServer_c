/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 08:46:33 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/09 13:25:03 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			jumper;
	unsigned char	*t;

	jumper = 0;
	t = s;
	while (jumper < n)
	{
		t[jumper] = '\0';
		jumper++;
	}
}
