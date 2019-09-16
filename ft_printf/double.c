/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:29:13 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 17:57:10 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		get_exponent_d(int start, int end, char *binary)
{
	char	*bi;
	int		*bin;
	int		result;
	int		jumper;

	jumper = -1;
	bi = ft_strnew(11);
	bin = (int*)malloc(sizeof(int) * 11);
	while (++jumper < 11)
		bi[jumper] = binary[start++];
	start = 11;
	result = 0;
	jumper = -1;
	while (--start >= 0)
		if (bi[++jumper] == '1')
			result += ft_atoi(ouss_version_beta("2", ft_itoa(start)));
	free(bi);
	free(bin);
	return (result - 1023);
}

char	*use_binary_d(char *binary)
{
	int		jumper;
	char	*result;

	jumper = 0;
	binary += 11;
	result = ft_strnew(1);
	result[0] = '1';
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

char	*get_dnbr(char *bin)
{
	int		exp;
	char	*mantisa;
	int		sign;

	mantisa = ft_strnew(0);
	if (bin[0] == '1')
		sign = 1;
	else
		sign = 0;
	exp = get_exponent_d(1, 11, bin);
	mantisa = use_binary_d(bin);
	mantisa = hayad_zroyat_lakhrin(mantisa);
	return (final_step(mantisa, exp));
}

char	*check_extrem_double(char *bin)
{
	int		exp;
	int		jumper;

	exp = get_exponent_d(1, 11, bin);
	jumper = 12;
	while (bin[jumper] && bin[jumper] == '0')
		jumper++;
	if (bin[0] == '0' && (jumper - 12) == 52 && exp == 1024)
		return ("inf");
	else if (bin[0] == '1' && (jumper - 12) == 52 && exp == 1024)
		return ("-inf");
	jumper = 12;
	while (bin[jumper] && bin[jumper] == '0')
		jumper++;
	if (exp == 1024 && (jumper - 12) != 52)
		return ("nan");
	return ("zeze");
}

int		manage_double(va_list ap, t_plist **argument)
{
	double	db;
	char	*result;
	int		signe;

	signe = 0;
	if ((*argument)->conversion == 'F')
		(*argument)->conversion = 'f';
	db = va_arg(ap, double);
	result = check_extrem_double(get_binary_double(db));
	if (db < 0 && ft_strcmp("inf", result) != 0 && ft_strcmp("-inf", result) &&
		ft_strcmp("inf", result) != 0)
	{
		signe = 1;
		db = db * (-1);
	}
	result = get_binary_double(db);
	if (ft_strcmp(check_extrem_double(result), "zeze") == 0)
	{
		result = get_dnbr(result);
		result = manage_rounding(result, argument);
		return (dont_finish_it_f(signe, result, argument));
	}
	return (dont_finish_it_extrem(signe,
			check_extrem_double(result), argument));
}
