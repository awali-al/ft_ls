/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:27:44 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/14 02:13:12 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void		finish_it_c(int *field_prec, char *c, int result)
{
	int	jumper;

	jumper = -1;
	while (field_prec[2] == 2 && c[1] == ' ' && --field_prec[0] >= 0)
		ft_putchar(c[1]);
	while (field_prec[2] == 2 && c[1] == '0' && --field_prec[0] >= 0)
		ft_putchar(c[1]);
	ft_putchar(result);
	while (field_prec[2] == 1 && --field_prec[0] >= 0)
		ft_putchar(' ');
}

void		dont_finish_it_c(char *c, int *field_prec, int result)
{
	int	temp_len;

	if (result == 0 && field_prec[1] == 0)
	{
		c[1] = ' ';
		result = '\0';
	}
	if (field_prec[1] != 0)
		c[1] = ' ';
	field_prec[0] -= 1;
	finish_it_c(field_prec, c, result);
}

int			manage_char(va_list ap, t_plist **argument)
{
	char		*c;
	int			*field_prec;
	int			result;

	field_prec = (int*)malloc(sizeof(int) * 3);
	result = va_arg(ap, int);
	field_prec[2] = 2;
	c = ft_strnew(2);
	c[0] = '\0';
	c[1] = 32;
	if ((*argument)->flags[0] == 1)
		field_prec[2] = 1;
	if ((*argument)->flags[3] == 1)
		c[1] = '0';
	field_prec[0] = (*argument)->field_width;
	field_prec[1] = (*argument)->precision[1];
	if ((*argument)->flags[4] == 1)
		c[2] = 1;
	if ((*argument)->conversion == 'c' || (*argument)->conversion == '%')
		dont_finish_it_c(c, field_prec, result);
	if ((*argument)->field_width > 1)
		return ((*argument)->field_width);
	else
		return (1);
}
