/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:30:31 by aakfas            #+#    #+#             */
/*   Updated: 2019/06/29 19:01:32 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char	*get_fnbr(char *bin)
{
	int		exp;
	char	*mantisa;
	int		sign;

	mantisa = ft_strnew(0);
	if (bin[0] == '1')
		sign = 1;
	else
		sign = 0;
	exp = get_exponent(1, 8, bin);
	mantisa = use_binary(bin);
	mantisa = hayad_zroyat_lakhrin(mantisa);
	return (final_step(mantisa, exp));
}

char	*check_extrem(char *bin)
{
	int		exp;
	char	*result;
	int		jumper;

	exp = get_exponent(1, 8, bin);
	jumper = 9;
	while (bin[jumper] && bin[jumper] == '0')
		jumper++;
	if (bin[0] == '0' && (jumper - 9) == 23 && exp == 128)
		return ("inf");
	else if (bin[0] == '1' && (jumper - 9) == 23 && exp == 128)
		return ("-inf");
	jumper = 9;
	while (bin[jumper] && bin[jumper] == '0')
		jumper++;
	if (exp == 128 && (jumper - 8) != 23)
		return ("nan");
	return ("zeze");
}

char	*get_binary(float nbr)
{
	char	*result;
	int		jumper;
	int		hopper;

	jumper = 32;
	hopper = -1;
	result = ft_strnew(32);
	while (--jumper >= 0 && ++hopper < 32)
	{
		if (((*(int*)(&nbr) >> jumper) & 1) == 1)
			result[hopper] = '1';
		else
			result[hopper] = '0';
	}
	return (result);
}

int		bigger_then_five(char *number)
{
	int jumper;

	if (number[0] - '0' > 5)
		return (1);
	else if (number[0] - '0' < 5)
		return (-1);
	else
	{
		jumper = 0;
		while (number[++jumper])
			if (number[jumper] != '0')
				return (1);
		return (0);
	}
}

void	check_precision(t_plist **argument)
{
	if ((*argument)->precision[0] == -1 ||
		((*argument)->precision[0] == 1 && (*argument)->precision[1] < 0))
	{
		(*argument)->precision[0] = 1;
		(*argument)->precision[1] = 6;
	}
}
