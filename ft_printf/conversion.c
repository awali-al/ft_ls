/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:28:56 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/06 18:29:01 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char	*dec_octal(uintmax_t nbr)
{
	static char	*str;
	char		*temp;
	char		*hel;

	hel = ft_strnew(1);
	str = ft_strnew(1);
	temp = "01234567";
	if (nbr >= 8)
		dec_octal(nbr / 8);
	hel[0] = temp[nbr % 8];
	str = ft_strjoin(str, hel);
	ft_strdel(&hel);
	return (str);
}

char	*dec_hex(uintmax_t nbr)
{
	static char	*str;
	char		*temp;
	char		*hel;

	hel = ft_strnew(1);
	str = ft_strnew(1);
	temp = "0123456789abcdef";
	if (nbr >= 16)
		dec_hex(nbr / 16);
	hel[0] = temp[nbr % 16];
	str = ft_strjoin(str, hel);
	ft_strdel(&hel);
	return (str);
}

char	*dec_bin(uintmax_t nbr)
{
	static char	*str;
	char		*temp;
	char		*hel;

	hel = ft_strnew(1);
	str = ft_strnew(1);
	temp = "01";
	if (nbr >= 2)
		dec_bin(nbr / 2);
	hel[0] = temp[nbr % 2];
	str = ft_strjoin(str, hel);
	ft_strdel(&hel);
	return (str);
}

char	*get_binary_double(double nbr)
{
	char	*result;
	int		jumper;
	int		hopper;

	jumper = 64;
	hopper = -1;
	result = ft_strnew(64);
	while (--jumper >= 0 && ++hopper < 64)
	{
		if ((*(long long*)(&nbr) >> jumper) & 1)
			result[hopper] = '1';
		else
			result[hopper] = '0';
	}
	return (result);
}

char	*bin_dec(char *binary)
{
	int		jumper;
	int		hopper;
	char	*result;

	jumper = ft_strlen(binary);
	hopper = 0;
	result = ft_strnew(0);
	while (--jumper >= 0)
	{
		if (binary[jumper] == '1')
			result = addition(result,
					ouss_version_beta("2", ft_itoa(hopper)));
		hopper++;
	}
	result = hayad_ziroyat(result);
	return (result);
}
