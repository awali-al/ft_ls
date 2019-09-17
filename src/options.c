/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:16:49 by aminewalial       #+#    #+#             */
/*   Updated: 2019/08/08 18:00:30 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	usage(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	write(2, &c, 1);
	ft_putstr_fd("\nusage: ./ft_ls [-GRadilrt1] [file ...]\n", 2);
	exit(0);
}

static int	c_opt(char c)
{
	if (c == 'a' || c == 'd' || c == 'G' || c == 'i' || c == 'l')
		return (1);
	else if (c == 'R' || c == 'r' || c == 't' || c == '1')
		return (1);
	else
		return (0);
}

static int	is_opt(char *str, unsigned short *o)
{
	int		n;
	int		i;

	if (str[0] != '-' || ft_strcmp(str, "--") == 0)
		return (0);
	else
	{
		n = ft_strlen(str);
		i = 0;
		while (++i < n)
			if (c_opt(str[i]) == 0)
				usage(str[i]);
			else
			{
				str[i] == 'a' ? *o |= FLAG_A : 0;
				str[i] == 'd' ? *o |= FLAG_D : 0;
				str[i] == 'G' ? *o |= FLAG_G : 0;
				str[i] == 'i' ? *o |= FLAG_I : 0;
				str[i] == 'l' ? *o |= FLAG_L : 0;
				str[i] == 'R' ? *o |= FLAG_REC : 0;
				str[i] == 'r' ? *o |= FLAG_REV : 0;
				str[i] == 't' ? *o |= FLAG_T : 0;
			}
		return (1);
	}
}

int			opt_fil(char **av, unsigned short *o)
{
	int		c;
	int		i;

	i = 0;
	c = 0;
	while (av[++i] && c == 0)
		if (is_opt(av[i], o) == 0)
			c = i;
	c == 0 ? c = i : 0;
	return (c);
}
