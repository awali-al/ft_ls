/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:49:10 by awali-al          #+#    #+#             */
/*   Updated: 2019/09/15 17:03:06 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	ust		o;
	int		i;

	o = 0;
	i = options(ac, av, &o);
	if (i == ac)
	{
		show_dir(".", o);
	}
	else
	{
		arg_treatent(av, ac, o);
	}
	return (0);
}
