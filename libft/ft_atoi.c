/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:09:41 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/10 08:51:29 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	jumper;
	int	result;
	int	sign;

	jumper = 0;
	result = 0;
	sign = 1;
	while (ft_iswhitespace(str[jumper]) == 1)
		jumper++;
	if (str[jumper] == '-')
	{
		sign = -1;
		jumper++;
	}
	else if (str[jumper] == '+')
	{
		sign = 1;
		jumper++;
	}
	while (str[jumper] >= '0' && str[jumper] <= '9')
	{
		result = result * 10 + (str[jumper] - 48);
		jumper++;
	}
	return (result * sign);
}
