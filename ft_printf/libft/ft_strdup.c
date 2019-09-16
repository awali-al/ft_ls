/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:44:59 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 15:45:00 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		jumper;

	jumper = 0;
	if ((str = (char*)(malloc(sizeof(*str) * (ft_strlen(s1) + 1)))))
	{
		while (s1[jumper] != '\0')
		{
			str[jumper] = s1[jumper];
			jumper++;
		}
		str[jumper] = '\0';
		return (str);
	}
	else
		return (NULL);
}
