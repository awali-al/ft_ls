/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:35:43 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 14:35:44 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	jumper;
	unsigned char	*s1_pointer;
	unsigned char	*s2_pointer;
	int				verifier;

	s1_pointer = (unsigned char*)s1;
	s2_pointer = (unsigned char*)s2;
	jumper = 0;
	verifier = 0;
	while (jumper < n)
	{
		if (s1_pointer[jumper] == s2_pointer[jumper])
			verifier = 1;
		else
		{
			verifier = 0;
			break ;
		}
		jumper++;
	}
	if (verifier == 1)
		jumper--;
	return (s1_pointer[jumper] - s2_pointer[jumper]);
}
