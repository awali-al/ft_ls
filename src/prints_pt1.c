/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_pt1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:25:59 by aminewalial       #+#    #+#             */
/*   Updated: 2019/08/08 19:55:06 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	dis_type(mode_t mode)
{
	S_ISREG(mode) ? write(1, "-", 1) : 0;
	S_ISBLK(mode) ? write(1, "b", 1) : 0;
	S_ISCHR(mode) ? write(1, "c", 1) : 0;
	S_ISDIR(mode) ? write(1, "d", 1) : 0;
	S_ISLNK(mode) ? write(1, "l", 1) : 0;
	S_ISFIFO(mode) ? write(1, "p", 1) : 0;
	S_ISSOCK(mode) ? write(1, "s", 1) : 0;
}

void	dis_perm(mode_t mode)
{
	(mode & S_IRUSR) == S_IRUSR ? write(1, "r", 1) : write(1, "-", 1);
	(mode & S_IWUSR) == S_IWUSR ? write(1, "w", 1) : write(1, "-", 1);
	if ((mode & S_ISUID) != S_ISUID)
		(mode & S_IXUSR) == S_IXUSR ? write(1, "x", 1) : write(1, "-", 1);
	else
		(mode & S_IXUSR) == S_IXUSR ? write(1, "s", 1) : write(1, "S", 1);
	(mode & S_IRGRP) == S_IRGRP ? write(1, "r", 1) : write(1, "-", 1);
	(mode & S_IWGRP) == S_IWGRP ? write(1, "w", 1) : write(1, "-", 1);
	if ((mode & S_ISGID) != S_ISGID)
		(mode & S_IXGRP) == S_IXGRP ? write(1, "x", 1) : write(1, "-", 1);
	else
		(mode & S_IXGRP) == S_IXGRP ? write(1, "s", 1) : write(1, "S", 1);
	(mode & S_IROTH) == S_IROTH ? write(1, "r", 1) : write(1, "-", 1);
	(mode & S_IWOTH) == S_IWOTH ? write(1, "w", 1) : write(1, "-", 1);
	if ((mode & S_ISVTX) != S_ISVTX)
		(mode & S_IXOTH) == S_IXOTH ? write(1, "x", 1) : write(1, "-", 1);
	else
		(mode & S_IXOTH) == S_IXOTH ? write(1, "t", 1) : write(1, "T", 1);
	write(1, " ", 1);
}

void	dis_link(nlink_t nhl, int max)
{
	int		i;
	int		d;

	d = max - int_len((int)nhl);
	i = 0;
	while (i < d)
	{
		write(1, " ", 1);
		i++;
	}
	ft_putnbr((int)nhl);
	write(1, " ", 1);
}

void	dis_user(uid_t uid, int max)
{
	int		i;
	int		d;

	d = max - int_len((int)uid) + 2;
	i = 0;
	ft_putstr(getpwuid(uid)->pw_name);
	while (i < d)
	{
		write(1, " ", 1);
		i++;
	}
}

void	dis_grup(gid_t gid, int max)
{
	int		i;
	int		d;

	d = max - int_len((int)gid) + 2;
	i = 0;
	ft_putstr(getgrgid(gid)->gr_name);
	while (i < d)
	{
		write(1, " ", 1);
		i++;
	}
}
