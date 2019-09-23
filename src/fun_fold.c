/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_fold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <aakfas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:08:44 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/23 14:36:31 by aakfas           ###   ########.fr       */
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

static void	name_dir(char *path, struct s_func fun, unsigned short o)
{
	char		*str;
	char		*name;
	struct stat	s;
	int			i;

	i = (int)o;
	stat(path, &s);
	str = ft_strndup(path, ft_strlen(path) - 1);
	name = ft_strrchr(str, '/');
	if (name)
		name++;
	else
		name = str;
	fun.cf(name, s.st_mode);
	free(str);
	str = NULL;
	write(1, "\n", 1);
}

t_ffun		fol_func(unsigned short o)
{
	if ((o & FLAG_D))
		return (name_dir);
	else
		return (show_dir);
}
