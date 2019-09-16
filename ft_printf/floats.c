/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:29:32 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/06 18:30:13 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char	*manage_floating_part(char ***real_virgule, t_plist **argument)
{
	char	*something;
	int		jumper;

	something = ft_strnew((*argument)->precision[1]);
	if ((*argument)->precision[1] > ft_strlen((*real_virgule)[1]))
	{
		jumper = -1;
		while (++jumper < ft_strlen((*real_virgule)[1]))
			something[jumper] = (*real_virgule)[1][jumper];
		while (jumper < (*argument)->precision[1])
		{
			something[jumper] = '0';
			jumper++;
		}
	}
	else
	{
		jumper = -1;
		while (++jumper < (*argument)->precision[1])
			something[jumper] = (*real_virgule)[1][jumper];
	}
	return (something);
}

char	*manage_rounding(char *number, t_plist **argument)
{
	char	**real_virgule;
	char	*something;
	char	*result;
	int		jumper;
	int		hopper;

	real_virgule = ft_strsplit(number, '.');
	check_precision(argument);
	if ((*argument)->precision[0] == 1 && (*argument)->precision[1] == 0)
		return (precision_0(&real_virgule, argument));
	something = manage_floating_part(&real_virgule, argument);
	something = add_one_or_no(something, real_virgule, argument);
	something = ft_strjoin(real_virgule[0], something);
	result = ft_strnew(ft_strlen(something) + 1);
	jumper = -1;
	while (++jumper < ft_strlen(real_virgule[0]))
		result[jumper] = real_virgule[0][jumper];
	if ((*argument)->precision[1] > 0)
	{
		result[jumper] = '.';
		jumper--;
		while (something[++jumper])
			result[jumper + 1] = something[jumper];
	}
	return (result);
}

int		manage_floats(va_list ap, t_plist **argument)
{
	float	fl;
	char	*result;
	int		signe;
	char	*check;

	signe = 0;
	if ((*argument)->conversion == 'F')
		(*argument)->conversion = 'f';
	fl = (float)va_arg(ap, double);
	check = check_extrem(get_binary(fl));
	if (fl < 0 && ft_strcmp(check, "inf") != 0 && ft_strcmp(check, "-inf") != 0
			&& ft_strcmp(check, "nan") != 0)
	{
		signe = 1;
		fl = fl * (-1);
	}
	result = get_binary(fl);
	if (ft_strcmp(check_extrem(result), "zeze") == 0)
	{
		result = get_fnbr(result);
		result = manage_rounding(result, argument);
		return (dont_finish_it_f(signe, result, argument));
	}
	return (dont_finish_it_extrem(signe, check_extrem(result), argument));
}
