/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 09:43:52 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/10 13:33:55 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char			*result;
	unsigned int	jumper;

	jumper = 0;
	if ((result = (char*)malloc(sizeof(char) * n + 1)))
	{
		while (jumper < n)
		{
			result[jumper] = s1[jumper];
			jumper++;
		}
		result[jumper] = '\0';
	}
	else
		return (NULL);
	return (result);
}
