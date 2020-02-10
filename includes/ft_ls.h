/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:55:19 by aminewalial       #+#    #+#             */
/*   Updated: 2019/09/25 15:39:13 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <errno.h>
# include <stdio.h>
# include <sys/stat.h>
# include <time.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <sys/acl.h>
# include <sys/types.h>

# define FLAG_A 1
# define FLAG_D 2
# define FLAG_G 4
# define FLAG_I 8
# define FLAG_L 16
# define FLAG_REC 32
# define FLAG_REV 64
# define FLAG_T 128
# define FLAG_F 256
# define FLAG_U 512
# define FLAG_ERR 1024

# define COL_RED "\x1b[31m"
# define COL_MAGENTA "\x1b[35m"
# define COL_CYAN "\x1b[36m"
# define COL_RESET "\x1b[0m"

struct s_func;

typedef struct		s_len
{
	int				blk_cnt;
	int				max_ino;
	int				max_nhl;
	int				max_usr;
	int				max_grp;
	int				max_siz;
	int				max_maj;
	int				max_min;
}					t_len;

typedef struct		s_lof
{
	char			*p;
	struct stat		s;
	struct s_lof	*next;
}					t_lof;

typedef void		(*t_cfun)(char *, mode_t, int);
typedef void		(*t_dfun)(t_lof *, t_len, struct s_func);
typedef void		(*t_ffun)(char *, struct s_func, unsigned short);
typedef void		(*t_ifun)(int, int);
typedef void		(*t_rfun)(t_lof *, struct s_func, unsigned short);
typedef int			(*t_sfun)(t_lof *, t_lof *);

typedef struct		s_func
{
	t_cfun			cf;
	t_dfun			df;
	t_ffun			ff;
	t_ifun			in;
	t_rfun			rf;
	t_sfun			sf;
}					t_func;

int					options(int ac, char **av, unsigned short *o);
void				fun_ini(t_func *fun, unsigned short o);

t_len				len_ini(void);
void				len_fil(t_lof *node, t_len *l);

int					int_len(int n);
t_lof				*struc_fill(char *file, t_len *l);
void				free_lst(t_lof *head);
void				erro(char *path);
int					can_add(unsigned short o, char *file, int n);
void				show_dir(char *path, struct s_func fun, unsigned short o);

void				lis_fil(char *file, t_lof **head, t_func fun, t_len *l);
void				lis_dis(t_lof *head, t_func fun, t_len l, unsigned short o);
void				reg_dis(t_lof *head, t_len l, struct s_func fun);
int					is_dir(char *path, t_func fun);

t_cfun				col_func(unsigned short o);
t_dfun				dis_func(unsigned short o);
t_ffun				fol_func(unsigned short o);
t_ifun				ino_func(unsigned short o);
t_rfun				rec_func(unsigned short o);
t_sfun				srt_func(unsigned short o);

void				dis_type(mode_t mode);
void				dis_perm(mode_t mode);
void				dis_link(nlink_t nhl, int max);
void				dis_user(uid_t uid, int max);
void				dis_grup(gid_t gid, int max);
void				dis_size(struct stat s, t_len l);
void				dis_date(time_t t);
void				dis_shct(char *path, off_t s);

void				args(char **av, int ac, unsigned short o, t_func fun);
void				fol_dis(t_lof *h, t_lof *tmp, t_func fun, unsigned short o);
void				file_disp(t_lof *node, t_func f, t_len l, unsigned short o);

int					not_srt(t_lof *cur, t_lof *niw);

#endif
