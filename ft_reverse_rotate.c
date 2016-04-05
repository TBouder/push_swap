/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 23:57:54 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/05 14:10:49 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rra(t_swap *a)
{
	int		first;
	int		activ;

	a = a->end;
	while (a->activ == 0)
		a = a->prev;
	if (a)
	{
		first = a->stack;
		activ = a->activ;
	}
	while (a->prev)
	{
		a->stack = a->prev->stack;
		a->activ = a->prev->activ;
		a = a->prev;
	}
	a->stack = first;
	a->activ = activ;
	ft_push_front(a->start);
}

void	rrr(t_swap *a, t_swap *b)
{
	rra(a);
	rra(b);
}

void	ft_rrr_a(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i, flg) : 0;
	if (flg.color)
		flg.verbose ? ft_printf("{c}rra{0}\n") : ft_printf("{c}rra{0} ");
	else
		flg.verbose ? ft_printf("rra\n") : ft_printf("rra ");
	rra(a);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;
	ft_calls_rev_rot(a, b, i, flg);
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i, flg) : 0;
}

void	ft_rev_rot_b_r(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i, flg) : 0;
	if (flg.color)
		flg.verbose ? ft_printf("{b}rrb{0}\n") : ft_printf("{b}rrb{0}");
	else
		flg.verbose ? ft_printf("rrb\n") : ft_printf("rrb");
	rra(b);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;
	ft_calls_rev_rot(a, b, i, flg);
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i, flg) : 0;
}

void	ft_rrr_ab(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i, flg) : 0;
	if (flg.color)
		flg.verbose ? ft_printf("{y}rrr{0}\n") : ft_printf("{y}rrr{0}");
	else
		flg.verbose ? ft_printf("rrr\n") : ft_printf("rrr");
	rrr(a, b);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;
	ft_calls_rev_rot(a, b, i, flg);
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i, flg) : 0;
}
