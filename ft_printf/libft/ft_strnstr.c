/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:08:54 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 17:08:57 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checker(char *hay, char *need, size_t jumper, size_t len)
{
	int				hopper;
	unsigned int	counter;

	hopper = 0;
	counter = 0;
	while (jumper < len && need[hopper] != '\0')
	{
		if (need[hopper] != hay[jumper])
			return (-1);
		jumper++;
		hopper++;
		counter++;
	}
	if (counter == ft_strlen(need))
		return (0);
	return (-1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	jumper;
	char			*clone_haystack;
	char			*clone_needle;

	jumper = 0;
	clone_haystack = (char*)haystack;
	clone_needle = (char*)needle;
	if (clone_needle[0] == '\0')
		return (clone_haystack);
	if (ft_strlen(clone_haystack) < len)
		len = ft_strlen(clone_haystack);
	while (clone_haystack[jumper] != '\0')
	{
		if (clone_haystack[jumper] == needle[0])
		{
			if (checker(clone_haystack, clone_needle, jumper, len) == 0)
				return (clone_haystack + jumper);
			jumper++;
		}
		jumper++;
	}
	return (NULL);
}
