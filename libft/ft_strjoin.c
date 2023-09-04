/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:05:40 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/11 03:48:39 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1l;
	int		s2l;

	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	if ((result = (char*)malloc(sizeof(char) * (s1l + s2l + 1))))
	{
		ft_strcpy(result, s1);
		ft_strcat(result, s2);
		return (result);
	}
	else
		return (NULL);
}
