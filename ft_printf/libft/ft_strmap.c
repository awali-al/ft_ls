/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:55:06 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 15:55:07 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		jumper;

	jumper = 0;
	if ((dest = (char*)malloc((sizeof(char) * ft_strlen(s)) + 1)))
	{
		while (s[jumper])
		{
			dest[jumper] = f(s[jumper]);
			jumper++;
		}
		dest[jumper] = '\0';
	}
	return (dest);
}
