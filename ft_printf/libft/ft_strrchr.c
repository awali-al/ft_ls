/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:09:07 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 17:09:08 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		jumper;
	char	*s_pointer;

	s_pointer = (char*)s;
	jumper = ft_strlen(s_pointer) - 1;
	if (c == '\0')
		return (s_pointer + ft_strlen(s));
	while (jumper >= 0)
	{
		if (s_pointer[jumper] == c)
			return (s_pointer + jumper);
		jumper--;
	}
	return (NULL);
}
