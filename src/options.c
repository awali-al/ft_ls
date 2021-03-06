/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:21:30 by awali-al          #+#    #+#             */
/*   Updated: 2019/09/24 22:27:17 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	is_opt(char c)
{
	if (c == 'a' || c == 'd' || c == 'G' || c == 'i' || c == 'l')
		return (1);
	else if (c == 'R' || c == 'r' || c == 't' || c == 'f' || c == 'U')
		return (1);
	else
		return (0);
}

static void	usage(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ft_ls [-GRUadfilrt]\n");
	exit(0);
}

static int	opt_fil(char *avi, unsigned short *o)
{
	int		i;

	i = 1;
	while (avi[i])
	{
		if (is_opt(avi[i]))
		{
			*o = avi[i] == 'a' ? *o | FLAG_A : *o;
			*o = avi[i] == 'd' ? *o | FLAG_D : *o;
			*o = avi[i] == 'G' ? *o | FLAG_G : *o;
			*o = avi[i] == 'i' ? *o | FLAG_I : *o;
			*o = avi[i] == 'l' ? *o | FLAG_L : *o;
			*o = avi[i] == 'R' ? *o | FLAG_REC : *o;
			*o = avi[i] == 'r' ? *o | FLAG_REV : *o;
			*o = avi[i] == 't' ? *o | FLAG_T : *o;
			*o = avi[i] == 'U' ? *o | FLAG_U : *o;
			*o = avi[i] == 'f' ? (*o | FLAG_U) | FLAG_A : *o;
		}
		else
			usage(avi[i]);
		i++;
	}
	i = i == 1 ? 0 : 1;
	return (i);
}

int			options(int ac, char **av, unsigned short *o)
{
	int		i;

	i = 1;
	while (i < ac && ft_strcmp(av[i], "--") && av[i][0] == '-')
	{
		if (!opt_fil(av[i], o))
		{
			ft_putstr_fd("ft_ls: -: No such file or directory\n", 2);
			exit(0);
		}
		i++;
	}
	i = (i < ac && ft_strcmp(av[i], "--") == 0) ? i + 1 : i;
	return (i);
}
