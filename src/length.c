/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 21:16:34 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/24 22:06:51 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			int_len(int n)
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

static int	maxi(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_len		len_ini(void)
{
	t_len	l;

	l.blk_cnt = 0;
	l.max_grp = 0;
	l.max_ino = 0;
	l.max_nhl = 0;
	l.max_siz = 0;
	l.max_usr = 0;
	l.max_maj = 0;
	l.max_min = 0;
	return (l);
}

void		len_fil(t_lof *node, t_len *l)
{
	char	*name;
	int		m;

	m = 0;
	if ((name = ft_strrchr(node->p, '/')))
		name++;
	else
		name = node->p;
	if (ft_strcmp(name, ".") && ft_strcmp(name, ".."))
		l->blk_cnt += node->s.st_blocks;
	l->max_ino = maxi(l->max_ino, int_len((int)node->s.st_ino));
	l->max_nhl = maxi(l->max_nhl, int_len((int)node->s.st_nlink));
	l->max_siz = maxi(l->max_siz, int_len((int)node->s.st_size));
	if (S_ISCHR(node->s.st_mode) || S_ISBLK(node->s.st_mode))
	{
		l->max_maj = maxi(l->max_maj, int_len(major(node->s.st_rdev)));
		l->max_min = maxi(l->max_min, int_len(minor(node->s.st_rdev)));
		m = l->max_maj + l->max_min + 1;
	}
	l->max_siz = maxi(l->max_siz, m);
	l->max_grp = maxi(l->max_grp, ft_strlen(getgrgid(node->s.st_gid)->gr_name));
	l->max_usr = maxi(l->max_usr, ft_strlen(getpwuid(node->s.st_uid)->pw_name));
}
