/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unichar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 00:27:35 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/07 00:27:40 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		ft_put_uchar(int *field_prec, char *c, wchar_t result)
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
	printc_it_darling(result);
	counter += count_size_uc(result);
	while (field_prec[2] == 1 && --field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(' ');
	return (counter);
}

int		dont_finish_it_uc(char *c, int *field_prec, wchar_t result)
{
	int	size;

	if (count_size_uc(result) == 0)
		return (-1);
	size = count_size_uc(result);
	if (result == 0 && field_prec[1] == 0)
	{
		c[1] = ' ';
		result = '\0';
	}
	if (field_prec[1] != 0)
		c[1] = ' ';
	field_prec[0] -= size;
	field_prec[1] -= size;
	if (field_prec[1] >= 0)
		field_prec[0] -= field_prec[1];
	return (ft_put_uchar(field_prec, c, result));
}

void	upper_conv(t_plist **argument)
{
	if ((*argument)->length_modifier == 1 && (*argument)->conversion == 'c')
		(*argument)->conversion = 'C';
	else if ((((*argument)->conversion == 's' &&
			(*argument)->length_modifier == 1)))
		(*argument)->conversion = 'S';
}

void	flag_manager(t_plist **argument, int **field_prec, char **c)
{
	if ((*argument)->flags[0] == 1)
		(*field_prec)[2] = 1;
	if ((*argument)->flags[3] == 1)
		(*c)[1] = '0';
	(*field_prec)[0] = (*argument)->field_width;
	(*field_prec)[1] = (*argument)->precision[1];
}

/*
** field_prec => 0 fw, 1 precis, 2 side (1 right, 2 left)
*/

int		manage_unichar(va_list ap, t_plist **argument)
{
	char		*c;
	int			*field_prec;
	wchar_t		caractere;
	wchar_t		*string;

	field_prec = (int*)malloc(sizeof(int) * 3);
	caractere = '\0';
	upper_conv(argument);
	if ((*argument)->conversion == 'C')
		caractere = va_arg(ap, wchar_t);
	else
		string = va_arg(ap, wchar_t*);
	if (caractere < 0 || count_size_uc(caractere) == 0)
		return (-1);
	field_prec[2] = 2;
	c = ft_strnew(2);
	c[0] = '\0';
	c[1] = 32;
	flag_manager(argument, &field_prec, &c);
	c[2] = (*argument)->flags[4];
	if ((*argument)->conversion == 'C')
		return (dont_finish_it_uc(c, field_prec, caractere));
	else if ((*argument)->conversion == 'S')
		return (dont_finish_it_us(c, field_prec, string));
	return (0);
}
