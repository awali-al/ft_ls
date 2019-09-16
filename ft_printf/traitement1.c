/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 23:52:54 by aakfas            #+#    #+#             */
/*   Updated: 2019/09/15 16:27:17 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	traitement(va_list ap, const char *format,
					t_plist **argument, int *jumper)
{
	initializer(argument);
	while (check_conversion(format[*jumper]) != 1 && format[*jumper])
	{
		if (format[*jumper] == '+' || format[*jumper] == '-'
			|| format[*jumper] == 32 || format[*jumper] == '#'
			|| format[*jumper] == '0')
			trait_flags(format[*jumper], argument);
		if ((format[*jumper] >= '1' && format[*jumper] <= '9') ||
				format[*jumper] == '*')
			trait_field_width(format, ap, jumper, argument);
		if (format[*jumper] == '.')
			trait_precision(jumper, format, argument, ap);
		if (format[*jumper] == 'h' || format[*jumper] == 'l' ||
			format[*jumper] == 'L' || format[*jumper] == 'j' ||
			format[*jumper] == 'z')
			length_modifier(format, jumper, argument);
		if (check_conversion(format[*jumper]) == 1)
		{
			(*argument)->conversion = format[*jumper];
			break ;
		}
		(*jumper)++;
	}
	(*argument)->conversion = format[(*jumper)];
}

int		ifcheck(char c, t_plist **argument)
{
	if (c == 'o' || c == 'u' || c == 'U' ||
		c == 'x' || c == 'X' || c == 'b' || c == 'O')
		return (1);
	else if (c == 'S' || c == 'C' || (c == 'c' && (*argument)->length_modifier
			== 1) || (c == 's' && (*argument)->length_modifier == 1))
		return (2);
	else if (c == 's' || c == 'c')
		return (3);
	else if (c == 'f' && (*argument)->length_modifier != 1
			&& (*argument)->length_modifier != 3)
		return (6);
	else if ((c == 'f' && (*argument)->length_modifier == 1) || c == 'F')
		return (4);
	else if ((c == 'f' && (*argument)->length_modifier == 3))
		return (7);
	else if (c == 'd' || c == 'D' || c == 'i')
		return (5);
	return (0);
}

void	call_manager_3(t_plist **argument, int *counter, va_list ap)
{
	if (ifcheck((*argument)->conversion, argument) == 1)
		*counter += manage_octal(ap, argument);
	else if (ifcheck((*argument)->conversion, argument) == 2)
		*counter += manage_unichar(ap, argument);
	else if (ifcheck((*argument)->conversion, argument) == 4)
		*counter += manage_double(ap, argument);
	else if (ifcheck((*argument)->conversion, argument) == 7)
		*counter += manage_long_double(ap, argument);
	else if (ifcheck((*argument)->conversion, argument) == 6)
		*counter += manage_double(ap, argument);
}

void	call_manager_2(t_plist **argument, int *counter, va_list ap)
{
	if ((*argument)->conversion == 'c' &&
		(*argument)->length_modifier != 1)
		*counter += manage_char(ap, argument);
	else if ((*argument)->conversion == '%')
		*counter += manage_percent(ap, argument);
	else if ((*argument)->conversion == 's' &&
			(*argument)->length_modifier != 1)
		*counter += manage_string(ap, argument);
	else if ((*argument)->conversion == 'p')
		*counter += manage_pointers(ap, argument);
	else if (ifcheck((*argument)->conversion, argument) == 5)
		*counter += manage_integers(ap, argument);
	else
		call_manager_3(argument, counter, ap);
}

int		classifier(va_list ap, const char *format, t_plist **argument)
{
	int jumper;
	int counter;

	jumper = 0;
	counter = 0;
	while (jumper < ft_strlen(format))
	{
		if (format[jumper] == '{' && check_if_color(format[jumper + 1]) == 0)
			manage_colors(format, &jumper);
		else if (format[jumper] == '%')
		{
			jumper++;
			traitement(ap, format, argument, &jumper);
			call_manager_2(argument, &counter, ap);
			if (format[jumper] == '{')
				manage_colors(format, &jumper);
			if (check_conversion(format[jumper]))
				jumper++;
		}
		else if (format[jumper] && ++counter >= 0)
			ft_putchar(format[jumper++]);
	}
	return (counter);
}
