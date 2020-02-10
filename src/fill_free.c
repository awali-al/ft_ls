/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:20:31 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/25 21:48:44 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_lof	*struc_fill(char *file, t_len *l)
{
	t_lof	*ret;

	ret = (t_lof*)malloc(sizeof(t_lof));
	ret->p = ft_strdup(file);
	if (lstat(file, &(ret->s)) == -1)
	{
		ft_bzero(&ret->s, sizeof(struct stat));
	}
	ret->next = NULL;
	len_fil(ret, l);
	return (ret);
}

void	free_lst(t_lof *head)
{
	t_lof *tmp;

	while (head)
	{
		ft_strdel(&head->p);
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
