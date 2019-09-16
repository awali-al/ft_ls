/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:07:35 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 17:07:36 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char			*result;
	unsigned int	jumper;

	jumper = 0;
	if ((result = (char*)malloc(sizeof(char) * n + 1)))
	{
		while (jumper < n)
		{
			result[jumper] = s1[jumper];
			jumper++;
		}
		result[jumper] = '\0';
	}
	else
		return (NULL);
	return (result);
}
