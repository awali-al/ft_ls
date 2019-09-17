/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:54:20 by aminewalial       #+#    #+#             */
/*   Updated: 2019/08/08 20:20:00 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	unsigned short	o;
	int				i;
	t_func			fun;

	i = opt_fil(av, &o);
	fun_ini(&fun, o);
	if (i == ac)
		fun.ff(ft_strdup("./"), fun, o);
	else
		args(av + i, ac - i, o, fun);
	return (0);
}
