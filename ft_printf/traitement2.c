/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 00:26:49 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/07 00:26:52 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	length_modifier(const char *format, int *jumper, t_plist **argument)
{
	if (format[*jumper] == 'h' && format[(*jumper) + 1] != 'h'
		&& (*jumper)++ >= 0)
		(*argument)->length_modifier = 2;
	if (format[*jumper] == 'h' && format[(*jumper) + 1] == 'h'
		&& ((*jumper) += 2 >= 0))
		(*argument)->length_modifier = 5;
	if (format[*jumper] == 'l' && format[(*jumper) + 1] != 'l'
		&& (*jumper)++ >= 0)
		(*argument)->length_modifier = 1;
	if (format[*jumper] == 'l' && format[(*jumper) + 1] == 'l'
		&& (*jumper)++ >= 0)
		(*argument)->length_modifier = 4;
	if (format[*jumper] == 'L' && (*jumper)++ >= 0)
		(*argument)->length_modifier = 3;
	if (format[*jumper] == 'j' && (*jumper)++ >= 0)
		(*argument)->length_modifier = 6;
	if (format[*jumper] == 'z' && (*jumper)++ >= 0)
		(*argument)->length_modifier = 7;
}

void	trait_precision(int *jumper, const char *format,
		t_plist **argument, va_list ap)
{
	(*jumper)++;
	if (format[*jumper] == '*')
	{
		(*argument)->precision[0] = 1;
		(*argument)->precision[1] = va_arg(ap, int);
		(*jumper)++;
	}
	else if (format[*jumper] >= '0' && format[*jumper] <= '9')
	{
		(*argument)->precision[0] = 1;
		(*argument)->precision[1] = make_it_number(format, jumper);
	}
	else if (format[*jumper] < '0' || format[*jumper] > '9')
	{
		(*argument)->precision[1] = 0;
		(*argument)->precision[0] = 1;
		(*jumper)--;
	}
}

void	trait_field_width(const char *format, va_list ap,
		int *jumper, t_plist **argument)
{
	if (format[*jumper] == '*')
	{
		(*argument)->field_width = va_arg(ap, int);
		if ((*argument)->field_width < 0)
		{
			(*argument)->field_width = -(*argument)->field_width;
			(*argument)->flags[0] = 1;
		}
		(*jumper)++;
	}
	else if (format[*jumper] >= '1' && format[*jumper] <= '9')
		(*argument)->field_width = make_it_number(format, jumper);
}
