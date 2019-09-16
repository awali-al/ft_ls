/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakfas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:10:30 by aakfas            #+#    #+#             */
/*   Updated: 2019/03/27 21:16:02 by aakfas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <locale.h>

typedef struct	s_plist
{
	int		*flags;
	int		field_width;
	int		*precision;
	int		length_modifier;
	char	conversion;
}				t_plist;
typedef struct	s_ieee
{
	long		mantisa:63;
	long		normalize:1;
	long		exp:15;
	long		signe:1;
}				t_ieee;
typedef union	u_data
{
	long double	lb;
	t_ieee		mem;
}				t_data;

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

int				ft_printf(const char *format, ...);
int				classifier(va_list ap, const char *format, t_plist **argument);
void			traitement(va_list ap, const char *format,
				t_plist **argument, int *jumper);
void			trait_flags(char flag, t_plist **argument);
int				make_it_number(const char *format, int *jumper);
char			*dec_hex(uintmax_t nbr);
char			*dec_octal(uintmax_t nbr);
char			*dec_bin(uintmax_t nbr);
int				manage_char(va_list ap, t_plist **argument);
int				manage_integers(va_list ap, t_plist **argument);
int				manage_unichar(va_list ap, t_plist **argument);
int				dont_finish_it(int number, char *c,
				int *field_prec, intmax_t result);
int				dont_finish_it_o(int number, char *c,
				int *field_prec, uintmax_t result);
void			dont_finish_it_c(char *c, int *field_prec, int result);
int				dont_finish_it_s(char *c, int *field_prec, char *result);
int				dont_finish_it_p(char *c, int	*field_prec, intmax_t result);
int				finish_it(int *field_prec, char *c, char *temp);
int				finish_it_xx(int *field_prec, char zero_checker,
				char *c, char *temp);
void			finish_it_c(int *field_prec, char *c, int result);
int				finish_it_s(int *field_prec, char *c, char *temp);
int				finish_it_p(int *field_prec, char *c, char *temp);
intmax_t		len_mod(va_list ap, t_plist **argument);
uintmax_t		len_mod_o(va_list ap, t_plist **argument);
char			*len_mod_s(va_list ap, t_plist **argument);
char			*make_spaces(int size);
char			*make_zeros(int size);
int				manage_pointers(va_list ap, t_plist **argument);
int				manage_string(va_list ap, t_plist **argument);
int				manage_octal(va_list ap, t_plist **argument);
void			trait_precision(int *jumper, const char *format,
				t_plist **argument, va_list ap);
void			trait_field_width(const char *format, va_list ap,
				int *jumper, t_plist **argument);
void			length_modifier(const char *format,
				int *jumper, t_plist **argument);
int				printc_it_darling(wchar_t result);
int				ft_put_uchar(int *field_prec, char *c, wchar_t result);
int				dont_finish_it_uc(char *c, int *field_prec, wchar_t result);
int				prints_it_darling(wchar_t *result);
int				ft_put_ustr(int *field_prec, char *c, wchar_t *result);
int				dont_finish_it_us(char *c, int *field_prec, wchar_t *result);
int				count_size_uc(wchar_t result);
int				count_size_us(wchar_t *result);
char			*addition(char *first, char *second);
char			*derb_2(char *str, int nb);
char			*multiplication(char *first, char *second);
char			*derb10(char *nbr, int ten);
char			*hayad_ziroyat(char *str);
char			*ouss(char *nb1, char *nb2);
char			*ouss_version_beta(char *nb1, char *nb2);
int				manage_floats(va_list ap, t_plist **argument);
char			*get_binary(float nbr);
char			*use_binary(char *binary);
int				get_exponent(int start, int end, char *binary);
char			*bin_dec(char *binary);
char			*get_mantica(char *bin);
char			*get_fnbr(char *bin);
char			*hayad_zroyat_lakhrin(char *nbr);
char			*final_step(char *mantisa, int exp);
char			*manage_rounding(char *number, t_plist **argument);
int				manage_double(va_list ap, t_plist **argument);
char			*get_binary_double(double nbr);
char			*get_dnbr(char *bin);
char			*use_binary_d(char *binary);
int				get_exponent_d(int start, int end, char *binary);
char			*get_mantica_d(char *bin);
int				dont_finish_it_f(int signe, char *number, t_plist **argument);
int				finish_it_nan(int *field_prec, char *c, char *temp);
int				finish_it_f(int signe, int *field_prec, char *c, char *temp);
int				finish_it_inf(int *field_prec, char *c, char *temp);
int				manage_long_double(va_list ap, t_plist **argument);
char			*get_binary_long_double(long double nbr);
int				is_it_zero(char *str);
char			*hayad_zero_wahed(char *number);
int				bigger_then_five(char *number);
char			*take_the_first(char *result);
int				check_return(char *str, int fw);
char			*check_extrem(char *bin);
char			*check_extrem_double(char *bin);
int				dont_finish_it_extrem(int signe, char *definer,
				t_plist **argument);
int				is_zero(char *str);
int				manage_percent(va_list ap, t_plist **argument);
void			manage_colors(const char *format, int *jumper);
void			check_color(char *color);
int				check_all(const char *format, t_plist **argument);
int				check_if_color(char c);
int				check_conversion(char conversion);
int				make_it_number(const char *format, int *jumper);
int				check_uni_preci(t_plist *argument);
void			trait_flags(char flag, t_plist **argument);
void			initializer(t_plist **argument);
void			put_it(int **field_prec, char *temp, char **c, int *counter);
void			search_conversion(char **temp, int number, uintmax_t *result);
int				get_big(int nbr1, int nbr2);
char			*hayad_ziroyat(char *str);
int				is_it_zero(char *str);
char			*hayad_zroyat_lakhrin(char *nbr);
char			*hayad_zero_wahed(char *number);
char			*take_the_first(char *result);
void			check_precision(t_plist **argument);
int				bigger_then_five(char *number);
char			*get_binary(float nbr);
char			*check_extrem(char *bin);
char			*get_fnbr(char *bin);
char			*precision_0(char ***real_virgule, t_plist **argument);
char			*add_one_or_no(char *something, char **real_virgule,
				t_plist **argument);
void			check_lenght_fd(int **field_prec, t_plist **argument,
				char *number, int signe);
void			print2(int signe, char c, int *counter);
void			print(char *temp, int *counter, char c);
char			*check_extrem_ldouble(char *bin);
void			sign_width_precision(int signe, t_plist **argument, char **c);

#endif
