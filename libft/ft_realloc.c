/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <ybouladh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:43:15 by ybouladh          #+#    #+#             */
/*   Updated: 2020/10/23 10:32:28 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *old_ptr, size_t old_size, size_t size)
{
	void	*new_ptr;

	if (size == 0 && old_ptr != NULL)
		free(old_ptr);
	else if (old_ptr == NULL && (old_ptr = malloc(size)))
	{
		ft_memset(old_ptr, 0, size);
		return (old_ptr);
	}
	else if (old_ptr != NULL)
	{
		if (!(new_ptr = malloc(size)))
			return (NULL);
		ft_memset(new_ptr, 0, size);
		if (size >= old_size)
			ft_strncpy(new_ptr, old_ptr, old_size);
		else
			ft_strncpy(new_ptr, old_ptr, size);
		free(old_ptr);
		return (new_ptr);
	}
	return (NULL);
}
