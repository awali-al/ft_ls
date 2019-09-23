/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_pt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:01:59 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/23 22:47:05 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	print_space(int d)
{
	int		i;

	i = 0;
	while (i <= d)
	{
		write(1, " ", 1);
		i++;
	}
}

void	dis_size(struct stat s, t_len l)
{
	int		d;

	if (S_ISCHR(s.st_mode) || S_ISFIFO(s.st_mode))
	{
		d = l.max_maj - int_len(major(s.st_rdev));
		print_space(d);
		ft_putnbr((int)major(s.st_rdev));
		write(1, ",", 1);
		d = l.max_min - int_len(minor(s.st_rdev));
		print_space(d);
		ft_putnbr((int)minor(s.st_rdev));
		write(1, " ", 1);
	}
	else
	{
		d = l.max_siz - int_len((int)s.st_size);
		print_space(d);
		ft_putnbr((int)s.st_size);
		write(1, " ", 1);
	}
}

void	dis_shct(char *path, off_t s)
{
	char	*buff;

	buff = ft_strnew((int)s);
	readlink(path, buff, s);
	write(1, " -> ", 4);
	ft_putstr(buff);
	free(buff);
	buff = NULL;
}
