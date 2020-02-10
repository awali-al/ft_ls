/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_fold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:08:44 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/26 15:17:32 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		show_dir(char *path, struct s_func fun, unsigned short o)
{
	DIR				*dp;
	struct dirent	*sd;
	t_lof			*head;
	t_len			l;
	char			*file;

	head = NULL;
	l = len_ini();
	if (!(dp = opendir(path)))
		erro(path);
	else
	{
		while ((sd = readdir(dp)))
		{
			file = ft_strjoin(path, sd->d_name);
			if (can_add(o, file, 0))
				lis_fil(file, &head, fun, &l);
			ft_strdel(&file);
		}
		closedir(dp);
		head ? lis_dis(head, fun, l, o) : 0;
		head ? free_lst(head) : 0;
	}
}

static void	long_disp(char *path, struct s_func fun)
{
	struct stat		s;
	t_len			l;

	stat(path, &s);
	l.max_siz = int_len((int)s.st_size);
	fun.in ? fun.in(s.st_ino, int_len((int)s.st_ino)) : 0;
	dis_type(s.st_mode);
	dis_perm(s.st_mode);
	dis_link(s.st_nlink, int_len((int)s.st_nlink));
	dis_user(s.st_uid, ft_strlen(getpwuid(s.st_uid)->pw_name));
	dis_grup(s.st_gid, ft_strlen(getgrgid(s.st_gid)->gr_name));
	dis_size(s, l);
	dis_date(s.st_mtime);
	fun.cf(".", s.st_mode, 0);
}

static void	name_dir(char *path, struct s_func fun, unsigned short o)
{
	char			*str;
	char			*name;
	struct stat		s;

	if (o & FLAG_L)
		long_disp(path, fun);
	else
	{
		stat(path, &s);
		str = ft_strndup(path, ft_strlen(path) - 1);
		name = ft_strrchr(str, '/');
		if (name)
			name++;
		else
			name = str;
		fun.cf(name, s.st_mode, 0);
		free(str);
		str = NULL;
	}
	write(1, "\n", 1);
}

t_ffun		fol_func(unsigned short o)
{
	if ((o & FLAG_D))
		return (name_dir);
	else
		return (show_dir);
}
