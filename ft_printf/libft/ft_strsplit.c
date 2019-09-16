/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:09:18 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 17:09:19 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		jump_c(char *s, char c)
{
	int jumper;

	jumper = 0;
	while (s[jumper] == c && s[jumper])
		jumper++;
	return (jumper);
}

static int		jump_not_c(char *s, char c)
{
	int hopper;

	hopper = 0;
	while (s[hopper] != c && s[hopper])
		hopper++;
	return (hopper);
}

static	int		words(char *s, char c)
{
	int jumper;
	int counter;

	jumper = 0;
	counter = 0;
	if (s[0] != c)
	{
		jumper++;
		counter++;
	}
	while (s[jumper] != '\0')
	{
		if (s[jumper - 1] == c && s[jumper] != c)
			counter++;
		jumper++;
	}
	return (counter);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*str;
	char	**result;
	int		i;
	int		words_counter;

	i = 0;
	words_counter = words((char*)s, c);
	if (s == NULL)
		return (NULL);
	if (!(result = (char**)malloc(sizeof(char*) * words_counter + 1)))
		return (NULL);
	str = (char*)s;
	str += jump_c(str, c);
	while (i < words_counter)
	{
		result[i] = (char*)malloc(sizeof(char) * (jump_not_c(str, c) + 1));
		ft_strncpy(result[i], str, jump_not_c(str, c));
		result[i++][jump_not_c(str, c)] = '\0';
		str += jump_not_c(str, c);
		str += jump_c(str, c);
	}
	result[i] = NULL;
	return (result);
}
