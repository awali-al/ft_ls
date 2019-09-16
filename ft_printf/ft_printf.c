/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:35:52 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/28 21:05:21 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_plist	*argument;
	va_list	ap;
	int		retu;

	va_start(ap, format);
	retu = classifier(ap, format, &argument);
	va_end(ap);
	return (retu);
}
