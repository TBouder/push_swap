/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 22:54:39 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/08 18:45:08 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rra(t_swap *a)
{
	int		first;
	int		activ;

	first = 0;
	activ = 0;
	if (a && a->activ == 1)
	{
		first = a->stack;
		activ = a->activ;
	}
	while (a->next)
	{
		a->stack = a->next->stack;
		a->activ = a->next->activ;
		a = a->next;
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

void	ft_rrr_a(t_swap *a, t_swap *b, t_flag *flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, *flg) : 0;
	if (flg->color)
		flg->verbose ? ft_printf("{c}rra{0}\n") : ft_printf("{c}rra{0} ");
	else
		flg->verbose ? ft_printf("rra\n") : ft_printf("rra ");
	rra(a);
	flg->verbose ? ft_flag_v(a, b) : 0;
	flg->cnt += 1;
	ft_calls_rev_rot(a, b, flg);
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, *flg) : 0;
}

void	ft_rrr_b(t_swap *a, t_swap *b, t_flag *flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, *flg) : 0;
	if (flg->color)
		flg->verbose ? ft_printf("{b}rrb{0}\n") : ft_printf("{b}rrb{0} ");
	else
		flg->verbose ? ft_printf("rrb\n") : ft_printf("rrb ");
	rra(b);
	flg->verbose ? ft_flag_v(a, b) : 0;
	flg->cnt += 1;
	ft_calls_rev_rot(a, b, flg);
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, *flg) : 0;
}

void	ft_rrr_ab(t_swap *a, t_swap *b, t_flag *flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, *flg) : 0;
	if (flg->color)
		flg->verbose ? ft_printf("{y}rrr{0}\n") : ft_printf("{y}rrr{0} ");
	else
		flg->verbose ? ft_printf("rrr\n") : ft_printf("rrr ");
	rrr(a, b);
	flg->verbose ? ft_flag_v(a, b) : 0;
	flg->cnt += 1;
	ft_calls_rev_rot(a, b, flg);
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, *flg) : 0;
}
