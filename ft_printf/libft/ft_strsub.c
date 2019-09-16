/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:09:48 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 17:10:05 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *dest;

	if ((dest = (char*)malloc(sizeof(char) * (len + 1))))
	{
		dest[len] = '\0';
		ft_memmove(dest, s + start, len);
		return (dest);
	}
	else
		return (NULL);
}
