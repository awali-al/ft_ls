/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:38:52 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 20:17:59 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		get_exponent_ld(int start, int end, char *binary)
{
	char	*bi;
	int		*bin;
	int		result;
	int		jumper;

	jumper = -1;
	bi = ft_strnew(15);
	bin = (int*)malloc(sizeof(int) * 15);
	while (++jumper < 15)
		bi[jumper] = binary[start++];
	start = 15;
	result = 0;
	jumper = -1;
	while (--start >= 0)
		if (bi[++jumper] == '1')
			result += ft_atoi(ouss_version_beta("2", ft_itoa(start)));
	return (result - 16383);
}

char	*use_binary_ld(char *binary)
{
	int		jumper;
	char	*result;

	jumper = 0;
	result = ft_strnew(1);
	if (binary[16] == '1')
		result[0] = '1';
	else
		result[0] = '0';
	binary += 16;
	jumper++;
	while (binary[jumper])
	{
		result = ft_strjoin(result, "0");
		if (binary[jumper] == '1')
			result = addition(result,
					ouss_version_beta("5", ft_itoa(jumper)));
		jumper++;
	}
	result = hayad_ziroyat(result);
	return (result);
}

char	*get_ldnbr(char *bin)
{
	int		exp;
	char	*mantisa;
	int		sign;

	mantisa = ft_strnew(0);
	if (bin[0] == '1')
		sign = 1;
	else
		sign = 0;
	exp = get_exponent_ld(1, 15, bin);
	mantisa = use_binary_ld(bin);
	mantisa = hayad_zroyat_lakhrin(mantisa);
	return (final_step(mantisa, exp));
}

int		manage_long_double(va_list ap, t_plist **argument)
{
	long double	db;
	char		*result;
	int			signe;

	signe = 0;
	db = va_arg(ap, long double);
	result = get_binary_long_double(db);
	if ((*argument)->conversion == 'F')
		(*argument)->conversion = 'f';
	if (db < 0 && ft_strcmp("inf", result) != 0 && ft_strcmp("-inf", result) &&
		ft_strcmp("inf", result) != 0)
	{
		signe = 1;
		db = db * (-1);
	}
	if (ft_strcmp(check_extrem_ldouble(result), "zeze") == 0)
	{
		result = get_ldnbr(result);
		result = manage_rounding(result, argument);
		return (dont_finish_it_f(signe, result, argument));
	}
	return (dont_finish_it_extrem(signe,
			check_extrem_ldouble(result), argument));
}
