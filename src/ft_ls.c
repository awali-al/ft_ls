/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:54:20 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/18 16:43:48 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	unsigned short	o;
	int				i;
	t_func			fun;

	i = options(ac, av, &o);
	fun_ini(&fun, o);
	if (i == ac)
		fun.ff("./", fun, o);
	else
		args(av + i, ac - i, o, fun);
	return (0);
}
