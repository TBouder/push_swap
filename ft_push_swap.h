/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:27:33 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/04 14:04:50 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
}					t_flag;

int		ft_launcher(t_swap *a, t_swap *b, t_flag flg);

void	ft_print_swap(t_swap *a);

/*Tools*/
void	ft_error();
long	ft_atoi_swap(const char *str);
void	ft_check_min_man(long value);
int		ft_is_sorted(t_swap *swap);
int		ft_is_null(t_swap *swap);
void	ft_success(t_swap *a, t_swap *b, int *i, t_flag flg);


/*Swap_struct*/
void	ft_swapend(t_swap **swap, int value, int activ);
void	ft_push_front(t_swap *stack);
int		ft_swaplen(t_swap *swap);
int		ft_swaprev(t_swap *swap);


/*Launcher*/
int		ft_z(t_swap *swap);
int		ft_y(t_swap *swap);
int		ft_sorted_a(t_swap *swap);

/*Flags*/
void	ft_flag_v(t_swap *a, t_swap *b);


void	ft_swap_a_r(t_swap *a, t_swap *b, int *i, t_flag flg);
void	ft_swap_b_r(t_swap *a, t_swap *b, int *i, t_flag flg);
void	ft_swap_ab_r(t_swap *a, t_swap *b, int *i, t_flag flg);
void	ft_calls_swap(t_swap *a, t_swap *b, int *i, t_flag flg);

void	ft_push_to_b_r(t_swap *a, t_swap *b, int *i, t_flag flg);
void	ft_push_to_a_r(t_swap *a, t_swap *b, int *i, t_flag flg);
void	ft_calls_push(t_swap *a, t_swap *b, int *i, t_flag flg);

void	ft_rot_a_r(t_swap *a, t_swap *b, int *i, t_flag flg);
void	ft_rot_b_r(t_swap *a, t_swap *b, int *i, t_flag flg);
void	ft_rot_ab_r(t_swap *a, t_swap *b, int *i, t_flag flg);
void	ft_calls_rot(t_swap *a, t_swap *b, int *i, t_flag flg);

void	ft_rev_rot_a_r(t_swap *a, t_swap *b, int *i, t_flag flg);
void	ft_rev_rot_b_r(t_swap *a, t_swap *b, int *i, t_flag flg);
void	ft_rev_rot_ab_r(t_swap *a, t_swap *b, int *i, t_flag flg);
void	ft_calls_rev_rot(t_swap *a, t_swap *b, int *i, t_flag flg);


void	sa(t_swap *a);
void	ss(t_swap *a, t_swap *b);
void	pa(t_swap *a, t_swap *b);
void	ra(t_swap *a);
void	rr(t_swap *a, t_swap *b);
void	rra(t_swap *a);
void	rrr(t_swap *a, t_swap *b);

#endif
