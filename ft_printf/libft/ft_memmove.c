/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:36:35 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 14:36:36 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*holder;
	unsigned int	jumper;
	unsigned char	*dst_pointer;

	holder = ft_strndup(src, len);
	jumper = 0;
	dst_pointer = (unsigned char*)dst;
	if (len == 0)
		return ((unsigned char*)dst);
	while (jumper < len)
	{
		dst_pointer[jumper] = holder[jumper];
		jumper++;
	}
	return ((unsigned char*)dst);
}
