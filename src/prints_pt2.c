/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_pt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:01:59 by aminewalial       #+#    #+#             */
/*   Updated: 2019/08/08 19:52:59 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	dis_size(off_t siz, int max)
{
	int		i;
	int		d;

	d = max - int_len((int)siz);
	i = 0;
	while (i <= d)
	{
		write(1, " ", 1);
		i++;
	}
	ft_putnbr((int)siz);
	write(1, " ", 1);
}

void	dis_shct(char *path, off_t s)
{
	char	*buff;

	buff = ft_strnew((int)s);
	readlink(path, buff, s);
	write(1, " -> ", 4);
	ft_putstr(buff);
	free(buff);
	buff = NULL;
}
