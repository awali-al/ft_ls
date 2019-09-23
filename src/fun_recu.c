/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_recu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <aakfas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:56:59 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/23 14:39:52 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	rec_disp(t_lof *head, struct s_func fun, unsigned short o)
{
	t_lof	*tmp;
	char	*str;
	char	*nxt;

	tmp = head;
	while (tmp != NULL)
	{
		if (!(str = ft_strrchr(tmp->p, '/')))
			str = tmp->p;
		else
			str++;
		if (S_ISDIR(tmp->s.st_mode) && ft_strcmp(str, ".")
		&& ft_strcmp(str, ".."))
		{
			write(1, "\n", 1);
			ft_putstr(tmp->p);
			write(1, ":\n", 2);
			nxt = ft_strjoin(tmp->p, "/");
			fun.ff(nxt, fun, o);
			ft_strdel(&nxt);
		}
		tmp = tmp->next;
	}
}

t_rfun		rec_func(unsigned short o)
{
	if ((o & FLAG_REC) && (o & FLAG_D) == 0)
		return (rec_disp);
	else
		return (NULL);
}
