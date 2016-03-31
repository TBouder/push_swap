/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 23:57:54 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/31 19:49:35 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

void	rrb(t_swap *b)
{
	int		first;
	int		activ;

	b = b->end;
	while (b->activ == 0)
		b = b->prev;
	if (b)
	{
		first = b->stack;
		activ = b->activ;
	}
	while (b->prev)
	{
		b->stack = b->prev->stack;
		b->activ = b->prev->activ;
		b = b->prev;
	}
	b->stack = first;
	b->activ = activ;
	ft_push_front(b->start);
}

void	rrr(t_swap *a, t_swap *b)
{
	rra(a);
	rrb(b);
}
