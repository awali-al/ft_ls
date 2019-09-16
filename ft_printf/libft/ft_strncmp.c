/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:07:07 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 17:07:09 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	jumper;
	unsigned char	*s1_clone;
	unsigned char	*s2_clone;

	jumper = 0;
	s1_clone = (unsigned char*)s1;
	s2_clone = (unsigned char*)s2;
	while (s1_clone[jumper] == s2_clone[jumper]
			&& s1_clone[jumper] != '\0' && jumper < n)
	{
		if (jumper + 1 == n)
			break ;
		jumper++;
	}
	return (s1_clone[jumper] - s2_clone[jumper]);
}
