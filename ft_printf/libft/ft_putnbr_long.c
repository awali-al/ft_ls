/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:29:23 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 15:29:25 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_long(uintmax_t n)
{
	uintmax_t nb;

	nb = n;
	if (nb > 9)
		ft_putnbr_long(nb / 10);
	ft_putchar_fd((nb % 10) + 48, 1);
}