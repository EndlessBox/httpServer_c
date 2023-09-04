/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:25:30 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/04 20:25:34 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		jumper;

	jumper = 0;
	if ((str = (char*)(malloc(sizeof(*str) * (ft_strlen(s1) + 1)))))
	{
		while (s1[jumper] != '\0')
		{
			str[jumper] = s1[jumper];
			jumper++;
		}
		str[jumper] = '\0';
		return (str);
	}
	else
		return (NULL);
}
