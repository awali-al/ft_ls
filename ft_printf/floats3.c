/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:30:53 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/06 18:30:56 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		get_big(int nbr1, int nbr2)
{
	if (nbr1 >= nbr2)
		return (nbr1 + 1);
	else
		return (nbr2 + 1);
}

int		get_exponent(int start, int end, char *binary)
{
	char	*bi;
	int		*bin;
	int		result;
	int		jumper;

	jumper = -1;
	bi = ft_strnew(8);
	bin = (int*)malloc(sizeof(int) * 8);
	while (++jumper < 8)
		bi[jumper] = binary[start++];
	start = 8;
	result = 0;
	jumper = -1;
	while (--start >= 0)
		if (bi[++jumper] == '1')
			result += ft_atoi(ouss_version_beta("2", ft_itoa(start)));
	return (result - 127);
}

char	*use_binary(char *binary)
{
	int		jumper;
	char	*result;

	jumper = 0;
	binary += 8;
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

char	*add_one_or_no(char *something, char **real_virgule,
						t_plist **argument)
{
	int jumper;

	if (bigger_then_five(real_virgule[1] + (*argument)->precision[1]) == 1)
	{
		jumper = ft_strlen(something);
		something = addition(something, "1");
		something = hayad_zero_wahed(something);
	}
	else if (bigger_then_five(real_virgule[1] + (*argument)->precision[1]) == 0)
	{
		if ((something[(*argument)->precision[1] - 1] - '0') % 2 != 0)
		{
			jumper = ft_strlen(something);
			something = addition(something, "1");
			something = hayad_zero_wahed(something);
		}
	}
	if (jumper < ft_strlen(something))
	{
		something = take_the_first(something);
		real_virgule[0] = addition(real_virgule[0], "1");
		real_virgule[0] = hayad_zero_wahed(real_virgule[0]);
	}
	return (something);
}

char	*precision_0(char ***real_virgule, t_plist **argument)
{
	char	*result;

	if (((*real_virgule)[0][ft_strlen((*real_virgule)[0]) - 1]
		- '0') % 2 == 0 && bigger_then_five((*real_virgule)[1]) == 1)
		result = (hayad_zero_wahed(addition((*real_virgule)[0], "1")));
	else if (((*real_virgule)[0][ft_strlen((*real_virgule)[0]) - 1] - '0') % 2
			!= 0 && ((*real_virgule)[1][0] - '0') >= 5)
		result = (hayad_zero_wahed(addition((*real_virgule)[0], "1")));
	else
		result = ((*real_virgule)[0]);
	if ((*argument)->flags[4] == 1)
	{
		result = ft_strjoin(result, ".");
		return (result);
	}
	else
		return (result);
}
