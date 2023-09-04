/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:30:23 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/12 15:05:34 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	jumper;
	unsigned char	*s1_pointer;
	unsigned char	*s2_pointer;
	int				verifier;

	s1_pointer = (unsigned char*)s1;
	s2_pointer = (unsigned char*)s2;
	jumper = 0;
	verifier = 0;
	while (jumper < n)
	{
		if (s1_pointer[jumper] == s2_pointer[jumper])
			verifier = 1;
		else
		{
			verifier = 0;
			break ;
		}
		jumper++;
	}
	if (verifier == 1)
		jumper--;
	return (s1_pointer[jumper] - s2_pointer[jumper]);
}
