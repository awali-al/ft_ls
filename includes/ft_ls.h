/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:54:16 by awali-al          #+#    #+#             */
/*   Updated: 2019/09/16 15:28:40 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "./includes/ft_printf.h"
# include "../libft/libft.h"
# include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

# define O_A 1
# define O_D 2
# define O_G 4
# define O_I 8
# define O_L 16
# define O_REC 32
# define O_REV 64
# define O_T 128

typedef unsigned short ust;

int		options(int ac, char **av, ust *o);
void	show_dir(char *path, ust o);

#endif