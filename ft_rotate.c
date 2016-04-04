/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 22:54:39 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/04 12:25:32 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ra(t_swap *a)
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

void	rr(t_swap *a, t_swap *b)
{
	ra(a);
	ra(b);
}

void	ft_rot_a_r(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	flg.verbose ? ft_printf("{c}ra{0}\n") : ft_printf("{c}ra{0} ");
	ra(a);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;
	ft_calls_rot(a, b, i, flg);
}

void	ft_rot_b_r(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	flg.verbose ? ft_printf("{b}rb{0}\n") : ft_printf("{b}rb{0} ");
	ra(b);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;
	ft_calls_rot(a, b, i, flg);
}

void	ft_rot_ab_r(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	flg.verbose ? ft_printf("{y}rr{0}\n") : ft_printf("{y}rr{0} ");
	rr(a, b);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;
	ft_calls_rot(a, b, i, flg);
}
