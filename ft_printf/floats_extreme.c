/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats_extreme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:35:41 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/06 18:35:43 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	check_lenght_fd(int **field_prec, t_plist **argument,
		char *number, int signe)
{
	if ((*argument)->field_width > ft_strlen(number))
		(*field_prec)[0] = (*argument)->field_width - ft_strlen(number);
	else
		(*field_prec)[0] = 0;
}

int		finish_it_nan(int *field_prec, char *c, char *temp)
{
	int	jumper;
	int	counter;

	jumper = -1;
	counter = 0;
	while (field_prec[1] == 0 && c[1] == ' ' &&
		--field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(32);
	while (field_prec[1] == 2 && c[1] == '0' &&
		--field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(c[1]);
	ft_putstr(temp);
	counter += ft_strlen(temp);
	while (field_prec[1] == 1 &&
		--field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(32);
	return (counter);
}

int		finish_it_inf(int *field_prec, char *c, char *temp)
{
	int	jumper;
	int	counter;

	jumper = -1;
	counter = 0;
	while (field_prec[1] == 2 && c[1] == ' ' &&
		--field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(32);
	while (field_prec[1] == 2 && c[1] == '0' &&
		--field_prec[0] >= 0 && ++counter > 0)
		ft_putchar(c[1]);
	print(temp, &counter, c[0]);
	while (field_prec[1] == 1 && --field_prec[0] >= 0 &&
		++counter > 0)
		ft_putchar(32);
	return (counter);
}

void	check_extremity(char *definer, char **c, t_plist **argument)
{
	if (definer[0] == '-' && ft_strcmp(definer, "nan") != 0)
	{
		(*c)[0] = '-';
		(*argument)->field_width--;
	}
	else if ((*argument)->flags[1] == 1 && definer[0] != '-' &&
			ft_strcmp(definer, "nan") != 0)
	{
		(*c)[0] = '+';
		(*argument)->field_width--;
	}
	else if ((*argument)->flags[2] == 1 && definer[0] != '-' &&
			ft_strcmp(definer, "nan") != 0)
	{
		(*c)[0] = ' ';
		(*argument)->field_width--;
	}
}

int		dont_finish_it_extrem(int signe, char *definer, t_plist **argument)
{
	char		*c;
	int			*field_prec;

	field_prec = (int*)malloc(sizeof(int) * 2);
	field_prec[1] = 2;
	c = ft_strnew(2);
	c[0] = '\0';
	c[1] = 32;
	if ((*argument)->flags[0] == 1)
		field_prec[1] = 1;
	check_extremity(definer, &c, argument);
	if (definer[0] == '-')
		definer++;
	if ((*argument)->field_width > ft_strlen(definer))
		field_prec[0] = (*argument)->field_width - ft_strlen(definer);
	else
		field_prec[0] = 0;
	if (ft_strcmp("nan", definer) == 0)
		return (finish_it_nan(field_prec, c, definer));
	else
		return (finish_it_inf(field_prec, c, definer));
}
