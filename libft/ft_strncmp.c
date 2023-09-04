/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:27:05 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/12 15:29:05 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	jumper;
	unsigned char	*s1_clone;
	unsigned char	*s2_clone;

	jumper = 0;
	s1_clone = (unsigned char*)s1;
	s2_clone = (unsigned char*)s2;
	while (s1_clone[jumper] == s2_clone[jumper]
			&& s1_clone[jumper] != '\0' && jumper < n)
	{
		if (jumper + 1 == n)
			break ;
		jumper++;
	}
	return (s1_clone[jumper] - s2_clone[jumper]);
}
