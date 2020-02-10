/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_choice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:57:37 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/17 17:56:18 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	fun_ini(t_func *fun, unsigned short o)
{
	fun->cf = col_func(o);
	fun->df = dis_func(o);
	fun->ff = fol_func(o);
	fun->in = ino_func(o);
	fun->rf = rec_func(o);
	fun->sf = srt_func(o);
}
