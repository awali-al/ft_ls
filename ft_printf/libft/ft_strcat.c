/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:42:34 by aakfas            #+#    #+#             */
/*   Updated: 2019/04/14 13:31:21 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int jumper;
	int hopper;

	jumper = ft_strlen(s1);
	hopper = 0;
	while (s2[hopper] != '\0')
	{
		s1[jumper++] = s2[hopper++];
	}
	s1[jumper] = '\0';
	return (s1);
}
