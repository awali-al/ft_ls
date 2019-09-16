/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_manipulation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:39:12 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 20:17:33 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char	*hayad_ziroyat(char *str)
{
	int		jumper;
	char	*result;

	if (is_it_zero(str))
		return ("0");
	jumper = 0;
	result = ft_strnew(0);
	while (*str == '0')
		str++;
	result = ft_strjoin(str, result);
	return (result);
}

int		is_it_zero(char *str)
{
	int	jumper;

	jumper = 0;
	while (str[jumper] == '0')
		jumper++;
	if (jumper == ft_strlen(str))
		return (1);
	else
		return (0);
}

char	*hayad_zroyat_lakhrin(char *nbr)
{
	int		jumper;
	char	*result;
	int		hopper;

	jumper = ft_strlen(nbr) - 1;
	if (is_it_zero(nbr))
		return ("0");
	while (nbr[jumper] == '0')
		jumper--;
	result = ft_strnew(jumper);
	hopper = 0;
	while (hopper <= jumper)
	{
		result[hopper] = nbr[hopper];
		hopper++;
	}
	return (result);
}

char	*hayad_zero_wahed(char *number)
{
	int		jumper;
	char	*result;

	jumper = 0;
	if (number[0] == '0')
	{
		result = ft_strnew(ft_strlen(number) - 1);
		while (number[++jumper])
			result[jumper - 1] = number[jumper];
		return (result);
	}
	else
		return (number);
}

char	*take_the_first(char *result)
{
	char	*res;
	int		jumper;

	res = ft_strnew(ft_strlen(result) - 1);
	jumper = 0;
	while (result[++jumper])
		res[jumper - 1] = result[jumper];
	free(result);
	return (res);
}
