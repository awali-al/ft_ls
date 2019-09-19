/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_inod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:45:06 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/19 16:21:27 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ino_print(int ino, t_len l)
{
	int		i;
	int		n;

	i = -1;
	n = l.max_ino - int_len(ino);
	while (++i < n)
		write(1, " ", 1);
	ft_putnbr(ino);
	write(1, " ", 1);
}

t_ifun		ino_func(unsigned short o)
{
	if ((o & FLAG_I))
		return (ino_print);
	else
		return (NULL);
}