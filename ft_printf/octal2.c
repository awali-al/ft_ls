/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:49:41 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/06 20:49:43 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void		put_it(int **field_prec, char *temp, char **c, int *counter)
{
	while ((*field_prec)[2] == 2 && (*c)[1] == '0' &&
		--(*field_prec)[0] >= 0 && ++(*counter) > 0)
		ft_putchar((*c)[1]);
	while (--(*field_prec)[1] >= 0 && ++(*counter) > 0)
		ft_putchar('0');
	if (((*counter) += ft_strlen(temp)) > 0 && (*field_prec)[1] == 0
		&& ++(*counter) > 0)
		ft_putchar(' ');
	ft_putstr(temp);
	while ((*field_prec)[2] == 1 && --(*field_prec)[0] >= 0 && ++(*counter) > 0)
		ft_putchar(' ');
}

void		search_conversion(char **temp, int number, uintmax_t *result)
{
	if (number == 0)
		*temp = ft_itoa_uintmax(*result);
	else if (number == 1)
		*temp = dec_octal(*result);
	else if (number == 2)
		*temp = dec_hex(*result);
	else if (number == 3)
		*temp = ft_toupper_str(dec_hex(*result));
	else if (number == 4)
		*temp = dec_bin(*result);
}

int			finish_it_xx(int *field_prec, char zero_checker,
					char *c, char *temp)
{
	int	jumper;
	int	counter;

	counter = 0;
	jumper = -1;
	while (field_prec[2] == 2 && c[1] == ' ' &&
		--field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(c[1]);
	if (c[0] != '\0' && ++counter > 0)
		ft_putchar(c[0]);
	if ((zero_checker == 'x' || zero_checker == 'X') && c[2] == 1 &&
		temp[0] != '\0' && ft_strcmp("0", temp) != 0 && (counter += 2) > 0)
	{
		ft_putchar('0');
		ft_putchar(zero_checker);
	}
	else if (zero_checker == '0' && c[2] == 1
			&& ft_strcmp("0", temp) != 0 && ++counter > 0)
	{
		ft_putchar('0');
		field_prec[1]--;
	}
	put_it(&field_prec, temp, &c, &counter);
	return (counter);
}

uintmax_t	len_mod_o(va_list ap, t_plist **argument)
{
	uintmax_t result;

	if ((*argument)->length_modifier == 1)
		result = va_arg(ap, unsigned long);
	else if ((*argument)->length_modifier == 2)
		result = (unsigned short)va_arg(ap, unsigned int);
	else if ((*argument)->length_modifier == 4)
		result = va_arg(ap, unsigned long long);
	else if ((*argument)->length_modifier == 5)
		result = (unsigned char)va_arg(ap, unsigned int);
	else if ((*argument)->length_modifier == 6)
		result = va_arg(ap, uintmax_t);
	else if ((*argument)->length_modifier == 7)
		result = va_arg(ap, size_t);
	else
		result = va_arg(ap, unsigned int);
	return (result);
}
