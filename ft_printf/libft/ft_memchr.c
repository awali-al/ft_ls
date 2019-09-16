/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:32:41 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 14:32:46 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	jumper;
	char			*src_pointer;

	jumper = 0;
	src_pointer = (char*)s;
	while (jumper < n)
	{
		if (src_pointer[jumper] == c)
			return (src_pointer + jumper);
		jumper++;
	}
	return (NULL);
}
