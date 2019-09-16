/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:43:32 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 15:44:14 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				jumper;
	unsigned char	*s1_clone;
	unsigned char	*s2_clone;

	s1_clone = (unsigned char*)s1;
	s2_clone = (unsigned char*)s2;
	jumper = 0;
	while (s1_clone[jumper] == s2_clone[jumper] && s1_clone[jumper] != '\0')
		jumper++;
	return (s1_clone[jumper] - s2_clone[jumper]);
}
