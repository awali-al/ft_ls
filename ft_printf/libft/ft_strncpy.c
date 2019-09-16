/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:07:23 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 17:07:25 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int	jumper;

	jumper = 0;
	if (ft_strlen(src) < len)
	{
		while (src[jumper] != '\0')
		{
			dst[jumper] = src[jumper];
			jumper++;
		}
	}
	else
	{
		while (jumper < len)
		{
			dst[jumper] = src[jumper];
			jumper++;
		}
	}
	while (jumper < len)
	{
		dst[jumper] = '\0';
		jumper++;
	}
	return (dst);
}
