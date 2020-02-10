/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_colo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:08:28 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/25 00:41:17 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	k_pop(char *path, mode_t m, int n)
{
	char	*name;
	char	*col;

	if (n)
		name = path;
	else
	{
		name = ft_strrchr(path, '/');
		name = name ? name + 1 : path;
	}
	if (S_ISDIR(m))
		col = ft_strdup(COL_CYAN);
	else if (S_ISLNK(m))
		col = ft_strdup(COL_MAGENTA);
	else if (S_ISREG(m) && ((m & S_IXUSR) || (m & S_IXGRP) || (m & S_IXOTH)))
		col = ft_strdup(COL_RED);
	else
		col = ft_strdup(COL_RESET);
	ft_putstr(col);
	ft_putstr(name);
	ft_putstr(COL_RESET);
	free(col);
	col = NULL;
}

static void	metal(char *path, mode_t mode, int n)
{
	char	*name;

	(void)mode;
	if (n)
		name = path;
	else
	{
		name = ft_strrchr(path, '/');
		name = name ? name + 1 : path;
	}
	ft_putstr(name);
}

t_cfun		col_func(unsigned short o)
{
	if ((o & FLAG_G))
		return (k_pop);
	else
		return (metal);
}
