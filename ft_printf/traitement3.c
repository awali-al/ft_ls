/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 00:27:03 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/07 00:27:04 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		make_it_number(const char *format, int *jumper)
{
	int result;

	result = 0;
	while (format[*jumper] <= '9' && format[*jumper] >= '0')
		result = (result * 10) + format[(*jumper)++] - '0';
	return (result);
}

int		check_if_color(char c)
{
	if (c == '%')
		return (1);
	else if (c == 'R' || c == 'G' || c == 'Y' || c == 'B'
			|| c == 'M' || c == 'C' || c == 'e')
		return (0);
	else
		return (-1);
}

void	check_color(char *color)
{
	if (ft_strcmp(color, "Red") == 0)
		ft_putstr(RED);
	else if (ft_strcmp(color, "Green") == 0)
		ft_putstr(GREEN);
	else if (ft_strcmp(color, "Yellow") == 0)
		ft_putstr(YELLOW);
	else if (ft_strcmp(color, "Blue") == 0)
		ft_putstr(BLUE);
	else if (ft_strcmp(color, "Magneta") == 0)
		ft_putstr(MAGENTA);
	else if (ft_strcmp(color, "Cyan") == 0)
		ft_putstr(CYAN);
	else
		ft_putstr(RESET);
}

void	manage_colors(const char *format, int *jumper)
{
	char		*color;
	int			hopper;

	(*jumper)++;
	hopper = *jumper;
	while (format[hopper] != '}')
		hopper++;
	color = ft_strnew(hopper - (*jumper));
	hopper = 0;
	while (format[*jumper] != '}')
		color[hopper++] = format[(*jumper)++];
	check_color(color);
	(*jumper)++;
	free(color);
}
