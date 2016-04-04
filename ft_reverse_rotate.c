/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 23:57:54 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/04 11:54:20 by tbouder          ###   ########.fr       */
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

void		ft_rev_rot_a_r(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	flg.verbose ? ft_putendl("rra\n") : ft_putstr("rra ");
	rra(a);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;

	ft_calls_rev_rot(a, b, i, flg);
}

void		ft_rev_rot_b_r(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	flg.verbose ? ft_putendl("rrb\n") : ft_putstr("rrb");
	rra(b);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;

	ft_calls_rev_rot(a, b, i, flg);
}

void		ft_rev_rot_ab_r(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	flg.verbose ? ft_putendl("rrr\n") : ft_putstr("rrr");
	rrr(a, b);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;

	ft_calls_rev_rot(a, b, i, flg);
}
