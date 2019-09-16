/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:30:42 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/06 18:30:44 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	print(char *temp, int *counter, char c)
{
	if (c != '\0')
	{
		ft_putchar(c);
		ft_putstr(temp);
		*counter += ft_strlen(temp) + 1;
	}
	else
	{
		ft_putstr(temp);
		*counter += ft_strlen(temp);
	}
}

void	print2(int signe, char c, int *counter)
{
	if (c != '\0')
	{
		ft_putchar(c);
		(*counter)++;
	}
	else if (signe == 1)
	{
		ft_putchar('-');
		(*counter)++;
	}
}

int		finish_it_f(int signe, int *field_prec, char *c, char *temp)
{
	int	jumper;
	int	counter;

	jumper = -1;
	counter = 0;
	while (field_prec[1] == 0 && c[1] == ' ' &&
		--field_prec[0] >= 0 && ++counter >= 0)
		ft_putchar(32);
	print2(signe, c[0], &counter);
	while (field_prec[1] == 0 && c[1] == '0' &&
		--field_prec[0] >= 0 && ++counter >= 0)
		ft_putchar(c[1]);
	ft_putstr(temp);
	counter += ft_strlen(temp);
	while (field_prec[1] == 1 && --field_prec[0] >= 0 &&
		++counter >= 0)
		ft_putchar(32);
	return (counter);
}

void	flags_distribution(int signe, t_plist **argument, char **c)
{
	if ((*argument)->flags[2] == 1 && signe != 1)
	{
		(*c)[0] = 32;
		(*argument)->field_width--;
	}
	else if (((*argument)->flags[2] == 1 && signe == 1) ||
			((*argument)->flags[1] == 1 && signe == 1) ||
			signe == 1)
	{
		(*c)[0] = '-';
		(*argument)->field_width--;
	}
	else if ((*argument)->flags[1] == 1 && signe != 1)
	{
		(*c)[0] = '+';
		(*argument)->field_width--;
	}
}

int		dont_finish_it_f(int signe, char *number, t_plist **argument)
{
	char		*c;
	int			*field_prec;

	field_prec = (int*)malloc(sizeof(int) * 2);
	field_prec[1] = 2;
	c = ft_strnew(3);
	c[0] = '\0';
	c[1] = 32;
	field_prec[1] = (*argument)->flags[0];
	flags_distribution(signe, argument, &c);
	if ((*argument)->flags[3] == 1 && (*argument)->flags[0] != 1)
		c[1] = '0';
	c[3] = (*argument)->conversion;
	check_lenght_fd(&field_prec, argument, number, signe);
	return (finish_it_f(signe, field_prec, c, number));
}
