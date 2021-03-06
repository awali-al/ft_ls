/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:55:23 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/25 15:42:07 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	file_disp(t_lof *node, t_func fun, t_len l, unsigned short o)
{
	fun.in ? fun.in(node->s.st_ino, l.max_ino) : 0;
	if ((o & FLAG_L))
	{
		dis_type(node->s.st_mode);
		dis_perm(node->s.st_mode);
		dis_link(node->s.st_nlink, l.max_nhl);
		dis_user(node->s.st_uid, l.max_usr);
		dis_grup(node->s.st_gid, l.max_grp);
		dis_size(node->s, l);
		dis_date(node->s.st_mtime);
		fun.cf(node->p, node->s.st_mode, 1);
		S_ISLNK(node->s.st_mode) ? dis_shct(node->p, node->s.st_size) : 0;
		write(1, "\n", 1);
	}
	else
	{
		fun.cf(node->p, node->s.st_mode, 1);
		write(1, "\n", 1);
	}
}

void	fol_dis(t_lof *h, t_lof *tmp, t_func fun, unsigned short o)
{
	char	*str;
	char	*buf;
	int		n;

	if (h->next || o & FLAG_ERR)
	{
		ft_putstr(tmp->p);
		write(1, ":\n", 2);
	}
	buf = NULL;
	if (S_ISLNK(tmp->s.st_mode))
	{
		readlink(tmp->p, buf, tmp->s.st_size);
	}
	!buf ? buf = tmp->p : 0;
	n = ft_strlen(buf) - 1;
	str = buf[n] == '/' ? ft_strdup(buf) : ft_strjoin(buf, "/");
	show_dir(str, fun, o);
	ft_strdel(&str);
}
