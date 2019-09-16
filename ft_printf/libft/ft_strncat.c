/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:01:17 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 17:04:10 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	jumper;
	unsigned int	hopper;

	jumper = ft_strlen(s1);
	hopper = 0;
	if (n <= ft_strlen(s2))
	{
		while (hopper < n)
			s1[jumper++] = s2[hopper++];
	}
	else
	{
		while (s2[hopper] != '\0')
			s1[jumper++] = s2[hopper++];
	}
	s1[jumper] = '\0';
	return (s1);
}
