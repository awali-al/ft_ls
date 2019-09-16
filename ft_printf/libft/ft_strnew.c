/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:08:39 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 17:08:40 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*new_string;
	unsigned int	jumper;

	jumper = 0;
	if ((new_string = (char*)malloc(size + 1)))
	{
		new_string[size] = '\0';
		while (jumper < size)
		{
			new_string[jumper] = '\0';
			jumper++;
		}
		return (new_string);
	}
	else
		return (NULL);
}
