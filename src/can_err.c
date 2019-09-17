/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:35:40 by aminewalial       #+#    #+#             */
/*   Updated: 2019/08/08 20:20:22 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		erro(char *path)
{
	char		*err;

	write(2, "ft_ls: ", 7);
	err = ft_strjoin(path, ": ");
	perror(err);
	free(err);
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

int			can_add(unsigned short o, char *file, int n)
{
	char		*str;
	struct stat	s;

	if (lstat(file, &s) == -1)
	{
		erro(file);
		return (0);
	}
	else
	{
		str = name_check(file);
		if (n == 0)
		{
			if ((o & FLAG_A) || str[0] != '.')
				return (1);
			else
				return (0);
		}
		free(str);
	}
	return (1);
}
