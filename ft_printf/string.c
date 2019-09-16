/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:05:15 by aakfas            #+#    #+#             */
/*   Updated: 2019/09/16 15:19:20 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		finish_it_s(int *field_prec, char *c, char *result)
{
	int	jumper;
	int	counter;

	jumper = -1;
	counter = 0;
	while (field_prec[2] == 2 && --field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(32);
	ft_putstr(result);
	counter += ft_strlen(result);
	while (field_prec[2] == 1 && --field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(' ');
	return (counter);
}

int		dont_finish_it_s(char *c, int *field_prec, char *result)
{
	field_prec[0] -= ft_strlen(result);
	return (finish_it_s(field_prec, c, result));
}

char	*precise_it(int precision, char *result)
{
	char	*final;
	int		jumper;

	final = ft_strnew(precision);
	jumper = -1;
	while (++jumper < precision)
		final[jumper] = result[jumper];
	return (final);
}

int		manage_string(va_list ap, t_plist **argument)
{
	char		*c;
	int			*field_prec;
	char		*result;

	field_prec = (int*)malloc(sizeof(int) * 3);
	field_prec[2] = 2;
	result = va_arg(ap, char*);
	if ((*argument)->flags[0] == 1)
		field_prec[2] = 1;
	if (result == NULL)
		result = "(null)";
	field_prec[0] = (*argument)->field_width;
	field_prec[1] = (*argument)->precision[1];
	if ((*argument)->precision[0] == 1 &&
			(*argument)->precision[1] < ft_strlen(result))
		result = precise_it((*argument)->precision[1], result);
	if ((*argument)->precision[1] == 0 && (*argument)->precision[0] == 1)
		result = "";
	return (dont_finish_it_s(c, field_prec, result));
}
