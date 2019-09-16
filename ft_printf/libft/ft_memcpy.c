/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:36:03 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 14:36:05 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				jumper;
	unsigned char		*dst_pointer;
	const unsigned char	*src_pointer;

	jumper = 0;
	dst_pointer = dst;
	src_pointer = src;
	while (jumper < n)
	{
		dst_pointer[jumper] = src_pointer[jumper];
		jumper++;
	}
	return (dst);
}
