/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:10:16 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 17:10:18 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_rev_checker(char *str)
{
	int jumper;

	jumper = ft_strlen(str) - 1;
	while (jumper > 0)
	{
		if (!ft_iswhitespace(str[jumper]))
			return (jumper);
		jumper--;
	}
	return (0);
}

static int	ft_checker(char *str)
{
	int jumper;

	jumper = 0;
	while (str[jumper])
	{
		if (!ft_iswhitespace(str[jumper]))
			return (jumper);
		jumper++;
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		front_jumper;
	int		back_jumper;
	char	*dest;
	int		dest_looper;

	front_jumper = ft_checker((char*)s);
	back_jumper = ft_rev_checker((char*)s);
	dest_looper = 0;
	if (front_jumper == 0 && back_jumper == 0)
		return ("");
	if ((dest = (char*)malloc(sizeof(char) * (back_jumper - front_jumper + 2))))
	{
		while (front_jumper <= back_jumper)
		{
			dest[dest_looper] = s[front_jumper];
			front_jumper++;
			dest_looper++;
		}
		dest[dest_looper] = '\0';
		return (dest);
	}
	else
		return (NULL);
}
