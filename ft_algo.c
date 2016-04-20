/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:22:24 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/20 13:43:03 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#define BNULL ft_is_null(b)

static int	ft_call_push_helper(t_swap *a, t_swap *b)
{
	int		r;

	r = 0;
	!r && !BNULL && ft_z(b) < ft_y(b) && ft_z(b) > B ? r = SB : 0;
	!r && !BNULL && ft_z(a) > A && ft_z(b) > ft_y(b) && ft_z(b) < B
		? r = RRR : 0;
	!r && !BNULL && ft_z(b) < ft_y(b) ? r = RB : 0;
	!r && ft_z(a) > A && ft_z(b) > ft_y(b) && ft_z(b) < B && ft_order(a)
		? r = RR : 0;
	!r && ft_z(a) < A && a->next->next && a->next->next->stack > a->next->stack
		? r = PB : 0;
	!r && ft_z(a) < A && a->next && a->next->stack > A ? r = PB : 0;
	!r && ft_z(a) < A && ft_y(a) > A && (a->next->stack < ft_z(a)
		|| ft_is_sorted(a->next)) ? r = RRA : 0;
	!r && ft_z(a) < A ? r = PB : 0;
	return (r);
}

int			ft_calls_push(t_swap *a, t_swap *b, t_flag *flg)
{
	int		r;

	r = 0;
	!r && ft_z(b) >= ft_y(b) && ft_z(b) < B ? r = RRB : 0;
	!r && ft_z(a) > A && flg->prev == -1 && ft_order(a) ? r = RRA : 0;
	!r && ft_z(a) > A && flg->prev < 2 ? r = RRA : 0;
	!r && ft_z(a) > A && flg->prev == 2 ? r = RA : 0;
	if (!r && ft_z(a) > ft_y(a))
	{
		!r && !BNULL && ft_z(b) < ft_y(b) && ft_z(b) > B && flg->prev == 2
		? r = RB : 0;
		!r && !BNULL && ft_z(a) < A && ft_z(b) < ft_y(b) ? r = SS : 0;
		!r && !BNULL && ft_z(a) < A && ft_z(b) >= ft_y(b) ? r = SA : 0;
		!r && !BNULL && ft_z(a) > A && ft_z(b) < ft_y(b) ? r = SB : 0;
	}
	else if (!r && ft_z(a) < ft_y(a))
		r = ft_call_push_helper(a, b);
	flg->prev == -1 ? flg->prev = 0 : 0;
	return (r);
}

int			ft_calls_swap(t_swap *a, t_swap *b, t_flag *flg)
{
	int		r;

	r = 0;
	if (ft_z(a) < ft_y(a))
	{
		!r && ft_z(a) > A && !BNULL && ft_z(b) > ft_y(b) && ft_z(b) < B
			&& ft_order(a) ? r = RR : 0;
		!r && ft_z(a) > A && !BNULL && ft_z(b) > ft_y(b) && ft_z(b) < B
			&& !ft_order(a) ? r = RRR : 0;
		!r && ft_z(a) > A && flg->prev < 2 ? r = RRA : 0;
		!r && ft_z(a) > A && flg->prev == 2 ? r = RA : 0;
		!r && ft_z(a) < A && ft_y(a) > A && (a->next->stack < ft_z(a)
			|| ft_is_sorted(a->next)) ? r = RRA : 0;
		!r && ft_z(a) < A ? r = PB : 0;
	}
	!r && ft_z(b) >= ft_y(b) && ft_z(b) < B ? r = RRB : 0;
	!r && !BNULL && ft_z(b) < ft_y(b) && ft_z(b) > B && flg->prev == 2
		? r = RB : 0;
	flg->prev == -1 ? flg->prev = 0 : 0;
	return (r);
}

int			ft_calls_rev_rot(t_swap *a, t_swap *b)
{
	int		r;

	r = 0;
	!r && ft_z(b) < ft_y(b) && ft_z(b) > B ? r = RRB : 0;
	if (ft_z(a) > ft_y(a))
	{
		!r && !BNULL && ft_z(b) < ft_y(b) ? r = SS : 0;
		!r && !BNULL && ft_z(b) >= ft_y(b) ? r = SA : 0;
		!r && !BNULL && ft_z(b) < ft_y(b) && ft_z(b) > B ? r = SB : 0;
	}
	if (ft_z(a) < ft_y(a))
	{
		!r && ft_z(a) < A && ft_y(a) > A && (a->next->stack < ft_z(a)
			|| ft_is_sorted(a->next)) ? r = RRA : 0;
		!r && ft_z(a) < A && !BNULL && ft_z(b) < ft_y(b) ? r = SB : 0;
		!r && ft_z(a) < A ? r = PB : 0;
		!r && ft_z(a) > A && !BNULL && ft_z(b) > ft_y(b) && ft_z(b) < B
			&& !ft_order(a) ? r = RRR : 0;
		!r && ft_z(a) > A && !BNULL && ft_z(b) > A ? r = PA : 0;
		!r && ft_z(a) > A && !ft_order(a) ? r = RRA : 0;
	}
	return (r);
}

int			ft_calls_rot(t_swap *a, t_swap *b)
{
	int		r;

	r = 0;
	!r && ft_z(b) < ft_y(b) && ft_z(b) > B ? r = RB : 0;
	if (ft_z(a) > ft_y(a))
	{
		!r && ft_z(a) < A && !BNULL && ft_z(b) < ft_y(b) ? r = SS : 0;
		!r && ft_z(a) < A && !BNULL && ft_z(b) >= ft_y(b) ? r = SA : 0;
		!r && ft_z(a) > A && !BNULL && ft_z(b) < ft_y(b) ? r = SB : 0;
		!r && ft_z(a) > A ? r = RA : 0;
	}
	if (ft_z(a) < ft_y(a))
	{
		!r && ft_z(a) < A && ft_y(a) > A && (ft_w(a) > A
			|| ft_is_r_sorted(a->end)) ? r = RA : 0;
		!r && ft_z(a) < A && !BNULL && ft_z(b) < ft_y(b) ? r = SB : 0;
		!r && ft_z(a) < A ? r = PB : 0;
		!r && ft_z(a) > A && ft_z(b) > ft_y(b) && ft_z(b) < B
			&& ft_order(a) ? r = RR : 0;
		!r && ft_z(a) > A && !BNULL && ft_z(b) > A ? r = PA : 0;
		!r && ft_z(a) > A && ft_order(a) ? r = RA : 0;
	}
	return (r);
}
