/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:23:31 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/24 23:09:15 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	reg_srt(t_lof *cur, t_lof *niw)
{
	return (ft_strcmp(cur->p, niw->p));
}

static int	rev_srt(t_lof *cur, t_lof *niw)
{
	return (-reg_srt(cur, niw));
}

static int	tim_srt(t_lof *cur, t_lof *niw)
{
	if (niw->s.st_mtime == cur->s.st_mtime)
		return (reg_srt(cur, niw));
	return (niw->s.st_mtime - cur->s.st_mtime);
}

static int	ret_srt(t_lof *cur, t_lof *niw)
{
	return (-tim_srt(cur, niw));
}

t_sfun		srt_func(unsigned short o)
{
	if (o & FLAG_U)
		return (not_srt);
	else
	{
		if ((o & FLAG_T) && (o & FLAG_REV))
			return (ret_srt);
		else if ((o & FLAG_T))
			return (tim_srt);
		else if ((o & FLAG_REV))
			return (rev_srt);
		else
			return (reg_srt);
	}
}
