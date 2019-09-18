/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <aakfas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:20:31 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/17 18:05:02 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_lof	*struc_fill(char *file, t_len *l)
{
	t_lof	*ret;

	ret = (t_lof*)malloc(sizeof(t_lof));
	ret->p = file;
	lstat(file, &(ret->s));
	ret->next = NULL;
	len_fil(ret, l);
	return (ret);
}

void	free_lst(t_lof *head)
{
	/*if (head == NULL)
		return ;
	if (head->next)
		free_lst(head->next);
	free(head->p);
	head->p = NULL;
	free(head);
	head = NULL;*/
	t_lof *next;

	while (head)
	{
		next = head->next;
		free(head->p);
		free(head);
		head = next;
	}
}
