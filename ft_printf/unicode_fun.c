/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 00:27:52 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/07 00:28:42 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		printc_it_darling(wchar_t result)
{
	int	counter;

	counter = 0;
	if (result >= 0 && result <= 127 && ++counter > 0)
		ft_putchar(result);
	else if (result <= 2047 && (counter += 2) > 0)
	{
		ft_putchar((result >> 6) | 0xC0);
		ft_putchar(((result >> 0) & 0x3F) | 0x80);
	}
	else if (result <= 65535 && (counter += 3) > 0)
	{
		ft_putchar((result >> 12) | 0xE0);
		ft_putchar(((result >> 6) & 0x3F) | 0x80);
		ft_putchar(((result >> 0) & 0x3F) | 0x80);
	}
	else if (result <= 0xFFFFF && (counter += 4) > 0)
	{
		ft_putchar((result >> 18) | 0xF0);
		ft_putchar(((result >> 12) & 0x3F) | 0x80);
		ft_putchar(((result >> 6) & 0x3F) | 0x80);
		ft_putchar(((result >> 0) & 0x3F) | 0x80);
	}
	return (counter);
}

int		count_size_uc(wchar_t result)
{
	int size;
	int jumper;

	size = 0;
	jumper = -1;
	if (result >= 0 && result <= 127)
		return (1);
	else if (result <= 2047)
		return (2);
	else if (result <= 65535)
		return (3);
	else if (result <= 0xFFFFF)
		return (4);
	else
		return (0);
}
