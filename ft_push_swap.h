/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:27:33 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/18 17:04:18 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# define A a->stack
# define B b->stack
# define PB 1
# define PA 2
# define RRA 3
# define RRB 4
# define RRR 5
# define RA 6
# define RB 7
# define RR 8
# define SA 9
# define SB 10
# define SS 11

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
	long			cnt;
	int				prev;
	int				display;
}					t_flag;

/*
** ft_tools
*/
long				ft_atoi_swap(const char *str);
void				ft_check_min_man(long value);
void				ft_check_duplicates(t_swap *a);
void				ft_init_b(int len, t_swap **b);
t_swap				*ft_end(t_swap *swap);

/*
** ft_exit
*/
void				ft_error(void);
void				ft_usage(char *str);
void				ft_success(t_swap *a, t_swap *b, t_flag flg);
void				ft_exit_one_nb(t_swap *a, t_flag flg);
void				ft_exit_already_ordered(t_swap *a, t_flag flg);

/*
** ft_swap_struct
*/
void				ft_swapend(t_swap **swap, int value, int activ);
void				ft_push_front(t_swap *stack);
int					ft_swaplen(t_swap *swap);
int					ft_order(t_swap *swap);

/*
** ft_flags
*/
void				ft_print_swap(t_swap *a);
void				ft_print_infos(t_swap *a);
void				ft_flag_v(t_swap *a, t_swap *b);
void				ft_init_flag(t_flag *flg);

/*
** ft_launcher
*/
int					ft_z(t_swap *swap);
int					ft_y(t_swap *swap);
int					ft_w(t_swap *swap);
int					ft_launcher(t_swap *a, t_swap *b, t_flag *flg);

/*
** ft_list_state
*/
int					ft_sorted_a(t_swap *swap);
int					ft_sorted_all(t_swap *a, t_swap *b);
int					ft_is_sorted(t_swap *swap);
int					ft_is_r_sorted(t_swap *swap);
int					ft_is_null(t_swap *swap);

/*
** ft_recursiv
*/
int					ft_calls_swap(t_swap *a, t_swap *b, t_flag *flg);
int					ft_calls_push(t_swap *a, t_swap *b, t_flag *flg);
int					ft_calls_rot(t_swap *a, t_swap *b);
int					ft_calls_rev_rot(t_swap *a, t_swap *b);

/*
** ft_swap
*/
void				sa(t_swap *a);
void				ss(t_swap *a, t_swap *b);
int					ft_rs_a(t_swap *a, t_swap *b, t_flag *flg);
int					ft_rs_b(t_swap *a, t_swap *b, t_flag *flg);
int					ft_rs_ab(t_swap *a, t_swap *b, t_flag *flg);

/*
** ft_push
*/
void				pa(t_swap *a, t_swap *b);
int					ft_rpa_b(t_swap *a, t_swap *b, t_flag *flg);
int					ft_rpb_a(t_swap *a, t_swap *b, t_flag *flg);

/*
** ft_rotate
*/
void				rra(t_swap *a);
void				rrr(t_swap *a, t_swap *b);
int					ft_rrr_a(t_swap *a, t_swap *b, t_flag *flg);
int					ft_rrr_b(t_swap *a, t_swap *b, t_flag *flg);
int					ft_rrr_ab(t_swap *a, t_swap *b, t_flag *flg);

/*
** ft_rev_rotate
*/
void				ra(t_swap *a);
void				rr(t_swap *a, t_swap *b);
int					ft_rr_a(t_swap *a, t_swap *b, t_flag *flg);
int					ft_rr_b(t_swap *a, t_swap *b, t_flag *flg);
int					ft_rr_ab(t_swap *a, t_swap *b, t_flag *flg);

#endif
