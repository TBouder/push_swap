/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:27:33 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/05 14:12:43 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct		s_swap
{
	int				stack;
	int				activ;
	struct s_swap	*start;
	struct s_swap	*end;
	struct s_swap	*next;
	struct s_swap	*prev;
}					t_swap;

typedef struct		s_flag
{
	int				verbose;
	int				color;
	int				ope;
	int				infos;
	int				total_mod;
}					t_flag;

int					ft_launcher(t_swap *a, t_swap *b, t_flag flg);

void				ft_print_swap(t_swap *a);
void				ft_check_duplicates(t_swap *a);
long				ft_atoi_swap(const char *str);
void				ft_check_min_man(long value);
int					ft_is_sorted(t_swap *swap);
int					ft_is_null(t_swap *swap);

void				ft_error(void);
void				ft_success(t_swap *a, t_swap *b, int *i, t_flag flg);
void				ft_exit_one_nb(t_swap *a, t_flag flg);


void				ft_swapend(t_swap **swap, int value, int activ);
void				ft_push_front(t_swap *stack);
int					ft_swaplen(t_swap *swap);
int					ft_swaprev(t_swap *swap);

int					ft_z(t_swap *swap);
int					ft_y(t_swap *swap);
int					ft_sorted_a(t_swap *swap);

void				ft_flag_v(t_swap *a, t_swap *b);
void				ft_print_infos(t_swap *a);
void				ft_init_flag(t_flag *flg);

void				ft_rs_a(t_swap *a, t_swap *b, int *i, t_flag flg);
void				ft_rs_b(t_swap *a, t_swap *b, int *i, t_flag flg);
void				ft_rs_ab(t_swap *a, t_swap *b, int *i, t_flag flg);
void				ft_calls_swap(t_swap *a, t_swap *b, int *i, t_flag flg);

void				ft_rpa_b(t_swap *a, t_swap *b, int *i, t_flag flg);
void				ft_rpb_a(t_swap *a, t_swap *b, int *i, t_flag flg);
void				ft_calls_push(t_swap *a, t_swap *b, int *i, t_flag flg);

void				ft_rr_a(t_swap *a, t_swap *b, int *i, t_flag flg);
void				ft_rr_b(t_swap *a, t_swap *b, int *i, t_flag flg);
void				ft_rr_ab(t_swap *a, t_swap *b, int *i, t_flag flg);
void				ft_calls_rot(t_swap *a, t_swap *b, int *i, t_flag flg);

void				ft_rrr_a(t_swap *a, t_swap *b, int *i, t_flag flg);
void				ft_rev_rot_b_r(t_swap *a, t_swap *b, int *i, t_flag flg);
void				ft_rrr_ab(t_swap *a, t_swap *b, int *i, t_flag flg);
void				ft_calls_rev_rot(t_swap *a, t_swap *b, int *i, t_flag flg);

void				sa(t_swap *a);
void				ss(t_swap *a, t_swap *b);
void				pa(t_swap *a, t_swap *b);
void				ra(t_swap *a);
void				rr(t_swap *a, t_swap *b);
void				rra(t_swap *a);
void				rrr(t_swap *a, t_swap *b);

#endif
