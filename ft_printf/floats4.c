/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:35:15 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/06 18:35:17 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char	*pos_exponent(char *mantisa, int exp)
{
	char	*temp;
	int		jumper;
	int		virgule;
	char	*result;

	virgule = 0;
	jumper = 0;
	temp = ft_strnew(0);
	temp = multiplication(ouss_version_beta("2", ft_itoa(exp)), mantisa);
	virgule = ft_strlen(mantisa) - 1;
	result = ft_strnew(ft_strlen(temp) + 1);
	jumper = -1;
	while (++jumper < ft_strlen(temp) - virgule)
		result[jumper] = temp[jumper];
	result[jumper] = '.';
	jumper--;
	while (temp[++jumper])
		result[jumper + 1] = temp[jumper];
	free(temp);
	return (result);
}

char	*neg_exponent(char *mantisa, int exp)
{
	char	*temp;
	int		jumper;
	int		virgule;
	int		hupper;

	virgule = 0;
	jumper = 0;
	temp = ft_strnew(0);
	temp = multiplication(ouss_version_beta("5", ft_itoa(exp * (-1))), mantisa);
	virgule = (ft_strlen(mantisa) - 1) + (exp * (-1));
	jumper = ft_strlen(temp);
	hupper = jumper;
	while (++jumper <= virgule)
		temp = ft_strjoin("0", temp);
	temp = ft_strjoin("0.", temp);
	return (temp);
}

char	*final_step(char *mantisa, int exp)
{
	char	*temp;

	temp = ft_strnew(0);
	if (exp >= 0)
		temp = pos_exponent(mantisa, exp);
	else
		temp = neg_exponent(mantisa, exp);
	if (temp[ft_strlen(temp) - 1] == '.')
		temp = ft_strjoin(temp, "0");
	return (temp);
}

void	sign_width_precision(int signe, t_plist **argument, char **c)
{
	if ((*argument)->flags[2] == 1 && signe != 1)
	{
		**c = 32;
		(*argument)->field_width--;
	}
	else if ((*argument)->flags[2] == 1 && signe == 1)
	{
		**c = '-';
		(*argument)->field_width--;
	}
	else if ((*argument)->flags[1] == 1 && signe != 1)
	{
		**c = '+';
		(*argument)->field_width--;
	}
	else if ((*argument)->flags[1] == 1 && signe == 1)
	{
		**c = '-';
		(*argument)->field_width--;
	}
	else if (signe == 1)
	{
		**c = '-';
		(*argument)->field_width--;
	}
}
