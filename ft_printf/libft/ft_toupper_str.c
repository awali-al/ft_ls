/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:11:29 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 17:11:30 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_toupper_str(char *str)
{
	int jumper;

	jumper = -1;
	while (str[++jumper])
		if (str[jumper] >= 'a' && str[jumper] <= 'z')
			str[jumper] = str[jumper] - ('a' - 'A');
	return (str);
}
