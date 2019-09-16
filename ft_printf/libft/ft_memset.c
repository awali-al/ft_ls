/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:36:56 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 14:36:57 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	jumper;
	unsigned char	*glorious;

	jumper = 0;
	glorious = b;
	while (jumper < len)
	{
		glorious[jumper] = c;
		jumper++;
	}
	return (b);
}
