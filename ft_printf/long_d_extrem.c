/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_d_extrem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:12:20 by aakfas            #+#    #+#             */
/*   Updated: 2019/06/26 19:28:16 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		get_exponent_extrem(char *binary)
{
	int		jumper;

	jumper = 1;
	while (binary[jumper] == '1' && jumper < 17)
		jumper++;
	if ((jumper - 1) == 16)
		return (1);
	return (0);
}

char	*check_extrem_ldouble(char *bin)
{
	int		jumper;
	int		exp;

	jumper = 17;
	exp = get_exponent_extrem(bin);
	while (bin[jumper] && bin[jumper] == '0')
		jumper++;
	if (bin[0] == '0' && (jumper - 16) == 64 && exp == 1)
		return ("inf");
	else if (bin[0] == '1' && (jumper - 16) == 64 && exp == 1)
		return ("-inf");
	jumper = 17;
	while (bin[jumper] && bin[jumper] == '0')
		jumper++;
	if (exp == 1 && (jumper - 16) != 64)
		return ("nan");
	return ("zeze");
}

void	assign_s(long bit, char **result, int placement)
{
	if (bit)
		(*result)[placement] = '1';
	else
		(*result)[placement] = '0';
}

void	assign_mantica(long bit, int jumper, int hopper, char **result)
{
	while (--jumper >= 0)
	{
		if ((bit >> jumper) & 1)
			(*result)[++hopper] = '1';
		else
			(*result)[++hopper] = '0';
	}
}

char	*get_binary_long_double(long double nbr)
{
	char	*result;
	int		jumper;
	int		hopper;
	t_data	dt;

	result = ft_strnew(80);
	dt.lb = nbr;
	assign_s(dt.mem.signe, &result, 0);
	hopper = 0;
	jumper = 15;
	while (--jumper >= 0)
	{
		if ((dt.mem.exp >> jumper) & 1)
			result[++hopper] = '1';
		else
			result[++hopper] = '0';
	}
	hopper++;
	assign_s(dt.mem.normalize, &result, hopper);
	jumper = 63;
	assign_mantica(dt.mem.mantisa, jumper, hopper, &result);
	return (result);
}
