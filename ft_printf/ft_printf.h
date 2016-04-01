/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:59:36 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 13:01:26 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <locale.h>
# include "libft/libft.h"
# define ULL unsigned long long

typedef struct		s_flags
{
	int				spaces;
	int				spaces_count;
	int				preci;
	int				preci_diff;
	int				zero;
	int				zero_base;
	int				l;
	int				diaiz;
	int				minus;
	int				plus;
	int				empty;
	int				display;
	int				temp;
	int				star;
	int				prio[3];
}					t_flags;

int					ft_printf(const char *restrict format, ...);
int					ft_printf_conv(char *str, va_list *pa, int *r_value,
						int index);
int					ft_is_printf(char c);
int					ft_binary_to_decimal(int b);
int					*ft_parse_binary(long long b);

int					ft_flag_spaces(char *str, int *index);
int					ft_flag_zero(char *str, int *index, t_flags *flags);
int					ft_flag_preci(char *str, int *index, t_flags *flags);
int					ft_flag_length(char *str, int *index, t_flags flags);
int					ft_flag_bool(int *index);
int					ft_flag_star_bool(int *index, t_flags *flag);

ULL					ft_atoi_ll(const char *str);
char				*ft_itoa_base_ll(unsigned long long n, int base);
char				*ft_itoa_base_ull(unsigned long long n, int base);
int					ft_nbrlen_ll(long long n);
void				ft_putnbr_base_ull(unsigned long long nb, int base,
						int maj);
void				ft_putnbr_ll(long long nb);
void				ft_putnbr_ull(unsigned long long nb);
int					ft_wstrlen_flags(wchar_t *str, t_flags flags);
int					ft_wstrlen(wchar_t *str);
int					ft_wchar_len(int *nbr);
int					ft_conv_s_case2(t_flags flags);

int					ft_conv_percent(t_flags flags);
int					ft_conv_char(t_flags flags, char c);
int					ft_d_i(va_list pa, t_flags flag);
int					ft_d_i_test(va_list pa, t_flags *flag);
int					ft_ld(va_list pa, t_flags flag);
int					ft_x(va_list pa, t_flags flag);
int					ft_lx(va_list pa, t_flags flag);
int					ft_o(va_list pa, t_flags flag);
int					ft_lo(va_list pa, t_flags flag);
int					ft_u(va_list pa, t_flags flag);
int					ft_lu(va_list pa, t_flags flag);
int					ft_s(va_list pa, t_flags flags);
int					ft_ls(va_list pa, t_flags flags);
int					ft_c(va_list pa, t_flags flags);
int					ft_lc(va_list pa, t_flags flags);
int					ft_p(va_list pa, t_flags flags);
int					ft_f(va_list pa, t_flags flag);
int					ft_b(va_list pa, t_flags flag);
int					ft_lb(va_list pa, t_flags flag);

void				ft_put_preci_int(t_flags *flags, long long local_pa,
						int id);
void				ft_put_preci_hex(t_flags *flags, long long local_pa,
						int maj, int flag);
void				ft_put_precision_oct(t_flags *flags, long long local_pa);
void				ft_put_preci_uni(t_flags *flags, long long local_pa);
void				ft_put_precision_str(t_flags flags, char *local_pa,
						int len);

void				ft_before_d_i(t_flags *flags, int v_len,
						long long local_pa);
void				ft_before_x(t_flags *flags, int v_len, long long value,
						int maj);
void				ft_before_o(t_flags *flags, int v_len, int index,
						long long local_pa);
void				ft_before_u(t_flags *flags, int v_len, long long local_pa);
void				ft_before_str(t_flags *flags, int v_len);
void				ft_before_c(t_flags *flags, int v_len);
void				ft_before_f(t_flags *flags, int v_len, double local_pa);

void				ft_after_d_i(t_flags *flags, int v_len, long long local_pa);
void				ft_after_hex(t_flags *flags, int v_len);
void				ft_after_o(t_flags *flags, int v_len);
void				ft_after_u(t_flags *flags, int v_len);
void				ft_after_str(t_flags *flags, int v_len);
void				ft_after_c(t_flags *flags, int v_len);
void				ft_after_f(t_flags *flags, int v_len);

#endif
