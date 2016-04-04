/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursiv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:22:24 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/04 16:22:38 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		ft_calls_swap(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	if (ft_z(a) < ft_y(a))
	{
		ft_z(a) > a->stack && ft_z(b) > ft_y(b) && ft_z(b) < b->stack
			&& ft_swaprev(a) ? ft_rrr_ab(a, b, i, flg) : 0;
		ft_z(a) > a->stack && ft_z(b) > ft_y(b) && ft_z(b) < b->stack
			&& !ft_swaprev(a) ? ft_rr_ab(a, b, i, flg) : 0; // ft_rr_ab(a, b, i, flg);
		ft_z(a) > a->stack && ft_z(b) > a->stack ? ft_rpb_a(a, b, i, flg) : 0;
		ft_z(a) > a->stack ? ft_rr_a(a, b, i, flg) : 0; // !ft_swaprev(a) ? ft_rr_a(a, b, i, flg) : ft_rrr_a(a, b, i, flg);
		ft_z(a) < a->stack ? ft_rpa_b(a, b, i, flg) : 0;
	}
	ft_z(b) > ft_y(b) && ft_z(b) < b->stack ? ft_rr_b(a, b, i, flg) : 0;
}

void		ft_calls_push(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	if (ft_z(a) < ft_y(a))
	{
		ft_z(a) > a->stack && ft_z(b) > ft_y(b) && ft_z(b) < b->stack
			? ft_rr_ab(a, b, i, flg) : 0;
		ft_z(a) > a->stack ? ft_rr_a(a, b, i, flg) : 0;
		ft_z(a) < a->stack ? ft_rpa_b(a, b, i, flg) : 0;
	}
	if (ft_z(a) > ft_y(a))
	{
		ft_z(a) < a->stack && ft_z(b) < ft_y(b) ? ft_rs_ab(a, b, i, flg) : 0;
		ft_z(a) < a->stack && ft_z(b) >= ft_y(b) ? ft_rs_a(a, b, i, flg) : 0;
		ft_z(a) > a->stack && ft_swaprev(a) ? ft_rrr_a(a, b, i, flg) : 0;
		ft_z(a) > a->stack && !ft_swaprev(a) ? ft_rr_a(a, b, i, flg) : 0;
	}
	ft_z(b) > ft_y(b) && ft_z(b) < b->stack ? ft_rr_b(a, b, i, flg) : 0;
	ft_z(b) < ft_y(b) ? ft_rs_b(a, b, i, flg) : 0;
}

void		ft_calls_rot(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_z(a) > ft_y(a) && ft_z(b) < ft_y(b) ? ft_rs_ab(a, b, i, flg) : 0;
	ft_z(a) > ft_y(a) && ft_z(b) >= ft_y(b) ? ft_rs_a(a, b, i, flg) : 0;
	if (ft_z(a) < ft_y(a))
	{
		ft_z(a) < a->stack && ft_y(a) > a->stack ? ft_rr_a(a, b, i, flg) : 0;
		ft_z(a) < a->stack && ft_y(a) > a->stack ? ft_rpa_b(a, b, i, flg) : 0;
		ft_z(a) > a->stack && ft_z(b) > a->stack ? ft_rpb_a(a, b, i, flg) : 0;
		ft_z(a) > a->stack && ft_z(a) > a->stack && ft_z(b) > ft_y(b)
			&& ft_z(b) < b->stack ? ft_rr_ab(a, b, i, flg) : 0;
		ft_z(a) > a->stack && ft_z(a) > a->stack ? ft_rr_a(a, b, i, flg) : 0;
	}
	ft_z(b) < ft_y(b) ? ft_rs_b(a, b, i, flg) : 0;
	ft_z(b) > ft_y(b) && ft_z(b) < b->stack ? ft_rr_b(a, b, i, flg) : 0;
}

void		ft_calls_rev_rot(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	if (ft_z(a) > ft_y(a))
	{
		ft_z(a) < a->stack && ft_z(b) < ft_y(b) ? ft_rs_ab(a, b, i, flg) : 0;
		ft_z(a) < a->stack && ft_z(b) >= ft_y(b) ? ft_rs_a(a, b, i, flg) : 0;
		ft_z(a) > a->stack ? ft_rrr_a(a, b, i, flg) : 0;
	}
	if (ft_z(a) < ft_y(a))
	{
		ft_z(a) < a->stack && ft_y(a) > a->stack ? ft_rrr_a(a, b, i, flg) : 0;
		ft_z(a) < a->stack && ft_y(a) <= a->stack ? ft_rpa_b(a, b, i, flg) : 0;
		ft_z(a) > a->stack && ft_z(b) > a->stack ? ft_rpb_a(a, b, i, flg) : 0;
		ft_z(a) > a->stack && ft_z(a) > a->stack && ft_z(b) > ft_y(b)
			&& ft_z(b) < b->stack ? ft_rrr_ab(a, b, i, flg) : 0;
		ft_z(a) > a->stack && ft_z(a) > a->stack ? ft_rrr_a(a, b, i, flg) : 0;
	}
	ft_z(b) < ft_y(b) ? ft_rs_b(a, b, i, flg) : 0;
	ft_z(b) > ft_y(b) && ft_z(b) < b->stack ? ft_rr_b(a, b, i, flg) : 0;
}
