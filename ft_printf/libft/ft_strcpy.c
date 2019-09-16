/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:44:25 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 15:44:29 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int jumper;

	jumper = 0;
	while (src[jumper] != '\0')
	{
		dst[jumper] = src[jumper];
		jumper++;
	}
	dst[jumper] = '\0';
	return (dst);
}
