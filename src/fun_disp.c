/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_disp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:22:10 by aminewalial       #+#    #+#             */
/*   Updated: 2019/08/09 13:54:29 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	lon_dis(t_lof *head, t_len l, struct s_func fun)
{
	t_lof	*tmp;

	tmp = head;
	while (tmp)
	{
		fun.in ? fun.in(tmp->s.st_ino, l) : 0;
		dis_type(tmp->s.st_mode);
		dis_perm(tmp->s.st_mode);
		dis_link(tmp->s.st_nlink, l.max_nhl);
		dis_user(tmp->s.st_uid, l.max_usr);
		dis_grup(tmp->s.st_gid, l.max_grp);
		dis_size(tmp->s.st_size, l.max_siz);
		dis_date(tmp->s.st_mtime);
		fun.cf(tmp->p, tmp->s.st_mode);
		S_ISLNK(tmp->s.st_mode) ? dis_shct(tmp->p, tmp->s.st_size) : 0;
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}

void		reg_dis(t_lof *head, t_len l, struct s_func fun)
{
	t_lof	*tmp;
	int		i;

	if (fun.df == NULL)
		i = l.blk_cnt;
	tmp = head;
	while (tmp != NULL)
	{
		fun.in ? fun.in(tmp->s.st_ino, l) : 0;
		fun.cf(tmp->p, tmp->s.st_mode);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}

t_dfun		dis_func(unsigned short o)
{
	if ((o & FLAG_L))
		return (lon_dis);
	else
		return (reg_dis);
}
