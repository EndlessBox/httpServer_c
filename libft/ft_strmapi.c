/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:03:55 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/12 15:13:44 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	jumper;
	char			*dest;

	if ((dest = (char*)malloc((sizeof(char) * ft_strlen(s)) + 1)))
	{
		jumper = 0;
		while (s[jumper] != '\0')
		{
			dest[jumper] = f(jumper, s[jumper]);
			jumper++;
		}
		dest[jumper] = '\0';
	}
	return (dest);
}
