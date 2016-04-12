/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursiv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:22:24 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/12 19:08:52 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#define BNULL ft_is_null(b)

void		ft_calls_swap(t_swap *a, t_swap *b, t_flag *flg)
{
	if (ft_z(a) < ft_y(a))
	{
		ft_z(a) > A && !BNULL && ft_z(b) > ft_y(b) && ft_z(b) < B && ft_order(a) ? ft_rr_ab(a, b, flg) : 0;
		ft_z(a) > A && !BNULL && ft_z(b) > ft_y(b) && ft_z(b) < B && !ft_order(a) ? ft_rrr_ab(a, b, flg) : 0;
		ft_z(a) > A && ft_z(b) > A && BNULL ? ft_rpb_a(a, b, flg) : 0;
		ft_z(a) > A && !ft_order(a) ? ft_rrr_a(a, b, flg) : 0;
		ft_z(a) > A && ft_order(a) ? ft_rr_a(a, b, flg) : 0;
		ft_z(a) < A ? ft_rpa_b(a, b, flg) : 0;
	}
	ft_z(b) > ft_y(b) && ft_z(b) < B ? ft_rrr_b(a, b, flg) : 0;
}

void		ft_calls_push(t_swap *a, t_swap *b, t_flag *flg)
{
	ft_z(b) >= ft_y(b) && ft_z(b) < B ? ft_rrr_b(a, b, flg) : 0;
	if (ft_z(a) > ft_y(a))
	{
		ft_z(a) < A && !BNULL && ft_z(b) < ft_y(b) ? ft_rs_ab(a, b, flg) : 0;
		ft_z(a) < A && !BNULL && ft_z(b) >= ft_y(b) ? ft_rs_a(a, b, flg) : 0;
		ft_z(a) > A && ft_order(a) ? ft_rr_a(a, b, flg) : 0;
		ft_z(a) > A && !ft_order(a) ? ft_rrr_a(a, b, flg) : 0;
		ft_z(a) > A && !BNULL && ft_z(b) < ft_y(b) ? ft_rs_b(a, b, flg) : 0;
	}
	if (ft_z(a) < ft_y(a))
	{
		ft_z(a) > A && !BNULL && ft_z(b) > ft_y(b) && ft_z(b) < B ? ft_rrr_ab(a, b, flg) : 0;

		flg->prev < 2 && ft_z(a) > A ? ft_rrr_a(a, b, flg) : 0;
		flg->prev == 2 && ft_z(a) > A ? ft_rr_a(a, b, flg) : 0;


		ft_z(a) < A ? ft_rpa_b(a, b, flg) : 0;
		ft_z(a) < A && !BNULL && ft_z(b) < ft_y(b) ? ft_rs_b(a, b, flg) : 0;
	}
	ft_z(b) > ft_y(b) && ft_z(b) < B ? ft_rrr_b(a, b, flg) : 0;
}

void		ft_calls_rev_rot(t_swap *a, t_swap *b, t_flag *flg)
{
	if (ft_z(a) > ft_y(a))
	{
		!BNULL && ft_z(b) < ft_y(b) ? ft_rs_ab(a, b, flg) : 0;
		!BNULL && ft_z(b) >= ft_y(b) ? ft_rs_a(a, b, flg) : 0;
		!BNULL && ft_z(b) < ft_y(b) && ft_z(b) > B ? ft_rs_b(a, b, flg) : 0;
	}
	if (ft_z(a) < ft_y(a))
	{
		ft_z(a) < A && ft_y(a) > A && (a->next->stack < ft_z(a) || ft_is_sorted(a->next)) ? ft_rrr_a(a, b, flg) : 0;
		ft_z(a) < A && ft_y(a) > A ? ft_rpa_b(a, b, flg) : 0;
		ft_z(a) < A && ft_y(a) < A ? ft_rpa_b(a, b, flg) : 0;
		ft_z(a) > A && !BNULL && ft_z(b) > A ? ft_rpb_a(a, b, flg) : 0;
		ft_z(a) > A && !BNULL && ft_z(b) > ft_y(b) && ft_z(b) < B && !ft_order(a) ? ft_rrr_ab(a, b, flg) : 0;
		ft_z(a) > A && !BNULL && ft_z(b) > ft_y(b) && ft_z(b) < B && ft_order(a) ? ft_rr_ab(a, b, flg) : 0;
		ft_z(a) > A && !ft_order(a) ? ft_rrr_a(a, b, flg) : 0;
		ft_z(a) > A && ft_order(a) ? ft_rr_a(a, b, flg) : 0;
		ft_z(a) < A && !BNULL && ft_z(b) < ft_y(b) ? ft_rs_b(a, b, flg) : 0;
	}
	ft_z(b) > ft_y(b) && ft_z(b) < B ? ft_rrr_b(a, b, flg) : 0;
}

void		ft_calls_rot(t_swap *a, t_swap *b, t_flag *flg)
{
	if (ft_z(a) > ft_y(a))
	{
		ft_z(a) < A && !BNULL && ft_z(b) < ft_y(b) ? ft_rs_ab(a, b, flg) : 0;
		ft_z(a) < A && !BNULL && ft_z(b) >= ft_y(b) ? ft_rs_a(a, b, flg) : 0;
		ft_z(a) > A && !BNULL && ft_z(b) < ft_y(b) ? ft_rs_b(a, b, flg) : 0;
		ft_z(a) > A ? ft_rr_a(a, b, flg) : 0;
	}
	if (ft_z(a) < ft_y(a))
	{
		ft_z(a) < A && ft_y(a) < A ? ft_rpa_b(a, b, flg) : 0;
		ft_z(a) > A && !BNULL && ft_z(b) > A ? ft_rpb_a(a, b, flg) : 0;
		ft_z(a) > A && ft_z(b) > ft_y(b) && ft_z(b) < B ? ft_rr_ab(a, b, flg) : 0;
		ft_z(a) > A ? ft_rr_a(a, b, flg) : 0;
		ft_z(a) < A && !BNULL && ft_z(b) < ft_y(b) ? ft_rs_b(a, b, flg) : 0;
	}
	ft_z(b) > ft_y(b) && ft_z(b) < B ? ft_rrr_b(a, b, flg) : 0;
}
