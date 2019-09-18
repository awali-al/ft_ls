/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:21:30 by awali-al          #+#    #+#             */
/*   Updated: 2019/09/15 16:36:08 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	is_opt(char c)
{
	if (c == 'a' || c == 'd' || c == 'G' || c == 'i' || c == 'l')
		return (1);
	else if (c == 'R' || c == 'r' || c == 't')
		return (1);
	else
		return (0);
}

static void	usage(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ft_ls [-GRadilrt]\n");
	exit(0);
}

static void	opt_fil(char *avi, ust *o)
{
	int		i;

	i = 1;
	while (avi[i])
	{
		if (is_opt(avi[i])) 
		{
			*o = avi[i] == 'a' ? *o | O_A : *o;
			*o = avi[i] == 'd' ? *o | O_D : *o;
			*o = avi[i] == 'G' ? *o | O_G : *o;
			*o = avi[i] == 'i' ? *o | O_I : *o;
			*o = avi[i] == 'l' ? *o | O_L : *o;
			*o = avi[i] == 'R' ? *o | O_REC : *o;
			*o = avi[i] == 'r' ? *o | O_REV : *o;
			*o = avi[i] == 't' ? *o | O_T : *o;
		}
		else
			usage(avi[i]);
		i++;
	}
}

int			options(int ac, char **av, ust *o)
{
	int		i;

	i = 1;
	while (i < ac && ft_strcmp(av[i], "--") && av[i][0] == '-')
	{
		opt_fil(av[i], o);
		i++;
	}
	i = (i < ac && ft_strcmp(av[i], "--") == 0) ? i + 1 : i;
	return (i);
}