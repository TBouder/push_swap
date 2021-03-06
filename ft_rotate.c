/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 23:57:54 by tbouder           #+#    #+#             */
/*   Updated: 2016/06/09 19:40:42 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ra(t_swap *a)
{
	int		first;
	int		activ;

	a = a->end;
	while (a && a->prev && a->activ == 0)
		a = a->prev;
	if (a)
	{
		first = a->stack;
		activ = a->activ;
	}
	while (a && a->prev)
	{
		a->stack = a->prev->stack;
		a->activ = a->prev->activ;
		a = a->prev;
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

int		ft_rr_a(t_swap *a, t_swap *b, t_flag *flg)
{
	if ((!flg->display || flg->all) && flg->color)
		flg->verbose ? ft_printf("{166}ra{0}\n") : ft_printf("{166}ra{0} ");
	else if (!flg->display || flg->all)
		flg->verbose ? ft_printf("ra\n") : ft_printf("ra ");
	ra(a);
	flg->prev = 2;
	flg->verbose ? ft_flag_v(a, b) : 0;
	flg->cnt += 1;
	return (3);
}

int		ft_rr_b(t_swap *a, t_swap *b, t_flag *flg)
{
	if ((!flg->display || flg->all) && flg->color)
		flg->verbose ? ft_printf("{75}rb{0}\n") : ft_printf("{75}rb{0} ");
	else if (!flg->display || flg->all)
		flg->verbose ? ft_printf("rb\n") : ft_printf("rb ");
	ra(b);
	flg->verbose ? ft_flag_v(a, b) : 0;
	flg->cnt += 1;
	return (3);
}

int		ft_rr_ab(t_swap *a, t_swap *b, t_flag *flg)
{
	if ((!flg->display || flg->all) && flg->color)
		flg->verbose ? ft_printf("{120}rr{0}\n") : ft_printf("{120}rr{0} ");
	else if (!flg->display || flg->all)
		flg->verbose ? ft_printf("rr\n") : ft_printf("rr ");
	rr(a, b);
	flg->prev = 2;
	flg->verbose ? ft_flag_v(a, b) : 0;
	flg->cnt += 1;
	return (3);
}
