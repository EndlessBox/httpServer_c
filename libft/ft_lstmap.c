/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 21:29:30 by ybouladh          #+#    #+#             */
/*   Updated: 2018/10/12 15:54:21 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*temporary;

	new = f(lst);
	if (!(temporary = new))
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
		new->next = f(lst);
		new = new->next;
	}
	new->next = f(lst);
	return (temporary);
}
