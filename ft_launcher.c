/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:05:00 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/18 20:13:40 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void		ft_algo(t_swap *a, t_swap *b, t_flag *flg, int id)
{
	int		i;

	i = id;
	while (!(ft_is_sorted(a) && ft_is_null(b)))
	{
		(id == PB) ? i = ft_rpa_b(a, b, flg) : 0;
		(id == PA) ? i = ft_rpb_a(a, b, flg) : 0;
		(id == RRA) ? i = ft_rrr_a(a, b, flg) : 0;
		(id == RRB) ? i = ft_rrr_b(a, b, flg) : 0;
		(id == RRR) ? i = ft_rrr_ab(a, b, flg) : 0;
		(id == RA) ? i = ft_rr_a(a, b, flg) : 0;
		(id == RB) ? i = ft_rr_b(a, b, flg) : 0;
		(id == RR) ? i = ft_rr_ab(a, b, flg) : 0;
		(id == SA) ? i = ft_rs_a(a, b, flg) : 0;
		(id == SB) ? i = ft_rs_b(a, b, flg) : 0;
		(id == SS) ? i = ft_rs_ab(a, b, flg) : 0;
		(id == 0) ? ft_launcher(a, b, flg) : 0;
		(i == 1) ? id = ft_calls_push(a, b, flg) : 0;
		(i == 2) ? id = ft_calls_rev_rot(a, b) : 0;
		(i == 3) ? id = ft_calls_rot(a, b) : 0;
		(i == 4) ? id = ft_calls_swap(a, b, flg) : 0;
		ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, *flg) : 0;
	}
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, *flg) : 0;
}

int				ft_z(t_swap *swap)
{
	t_swap	*tmp;

	tmp = swap->end;
	while (tmp && tmp->activ == 0 && tmp->prev)
		tmp = tmp->prev;
	return (tmp->stack);
}

int				ft_y(t_swap *swap)
{
	t_swap	*tmp;

	tmp = swap->end;
	while (tmp && tmp->activ == 0 && tmp->prev)
		tmp = tmp->prev;
	if (tmp && tmp != NULL && tmp->prev)
		tmp = tmp->prev;
	return (tmp->stack);
}

int				ft_w(t_swap *swap)
{
	t_swap	*tmp;

	tmp = swap->end;
	while (tmp && tmp->activ == 0 && tmp->prev)
		tmp = tmp->prev;
	if (tmp && tmp != NULL && tmp->prev)
		tmp = tmp->prev;
	if (tmp && tmp != NULL && tmp->prev)
		tmp = tmp->prev;
	return (tmp->stack);
}

int				ft_launcher(t_swap *a, t_swap *b, t_flag *flg)
{
	while (1)
	{
		ft_z(a) > A && ft_z(a) > ft_y(a) && ft_y(a) < A && ft_is_r_sorted(a->end) ? ft_algo(a, b, flg, RA) : 0;
		ft_z(a) > A && ft_z(a) > ft_y(a) && ft_is_r_sorted(a->end->prev) ? ft_algo(a, b, flg, RA) : 0;
		ft_z(a) < ft_y(a) && ft_z(a) < A && ft_y(a) < A ? ft_algo(a, b, flg, RA) : 0;
		ft_z(a) < ft_y(a) && ft_z(a) < A ? ft_algo(a, b, flg, PB) : 0;
		ft_z(a) < ft_y(a) && ft_z(a) > A && !ft_order(a) ? ft_algo(a, b, flg, RRA) : 0;
		ft_z(a) < ft_y(a) && ft_z(a) > A && ft_order(a) ? ft_algo(a, b, flg, RA) : 0;
		ft_z(a) > ft_y(a) ? ft_algo(a, b, flg, SA) : 0;
		ft_z(b) < ft_y(b) ? ft_algo(a, b, flg, SB) : 0;
	}
	return (1);
}
