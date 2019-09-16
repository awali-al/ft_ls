/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:11:35 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/15 16:00:27 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int			finish_it(int *field_prec, char *c, char *temp)
{
	int	jumper;
	int	counter;

	jumper = -1;
	counter = 0;
	while (field_prec[2] == 2 && c[1] == ' ' &&
			--field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(c[1]);
	if (c[0] != '\0' && ++counter > 0)
		ft_putchar(c[0]);
	while (field_prec[2] == 2 && c[1] == '0' &&
			--field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(c[1]);
	while (--field_prec[1] >= 0 && ++counter > 0)
		ft_putchar('0');
	if (c[2] == 1 && c[3] == 'o' && ++counter > 0)
		ft_putchar('0');
	else if (c[2] == 1 && c[3] == 'u' && ++counter > 0)
		ft_putchar(32);
	if ((counter += ft_strlen(temp)) > 0 && field_prec[1] == 0 && ++counter > 0)
		ft_putchar(' ');
	ft_putstr(temp);
	while (field_prec[2] == 1 && --field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(' ');
	return (counter);
}

intmax_t	len_mod(va_list ap, t_plist **argument)
{
	uintmax_t	result;

	if ((*argument)->length_modifier == 1)
		result = va_arg(ap, long);
	else if ((*argument)->length_modifier == 2)
		result = (short)va_arg(ap, int);
	else if ((*argument)->length_modifier == 4)
		result = va_arg(ap, long long);
	else if ((*argument)->length_modifier == 5)
		result = (signed char)va_arg(ap, int);
	else if ((*argument)->length_modifier == 6)
		result = va_arg(ap, intmax_t);
	else if ((*argument)->length_modifier == 7)
		result = va_arg(ap, ssize_t);
	else
		result = va_arg(ap, int);
	return (result);
}

int			dont_finish_it(int number, char *c,
			int *field_prec, intmax_t result)
{
	char	*temp;

	if (number == 1)
		temp = ft_itoa_intmax(result);
	else
		temp = dec_octal(result);
	if (result < 0)
	{
		c[0] = '-';
		temp++;
	}
	if (result == 0 && field_prec[1] == 0 && field_prec[3] == 1)
	{
		c[1] = ' ';
		temp = "";
	}
	if (field_prec[1] != 0)
		c[1] = ' ';
	field_prec[0] -= ft_strlen(temp);
	field_prec[1] -= ft_strlen(temp);
	if (c[0] != '\0')
		field_prec[0]--;
	if (field_prec[1] >= 0)
		field_prec[0] -= field_prec[1];
	return (finish_it(field_prec, c, temp));
}

int			manage_integers(va_list ap, t_plist **argument)
{
	char		*c;
	int			*field_prec;

	if ((*argument)->conversion == 'D')
		(*argument)->length_modifier = 1;
	if ((*argument)->conversion == 'D')
		(*argument)->conversion = 'd';
	field_prec = (int*)malloc(sizeof(int) * 4);
	field_prec[2] = 2;
	field_prec[3] = (*argument)->precision[0];
	c = ft_strnew(4);
	c[0] = '\0';
	c[1] = 32;
	if ((*argument)->flags[0] == 1)
		field_prec[2] = 1;
	if ((*argument)->flags[3] == 1 && (*argument)->precision[0] != 1)
		c[1] = '0';
	if ((*argument)->flags[2] == 1)
		c[0] = 32;
	if ((*argument)->flags[1] == 1)
		c[0] = '+';
	c[3] = (*argument)->conversion;
	field_prec[0] = (*argument)->field_width;
	field_prec[1] = (*argument)->precision[1];
	return (dont_finish_it(1, c, field_prec, len_mod(ap, argument)));
}
