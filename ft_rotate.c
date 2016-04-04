/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 22:54:39 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/04 14:28:51 by tbouder          ###   ########.fr       */
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

void	ft_rr_a(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i, flg) : 0;

	if (flg.color)
		flg.verbose ? ft_printf("{c}ra{0}\n") : ft_printf("{c}ra{0} ");
	else
		flg.verbose ? ft_printf("ra\n") : ft_printf("ra ");
	ra(a);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;
	ft_calls_rot(a, b, i, flg);
}

void	ft_rr_b(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i, flg) : 0;

	if (flg.color)
		flg.verbose ? ft_printf("{b}rb{0}\n") : ft_printf("{b}rb{0} ");
	else
		flg.verbose ? ft_printf("rb\n") : ft_printf("rb ");
	ra(b);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;
	ft_calls_rot(a, b, i, flg);
}

void	ft_rr_ab(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i, flg) : 0;

	if (flg.color)
		flg.verbose ? ft_printf("{y}rr{0}\n") : ft_printf("{y}rr{0} ");
	else
		flg.verbose ? ft_printf("rr\n") : ft_printf("rr ");
	rr(a, b);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;
	ft_calls_rot(a, b, i, flg);
}
