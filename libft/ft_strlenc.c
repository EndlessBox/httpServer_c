/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <ybouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 09:47:21 by ybouladh          #+#    #+#             */
/*   Updated: 2020/10/23 12:41:58 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlenc(char *str, char c)
{
	int		jumper;

	jumper = 0;
	while (str[jumper] != c && str[jumper])
		jumper++;
	if (str[jumper] == '\0')
		return (-1);
	return (jumper);
}
