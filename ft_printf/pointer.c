/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:04:52 by aakfas            #+#    #+#             */
/*   Updated: 2019/09/16 15:19:11 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		finish_it_p(int *field_prec, char *c, char *temp)
{
	int	jumper;
	int	counter;

	jumper = -1;
	counter = 0;
	while (field_prec[2] == 2 && c[1] == ' ' &&
			--field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(c[1]);
	ft_putstr("0x");
	counter += 2;
	while (field_prec[2] == 2 && c[1] == '0' &&
			--field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(c[1]);
	while (--field_prec[1] >= 0 && ++counter > 0)
		ft_putchar('0');
	if (c[2] == 1 && c[3] == 'o' && ++counter > 0)
		ft_putchar('0');
	else if (c[2] == 1 && c[3] == 'u' && ++counter > 0)
		ft_putchar(32);
	if ((counter += ft_strlen(temp)) > 0 && field_prec[1] == 0 && counter++ > 0)
		ft_putchar(' ');
	ft_putstr(temp);
	while (field_prec[2] == 1 && --field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(' ');
	return (counter);
}

int		dont_finish_it_p(char *c, int *field_prec, intmax_t result)
{
	char	*temp;

	temp = dec_hex(result);
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
	field_prec[0] -= 2;
	return (finish_it_p(field_prec, c, temp));
}

void	manage_flags(t_plist **argument, int **field_prec, char **c)
{
	if ((*argument)->flags[0] == 1)
		(*field_prec)[2] = 1;
	if ((*argument)->flags[3] == 1)
		(*c)[1] = '0';
	if ((*argument)->flags[2] == 1)
		(*c)[0] = 32;
	if ((*argument)->flags[1] == 1)
		(*c)[0] = '+';
}

/*
** field_prece 0 -> fw, 1 -> precisions, 2 -> side (1 right, 2 left), 3 -> #
** c -> 0 : sign, 1 : padding, conversion
*/

int		manage_pointers(va_list ap, t_plist **argument)
{
	char		*c;
	int			*field_prec;
	uintmax_t	result;
	int			len;

	field_prec = (int*)malloc(sizeof(int) * 4);
	field_prec[2] = 2;
	field_prec[3] = 0;
	field_prec[1] = 0;
	c = ft_strnew(4);
	c[0] = '\0';
	c[1] = 32;
	manage_flags(argument, &field_prec, &c);
	c[3] = (*argument)->conversion;
	field_prec[0] = (*argument)->field_width;
	if ((*argument)->precision[0] == 1)
	{
		field_prec[1] = (*argument)->precision[1];
		field_prec[3] = 1;
	}
	result = va_arg(ap, intmax_t);
	return (dont_finish_it_p(c, field_prec, result));
}
