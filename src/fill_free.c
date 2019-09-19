/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:20:31 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/19 16:46:05 by awali-al         ###   ########.fr       */
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
	t_lof *next;

	while (head)
	{
		next = head->next;
		if (head->p)
			free(head->p);
		head->p = NULL;
		free(head);
		head = next;
	}
}
