/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:27:29 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/20 20:11:43 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char	*derb10(char *nbr, int ten)
{
	while (ten-- >= 1)
		nbr = ft_strjoin(nbr, "0");
	return (nbr);
}

char	*ouss_version_beta(char *nb1, char *nb2)
{
	int		jumper1;
	int		jumper2;
	char	*str;
	char	*temp;

	if (nb2[0] == '0')
		return ("1");
	jumper2 = ft_atoi(nb2) - 1;
	str = ft_strdup(nb1);
	while (jumper2 > 0)
	{
		temp = str;
		jumper1 = ft_atoi(nb1);
		while (jumper1 > 1)
		{
			str = addition(str, temp);
			jumper1--;
		}
		jumper2--;
	}
	str = hayad_ziroyat(str);
	return (str);
}

char	*derb_2(char *str, int nb)
{
	int		jumper;
	char	*result;
	int		rest;
	int		holder;
	char	*t;

	jumper = ft_strlen(str);
	result = ft_strnew(0);
	holder = 0;
	t = ft_strnew(1);
	rest = 0;
	while (--jumper >= 0)
	{
		holder = nb * (str[jumper] - '0') + rest;
		t[0] = (holder % 10) + '0';
		result = ft_strjoin(t, result);
		rest = (holder / 10);
	}
	t[0] = rest + '0';
	result = ft_strjoin(t, result);
	return (result);
}

char	*multiplication(char *first, char *second)
{
	char	*result;
	int		jumper;
	int		i;

	result = ft_strnew(0);
	if (is_it_zero(first) || is_it_zero(second))
		return ("0");
	jumper = ft_strlen(second);
	i = -1;
	result = ft_strjoin("0", result);
	while (++i < jumper)
	{
		result = ft_strjoin(result, "0");
		result = addition(result, derb_2(first, second[i] - '0'));
	}
	return (hayad_ziroyat(result));
}

char	*addition(char *first, char *second)
{
	char	*result;
	int		jumper;
	int		rest;
	int		len_first;
	int		len_second;

	len_first = ft_strlen(first) - 1;
	len_second = ft_strlen(second) - 1;
	jumper = get_big(len_first, len_second);
	result = ft_strnew(jumper + 1);
	ft_memset(result, '0', jumper);
	rest = 0;
	while (jumper >= 0)
	{
		if (len_first >= 0 && len_second >= 0)
			rest = (first[len_first--] - '0') +
				(second[len_second--] - '0') + rest;
		else if (len_second >= 0)
			rest = (second[len_second--] - '0') + rest;
		else if (len_first >= 0)
			rest = (first[len_first--] - '0') + rest;
		result[jumper--] = (rest % 10) + '0';
		rest = rest / 10;
	}
	return (result);
}
