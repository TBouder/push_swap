/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 22:54:39 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/30 17:16:02 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// ra : rotate a - décale d’une position tous les élements de la pile a. (vers le haut, le premier élément devient le dernier).
// rb : rotate b - décale d’une position tous les élements de la pile b. (vers le haut, le premier élément devient le dernier).
// rr : ra et rb en meme temps.


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

void	rb(t_swap *b)
{
	int		first;
	int		activ;

	first = 0;
	activ = 0;
	if (b && b->activ == 1)
	{
		first = b->stack;
		activ = b->activ;
	}
	while (b->next)
	{
		b->stack = b->next->stack;
		b->activ = b->next->activ;
		b = b->next;
	}
	b->stack = first;
	b->activ = activ;
	ft_push_front(b->start);
}

void	rr(t_swap *a, t_swap *b)
{
	ra(a);
	rb(b);
}
