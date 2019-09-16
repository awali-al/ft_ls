/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <aakfas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 00:27:14 by aakfas            #+#    #+#             */
/*   Updated: 2019/06/27 18:24:20 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		check_conversion(char conversion)
{
	if (conversion == 'c' || conversion == 'C' || conversion == 's' ||
		conversion == 'S' || conversion == 'p' || conversion == 'd' ||
		conversion == 'i' || conversion == 'o' || conversion == 'f' ||
		conversion == 'F' || conversion == '%' || conversion == 'u' ||
		conversion == 'x' || conversion == 'X' || conversion == 'b' ||
		conversion == 'D' || conversion == 'U' || conversion == 'O')
		return (1);
	else
		return (0);
}

void	trait_flags(char flag, t_plist **argument)
{
	if (flag == '-')
		(*argument)->flags[0] = 1;
	if (flag == '+')
		(*argument)->flags[1] = 1;
	if (flag == 32)
		(*argument)->flags[2] = 1;
	if (flag == '0')
		(*argument)->flags[3] = 1;
	if (flag == '#')
		(*argument)->flags[4] = 1;
}

void	initializer(t_plist **argument)
{
	int hopper;

	hopper = -1;
	(*argument) = (t_plist*)malloc(sizeof(t_plist));
	(*argument)->flags = (int*)malloc(sizeof(int) * 5);
	(*argument)->precision = (int*)malloc(sizeof(int) * 2);
	(*argument)->field_width = 0;
	(*argument)->precision[0] = -1;
	(*argument)->precision[1] = 0;
	(*argument)->length_modifier = 0;
	while (++hopper < 5)
		(*argument)->flags[hopper] = 0;
}
