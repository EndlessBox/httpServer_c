/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 03:15:37 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/12 15:13:24 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		jumper;

	jumper = 0;
	if ((dest = (char*)malloc((sizeof(char) * ft_strlen(s)) + 1)))
	{
		while (s[jumper])
		{
			dest[jumper] = f(s[jumper]);
			jumper++;
		}
		dest[jumper] = '\0';
	}
	return (dest);
}
