/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:54:06 by aakfas            #+#    #+#             */
/*   Updated: 2019/04/12 18:38:19 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst_saver;
	size_t	size_src_saver;
	size_t	jumper;
	size_t	hopper;

	size_dst_saver = ft_strlen(dst);
	size_src_saver = ft_strlen(src);
	hopper = size_dst_saver;
	jumper = 0;
	if (size_dst_saver >= size)
		return (size + size_src_saver);
	while (src[jumper] && hopper < size - 1)
		dst[hopper++] = src[jumper++];
	dst[hopper] = '\0';
	return (size_dst_saver + size_src_saver);
}
