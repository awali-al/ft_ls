/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:42:52 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 15:42:56 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		jumper;
	char	*s_pointer;

	jumper = 0;
	s_pointer = (char*)s;
	if (c == '\0')
	{
		while (s_pointer[jumper] != '\0')
			jumper++;
		return (s_pointer + jumper);
	}
	while (s_pointer[jumper] != '\0')
	{
		if (s_pointer[jumper] == c)
			return (s_pointer + jumper);
		jumper++;
	}
	return (NULL);
}
