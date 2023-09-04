/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <ybouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:59:26 by ybouladh          #+#    #+#             */
/*   Updated: 2020/10/22 11:46:12 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*new_string;

	if ((new_string = (char*)malloc(size + 1)))
	{
		ft_memset(new_string, '\0', size + 1);
		return (new_string);
	}
	else
		return (NULL);
}
