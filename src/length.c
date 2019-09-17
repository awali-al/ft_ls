/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 21:16:34 by aminewalial       #+#    #+#             */
/*   Updated: 2019/08/08 17:58:09 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		int_len(int n)
{
	int		c;

	if (n == 0)
		return (2);
	c = 0;
	while (n)
	{
		c++;
		n /= 10;
	}
	return (c + 1);
}

t_len	len_ini(void)
{
	t_len	l;

	l.blk_cnt = 0;
	l.max_grp = 0;
	l.max_ino = 0;
	l.max_nhl = 0;
	l.max_siz = 0;
	l.max_usr = 0;
	return (l);
}

void	len_fil(t_lof *node, t_len *l)
{
	char	*name;
	int		u;
	int		g;

	if ((name = ft_strrchr(node->p, '/')))
		name++;
	else
		name = node->p;
	u = ft_strlen(getpwuid(node->s.st_uid)->pw_name);
	g = ft_strlen(getgrgid(node->s.st_gid)->gr_name);
	if (ft_strcmp(name, ".") && ft_strcmp(name, ".."))
		l->blk_cnt += node->s.st_blocks;
	l->max_ino < (int)node->s.st_ino ? l->max_ino = node->s.st_ino : 0;
	l->max_nhl < node->s.st_nlink ? l->max_nhl = node->s.st_nlink : 0;
	l->max_siz < node->s.st_size ? l->max_siz = node->s.st_size : 0;
	l->max_grp < g ? l->max_grp = g : 0;
	l->max_usr < u ? l->max_usr = u : 0;
}

void	len_edi(t_len *l)
{
	l->max_grp = int_len(l->max_grp);
	l->max_ino = int_len(l->max_ino);
	l->max_nhl = int_len(l->max_nhl);
	l->max_siz = int_len(l->max_siz);
	l->max_usr = int_len(l->max_usr);
}
