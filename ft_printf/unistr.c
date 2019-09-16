/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unistr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 00:30:03 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/07 00:30:05 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		prints_it_darling(wchar_t *result)
{
	int	jumper;
	int	counter;

	jumper = -1;
	counter = 0;
	while (result[++jumper])
		counter += printc_it_darling(result[jumper]);
	return (counter);
}

int		ft_put_ustr(int *field_prec, char *c, wchar_t *result)
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
	else if (c[2] == '0' && ++counter > 0)
		ft_putchar('0');
	while (field_prec[2] == 2 && c[1] == '0' &&
			--field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(c[1]);
	while (--field_prec[1] >= 0 && ++counter > 0)
		ft_putchar('0');
	if (field_prec[1] == 0 && ++counter > 0)
		ft_putchar(' ');
	counter += prints_it_darling(result);
	while (field_prec[2] == 1 && --field_prec[0] >= 0 &&
			++counter > 0 && ++counter > 0)
		ft_putchar(' ');
	return (counter);
}

int		count_size_us(wchar_t *result)
{
	int size;
	int jumper;

	size = 0;
	jumper = -1;
	while (result[++jumper])
	{
		if (result[jumper] > 0 && result[jumper] <= 127)
			size++;
		else if (result[jumper] <= 2047)
			size += 2;
		else if (result[jumper] <= 65535)
			size += 3;
		else if (result[jumper] <= 0xFFFFF)
			size += 4;
	}
	return (size);
}

int		dont_finish_it_us(char *c, int *field_prec, wchar_t *result)
{
	int		temp_len;
	int		size;
	int		jumper;

	size = count_size_us(result);
	if (result[0] == '\0')
		return (0);
	if (result[0] == 0 && field_prec[1] == 0)
	{
		c[1] = ' ';
		result = 0x0000;
	}
	if (field_prec[1] != 0)
		c[1] = ' ';
	field_prec[0] -= size;
	field_prec[1] -= size;
	if (field_prec[1] >= 0)
		field_prec[0] -= field_prec[1];
	return (ft_put_ustr(field_prec, c, result));
}
