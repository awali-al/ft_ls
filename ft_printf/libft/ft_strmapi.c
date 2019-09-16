/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:00:08 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 16:00:12 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	jumper;
	char			*dest;

	if ((dest = (char*)malloc((sizeof(char) * ft_strlen(s)) + 1)))
	{
		jumper = 0;
		while (s[jumper] != '\0')
		{
			dest[jumper] = f(jumper, s[jumper]);
			jumper++;
		}
		dest[jumper] = '\0';
	}
	return (dest);
}
