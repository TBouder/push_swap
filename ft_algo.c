/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:22:24 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/18 22:15:07 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#define BNULL ft_is_null(b)

int			ft_calls_swap(t_swap *a, t_swap *b, t_flag *flg)
{
	int		r;

	r = 0;
	if (ft_z(a) < ft_y(a))
	{
		!r && ft_z(a) > A && !BNULL && ft_z(b) > ft_y(b) && ft_z(b) < B && ft_order(a) ? r = RR : 0;
		!r && ft_z(a) > A && !BNULL && ft_z(b) > ft_y(b) && ft_z(b) < B && !ft_order(a) ? r = RRR : 0;
		!r && ft_z(a) > A && flg->prev < 2 ? r = RRA : 0;
		!r && ft_z(a) > A && flg->prev == 2 ? r = RA : 0;
		!r && ft_z(a) < A && ft_y(a) > A && (a->next->stack < ft_z(a) || ft_is_sorted(a->next)) ? r = RRA : 0;
		!r && ft_z(a) < A ? r = PB : 0;
	}
	!r && ft_z(b) >= ft_y(b) && ft_z(b) < B ? r = RRB : 0;
	!r && ft_z(b) < ft_y(b) && ft_z(b) > B ? r = RB : 0;
	return (r);
}

int			ft_calls_push(t_swap *a, t_swap *b, t_flag *flg)
{
	int		r;

	r = 0;
	!r && ft_z(b) >= ft_y(b) && ft_z(b) < B ? r = RRB : 0;
	if (ft_z(a) > ft_y(a))
	{
		!r && ft_z(a) > A && ft_order(a) && flg->prev == 2 ? r = RRA : 0;
		!r && ft_z(a) > A && ft_order(a) && flg->prev < 2 ? r = RA : 0;
		!r && ft_z(b) < ft_y(b) && ft_z(b) > B ? r = RB : 0;
		!r && !BNULL && ft_z(a) < A && ft_z(b) < ft_y(b) ? r = SS : 0;
		!r && !BNULL && ft_z(a) < A && ft_z(b) >= ft_y(b) ? r = SA : 0;
		!r && !BNULL && ft_z(a) > A && ft_z(b) < ft_y(b) ? r = SB : 0;
	}
	else if (ft_z(a) < ft_y(a))
	{
		!r && !BNULL && ft_z(b) < ft_y(b) && ft_z(b) > B ? r = SB : 0;
		!r && !BNULL && ft_z(a) > A && ft_z(b) > ft_y(b) && ft_z(b) < B ? r = RRR : 0;
		!r && ft_z(b) < ft_y(b) ? r = RB : 0;
		!r && ft_z(a) > A && flg->prev < 2 ? r = RRA : 0;
		!r && ft_z(a) > A && flg->prev == 2 ? r = RA : 0;

		!r && ft_z(a) < A && a->next->next && a->next->next->stack > a->next->stack ? r = PB : 0;
		!r && ft_z(a) < A && a->next && a->next->stack > A ? r = PB : 0;
		!r && ft_z(a) < A && ft_y(a) > A && (a->next->stack < ft_z(a) || ft_is_sorted(a->next)) ? r = RRA : 0;
		!r && ft_z(a) < A ? r = PB : 0;
	}
	return (r);
}

int			ft_calls_rev_rot(t_swap *a, t_swap *b)
{
	int		r;

	r = 0;
	!r && ft_z(b) < ft_y(b) && ft_z(b) > B ? r = RB : 0;
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
		!r && ft_z(a) < A && !BNULL && ft_z(b) < ft_y(b) ? r = SB : 0;
		!r && ft_z(a) < A ? r = PB : 0;
		!r && ft_z(a) > A && ft_z(b) > ft_y(b) && ft_z(b) < B && ft_order(a)
			? r = RR : 0;
		!r && ft_z(a) > A && !BNULL && ft_z(b) > A ? r = PA : 0;
		!r && ft_z(a) > A && ft_order(a) ? r = RA : 0;
	}
	return (r);
}
