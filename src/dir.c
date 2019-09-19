/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:40:49 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/17 14:58:35 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			is_dir(char *path, t_func fun)
{
	struct stat	s;
	struct stat	ls;
	int			n;

	stat(path, &s);
	lstat(path, &ls);
	n = ft_strlen(path) - 1;
	if (S_ISDIR(ls.st_mode))
		return (1);
	else if (path[n] == '/')
		return (1);
	else if (S_ISLNK(ls.st_mode) && S_ISDIR(s.st_mode) && fun.df == reg_dis)
		return (1);
	else
		return (0);
}

static void	dis_tota(int t)
{
	write(1, "total ", 6);
	ft_putnbr(t);
	write(1, "\n", 1);
}

void		lis_fil(char *file, t_lof **head, t_func fun, t_len *l)
{
	t_lof		*niw;
	t_lof		*tmp;
	t_lof		*prv;

	prv = NULL;
	niw = struc_fill(file, l);
	if (!(*head))
		*head = niw;
	else
	{
		tmp = *head;
		while (tmp && fun.sf(tmp, niw) < 0)
		{
			prv = tmp;
			tmp = tmp->next;
		}
		niw->next = tmp;
		prv ? prv->next = niw : 0;
		tmp == *head ? *head = niw : 0;
	}
}

void		lis_dis(t_lof *head, t_func fun, t_len l, unsigned short o)
{
	len_edi(&l);
	(o & FLAG_L) ? dis_tota(l.blk_cnt) : 0;
	fun.df(head, l, fun);
	fun.rf != NULL ? fun.rf(head, fun, o) : 0;
}
