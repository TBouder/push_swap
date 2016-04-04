/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 22:54:39 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/04 10:10:58 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
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

void	rr(t_swap *a, t_swap *b)
{
	ra(a);
	ra(b);
}

void	ft_rot_a_r(t_swap *a, t_swap *b, int *i)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	ft_printf("{g}ra{0}\n");
	ra(a);
	ft_flag_v(a, b);
	*i += 1;
	ft_calls_rot(a, b, i);
}

void	ft_rot_b_r(t_swap *a, t_swap *b, int *i)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	ft_printf("{g}rb{0}\n");
	ra(b);
	ft_flag_v(a, b);
	*i += 1;
	ft_calls_rot(a, b, i);
}

void	ft_rot_ab_r(t_swap *a, t_swap *b, int *i)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	ft_printf("{g}rr{0}\n");
	rr(a, b);
	ft_flag_v(a, b);
	*i += 1;
	ft_calls_rot(a, b, i);
}
