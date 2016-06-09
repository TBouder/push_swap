/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 22:54:39 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/20 20:04:30 by tbouder          ###   ########.fr       */
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
	while (a && a->next)
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

int		ft_rrr_a(t_swap *a, t_swap *b, t_flag *flg)
{
	if ((!flg->display || flg->all) && flg->color)
		flg->verbose ? ft_printf("{166}rra{0}\n") : ft_printf("{166}rra{0} ");
	else if (!flg->display || flg->all)
		flg->verbose ? ft_printf("rra\n") : ft_printf("rra ");
	rra(a);
	flg->prev = 1;
	flg->verbose ? ft_flag_v(a, b) : 0;
	flg->cnt += 1;
	return (2);
}

int		ft_rrr_b(t_swap *a, t_swap *b, t_flag *flg)
{
	if ((!flg->display || flg->all) && flg->color)
		flg->verbose ? ft_printf("{75}rrb{0}\n") : ft_printf("{75}rrb{0} ");
	else if (!flg->display || flg->all)
		flg->verbose ? ft_printf("rrb\n") : ft_printf("rrb ");
	rra(b);
	flg->prev = 1;
	flg->verbose ? ft_flag_v(a, b) : 0;
	flg->cnt += 1;
	return (2);
}

int		ft_rrr_ab(t_swap *a, t_swap *b, t_flag *flg)
{
	if ((!flg->display || flg->all) && flg->color)
		flg->verbose ? ft_printf("{120}rrr{0}\n") : ft_printf("{120}rrr{0} ");
	else if (!flg->display || flg->all)
		flg->verbose ? ft_printf("rrr\n") : ft_printf("rrr ");
	rrr(a, b);
	flg->prev = 1;
	flg->verbose ? ft_flag_v(a, b) : 0;
	flg->cnt += 1;
	return (2);
}
