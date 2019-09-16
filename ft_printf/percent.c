/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 00:42:34 by aakfas            #+#    #+#             */
/*   Updated: 2019/09/16 15:20:50 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		finish_it_percent(int *field_prec, char *c, int result)
{
	int	jumper;
	int	counter;

	jumper = -1;
	counter = 0;
	while (field_prec[2] == 2 && --field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(c[1]);
	ft_putchar(result);
	counter++;
	while (field_prec[2] == 1 && --field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(' ');
	return (counter);
}

int		manage_percent(va_list ap, t_plist **argument)
{
	char		*c;
	int			*field_prec;
	int			result;

	field_prec = (int*)malloc(sizeof(int) * 3);
	result = '%';
	field_prec[2] = 2;
	c = ft_strnew(3);
	c[0] = '\0';
	c[1] = ' ';
	if ((*argument)->flags[0] == 1)
		field_prec[2] = 1;
	field_prec[0] = (*argument)->field_width - 1;
	if ((*argument)->flags[3] == 1)
		c[1] = '0';
	return (finish_it_percent(field_prec, c, result));
}
