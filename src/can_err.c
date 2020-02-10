/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:35:40 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/26 15:07:32 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		erro(char *path)
{
	char		*err;
	int			n;

	err = NULL;
	write(2, "ft_ls: ", 7);
	n = ft_strlen(path) - 1;
	if (path[n] == '/')
		err = ft_strndup(path, n);
	else
		err = ft_strdup(path);
	perror(err);
	err ? free(err) : 0;
	err = NULL;
}

static char	*name_check(char *file)
{
	char		*tmp;
	char		*str;
	int			i;
	int			c;

	c = 0;
	tmp = file;
	i = ft_strlen(file) - 1;
	if (file[i] == '/')
	{
		tmp = ft_strndup(file, i);
		c = 1;
	}
	if ((str = ft_strrchr(tmp, '/')))
		str = ft_strdup(str + 1);
	else
		str = ft_strdup(tmp);
	c ? free(tmp) : 0;
	return (str);
}

static int	job(unsigned short o, char *str)
{
	if ((o & FLAG_A) || str[0] != '.')
	{
		ft_strdel(&str);
		return (1);
	}
	else
	{
		ft_strdel(&str);
		return (0);
	}
}

static int	require(unsigned short o)
{
	if ((o & FLAG_I) || (o & FLAG_G) || (o & FLAG_L) || (o & FLAG_T))
		return (1);
	else
		return (0);
}

int			can_add(unsigned short o, char *file, int n)
{
	char		*str;
	struct stat	s;

	if (lstat(file, &s) == -1 && errno != EACCES)
	{
		erro(file);
		return (0);
	}
	else if (lstat(file, &s) == -1 && require(o))
		return (0);
	else
	{
		str = name_check(file);
		if (n == 0)
		{
			return (job(o, str));
		}
		ft_strdel(&str);
	}
	return (1);
}
