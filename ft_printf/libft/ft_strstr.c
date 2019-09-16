/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:09:29 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 17:09:32 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	succes(char *haystack, char *needle, int jumper)
{
	int hopper;

	hopper = 0;
	while (needle[hopper] != '\0')
	{
		if (needle[hopper] != haystack[jumper])
			return (0);
		hopper++;
		jumper++;
	}
	return (1);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	int jumper;

	jumper = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[jumper] != '\0')
	{
		if (haystack[jumper] == needle[0])
		{
			if (succes((char*)haystack, (char*)needle, jumper) == 1)
			{
				return ((char*)(haystack + jumper));
			}
		}
		jumper++;
	}
	return (NULL);
}
