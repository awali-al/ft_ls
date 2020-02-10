/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <aakfas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:36:55 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/17 18:17:28 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	dis_date(time_t t)
{
	time_t	tim;
	char	*ct;
	char	*dt;
	char	*yr;

	tim = time(NULL);
	yr = NULL;
	ct = ctime(&t);
	if (t > tim + 1 || t < tim - 15552000)
	{
		dt = ft_strndup(ct + 4, 6);
		yr = ft_strndup(ct + 19, 5);
		ft_putstr(dt);
		write(1, " ", 1);
		ft_putstr(yr);
		free(yr);
	}
	else
	{
		dt = ft_strndup(ct + 4, 12);
		ft_putstr(dt);
	}
	write(1, " ", 1);
	free(dt);
}
