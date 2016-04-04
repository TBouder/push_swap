/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 23:57:54 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/04 10:10:52 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
// rra : reverse rotate a (vers le bas, le dernier élément devient le premier).
// rrb : reverse rotate b (vers le bas, le dernier élément devient le premier).
// rrr : rra et rrb en même temps.

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

void		ft_rev_rot_a_r(t_swap *a, t_swap *b, int *i)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	ft_printf("{g}rra{0}\n");
	rra(a);
	ft_flag_v(a, b);
	*i += 1;

	ft_calls_rev_rot(a, b, i);
}

void		ft_rev_rot_ab_r(t_swap *a, t_swap *b, int *i)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	ft_printf("{g}rrr{0}\n");
	rrr(a, b);
	ft_flag_v(a, b);
	*i += 1;

	ft_calls_rev_rot(a, b, i);
}
