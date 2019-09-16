/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:29:19 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 14:29:21 by aakfas           ###   ########.fr       */
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
