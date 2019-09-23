/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:19:34 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/23 21:03:13 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	skp_dir(t_lof **tmp, t_lof **prv, t_lof *niw, t_func fun)
{
	while (*tmp && !S_ISDIR((*tmp)->s.st_mode))
	{
		(*prv) = (*tmp);
		(*tmp) = (*tmp)->next;
	}
	while (*tmp && fun.sf((*tmp), niw) < 0)
	{
		(*prv) = (*tmp);
		(*tmp) = (*tmp)->next;
	}
}

static void	arg_fil(char *file, t_lof **head, t_func fun, t_len *l)
{
	t_lof	*niw;
	t_lof	*tmp;
	t_lof	*prv;

	prv = NULL;
	niw = struc_fill(file, l);
	if (!(*head))
		*head = niw;
	else
	{
		tmp = *head;
		if (fun.ff == show_dir && is_dir(niw->p, fun))
			skp_dir(&tmp, &prv, niw, fun);
		else
			while (tmp && fun.sf(tmp, niw) < 0 && !(!is_dir(niw->p, fun)
						&& is_dir(tmp->p, fun)))
			{
				prv = tmp;
				tmp = tmp->next;
			}
		niw->next = tmp;
		prv ? prv->next = niw : 0;
		tmp == *head ? *head = niw : 0;
	}
}

static void	arg_dis(t_lof *head, t_func fun, unsigned short o, t_len l)
{
	t_lof	*tmp;

	if ((o & FLAG_D))
		fun.df(head, l, fun);
	else
	{
		tmp = head;
		while (tmp)
		{
			if (is_dir(tmp->p, fun))
				fol_dis(head, tmp, fun, o);
			else
				file_disp(tmp, fun, l, o);
			tmp = tmp->next;
			tmp && is_dir(tmp->p, fun) ? write(1, "\n\n", 2) : 0;
		}
	}
}

void		args(char **av, int ac, unsigned short o, t_func fun)
{
	t_lof	*head;
	t_len	l;
	char	*str;
	int		i;

	l = len_ini();
	head = NULL;
	i = 0;
	while (i < ac)
	{
		str = ft_strdup(av[i]);
		can_add(o, av[i], 1) ? arg_fil(str, &head, fun, &l) : 0;
		i++;
	}
	arg_dis(head, fun, o, l);
	free_lst(head);
}
