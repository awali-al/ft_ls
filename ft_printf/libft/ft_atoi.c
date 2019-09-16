/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:16:49 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/31 17:49:55 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	jumper;
	int	result;
	int	sign;

	jumper = 0;
	result = 0;
	sign = 1;
	while (ft_iswhitespace(str[jumper]) == 1)
		jumper++;
	if (str[jumper] == '-')
	{
		sign = -1;
		jumper++;
	}
	else if (str[jumper] == '+')
	{
		sign = 1;
		jumper++;
	}
	while (str[jumper] >= '0' && str[jumper] <= '9')
	{
		result = result * 10 + (str[jumper] - 48);
		jumper++;
	}
	return (result * sign);
}
