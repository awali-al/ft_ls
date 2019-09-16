/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:49:26 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/28 21:27:33 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void		dont_finish_it_o2(int number, char *temp,
			char *zero_checker, int **field_prec)
{
	if (number == 2)
		(*zero_checker) = 'x';
	else
		(*zero_checker) = 'X';
	if (ft_strcmp("0", temp) != 0)
		(*field_prec)[0] -= 2;
}

int			dont_finish_it_o(int number, char *c,
			int *field_prec, uintmax_t result)
{
	char	*temp;
	int		temp_len;
	char	zero_checker;

	search_conversion(&temp, number, &result);
	if (field_prec[1] == 0 && field_prec[3] == 1 && result == 0)
	{
		c[1] = ' ';
		temp = "";
	}
	field_prec[0] -= ft_strlen(temp);
	field_prec[1] -= ft_strlen(temp);
	if (field_prec[1] >= 0)
		field_prec[0] -= field_prec[1];
	if (c[2] == 1 && number == 1 && ft_strcmp(temp, "0") != 0)
	{
		field_prec[0]--;
		zero_checker = '0';
	}
	if (c[2] == 1 && (number == 2 || number == 3) && temp[0] != '\0')
		dont_finish_it_o2(number, temp, &zero_checker, &field_prec);
	return (finish_it_xx(field_prec, zero_checker, c, temp));
}

void		manage_upper_conversion(t_plist **argument)
{
	if ((*argument)->conversion == 'U')
	{
		(*argument)->conversion = 'u';
		(*argument)->length_modifier = 1;
	}
	if ((*argument)->conversion == 'O')
	{
		(*argument)->conversion = 'o';
		(*argument)->length_modifier = 1;
	}
}

int			make_the_good_call(char *c, int *field_prec,
		va_list ap, t_plist **argument)
{
	uintmax_t result;

	result = len_mod_o(ap, argument);
	if ((*argument)->conversion == 'o')
		return (dont_finish_it_o(1, c, field_prec, result));
	else if ((*argument)->conversion == 'u')
		return (dont_finish_it_o(0, c, field_prec, result));
	else if ((*argument)->conversion == 'x')
		return (dont_finish_it_o(2, c, field_prec, result));
	else if ((*argument)->conversion == 'X')
		return (dont_finish_it_o(3, c, field_prec, result));
	else if ((*argument)->conversion == 'b')
		return (dont_finish_it_o(4, c, field_prec, result));
	else
		return (0);
}

/*
** field_prec ==> 0 -> fw, 1 -> precisions, 2 ->side (1 right, 2 left)
** c ==> 0 -> sign, 1 -> padding, 2 -> #
*/

int			manage_octal(va_list ap, t_plist **argument)
{
	char		*c;
	int			*field_prec;

	if ((*argument)->precision[0] == 1)
		(*argument)->flags[3] = 0;
	field_prec = (int*)malloc(sizeof(int) * 4);
	field_prec[1] = 0;
	c = ft_strnew(3);
	c[0] = '\0';
	c[1] = 32;
	(field_prec[3]) = 0;
	field_prec[2] = (*argument)->flags[0] == 1 ? 1 : 2;
	manage_upper_conversion(argument);
	if ((*argument)->flags[3] == 1)
		c[1] = '0';
	field_prec[0] = (*argument)->field_width;
	if ((*argument)->precision[0] == 1)
	{
		field_prec[1] = (*argument)->precision[1];
		field_prec[3] = 1;
	}
	c[2] = (*argument)->flags[4];
	return (make_the_good_call(c, field_prec, ap, argument));
}
