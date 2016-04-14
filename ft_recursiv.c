/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursiv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:22:24 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/14 15:23:46 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#define BNULL ft_is_null(b)

int			ft_calls_swap(t_swap *a, t_swap *b)
{
	int		r;

	r = 0;
	if (ft_z(a) < ft_y(a))
	{
		!r && ft_z(a) > A && !BNULL && ft_z(b) > ft_y(b) && ft_z(b) < B
			&& ft_order(a) ? r = 8 : 0;
		!r && ft_z(a) > A && !BNULL && ft_z(b) > ft_y(b) && ft_z(b) < B
			&& !ft_order(a) ? r = 5 : 0;
		!r && ft_z(a) > A && ft_z(b) > A && BNULL ? r = 2 : 0;
		!r && ft_z(a) > A && !ft_order(a) ? r = 3 : 0;
		!r && ft_z(a) > A && ft_order(a) ? r = 6 : 0;
		!r && ft_z(a) < A ? r = 1 : 0;
	}
	!r && ft_z(b) >= ft_y(b) && ft_z(b) < B ? r = 4 : 0;
	!r && ft_z(b) < ft_y(b) && ft_z(b) > B ? r = 7 : 0;
	return (r);
}

int			ft_calls_push(t_swap *a, t_swap *b, t_flag *flg)
{
	int		r;

	r = 0;
	!r && ft_z(b) >= ft_y(b) && ft_z(b) < B ? r = 4 : 0;
	//!r && ft_z(b) < ft_y(b) && ft_z(b) > B ? r = 7 : 0;
	if (ft_z(a) > ft_y(a))
	{
		!r && ft_z(b) < ft_y(b) && ft_z(b) > B ? r = 7 : 0;
		!r && ft_z(a) < A && !BNULL && ft_z(b) < ft_y(b) ? r = 11 : 0;
		!r && ft_z(a) < A && !BNULL && ft_z(b) >= ft_y(b) ? r = 9 : 0;
		!r && ft_z(a) > A && ft_order(a) ? r = 6 : 0;
		!r && ft_z(a) > A && !ft_order(a) ? r = 3 : 0;
		!r && ft_z(a) > A && !BNULL && ft_z(b) < ft_y(b) ? r = 10 : 0;
	}
	else if (ft_z(a) < ft_y(a))
	{
		!r && ft_z(b) < ft_y(b) ? r = 7 : 0;
		// !r && ft_z(b) < ft_y(b) && ft_z(b) > B ? r = 7 : 0;
		!r && ft_z(a) > A && !BNULL && ft_z(b) > ft_y(b) && ft_z(b) < B
			? r = 5 : 0;
		!r && flg->prev < 2 && ft_z(a) > A ? r = 3 : 0;
		!r && flg->prev == 2 && ft_z(a) > A ? r = 6 : 0;
		!r && ft_z(a) < A ? r = 1 : 0;
		!r && ft_z(a) < A && !BNULL && ft_z(b) < ft_y(b) ? r = 10 : 0;
	}
	return (r);
}

int			ft_calls_rev_rot(t_swap *a, t_swap *b)
{
	int		r;

	r = 0;
	//ft_z(b) >= ft_y(b) && ft_z(b) < B ? r = 4 : 0;
	!r && ft_z(b) < ft_y(b) && ft_z(b) > B ? r = 7 : 0;
	if (ft_z(a) > ft_y(a))
	{
		!r && !BNULL && ft_z(b) < ft_y(b) ? r = 11 : 0;
		!r && !BNULL && ft_z(b) >= ft_y(b) ? r = 9 : 0;
		!r && !BNULL && ft_z(b) < ft_y(b) && ft_z(b) > B ? r = 10 : 0;
	}
	if (ft_z(a) < ft_y(a))
	{
		!r && ft_z(a) < A && ft_y(a) > A && (a->next->stack < ft_z(a)
			|| ft_is_sorted(a->next)) ? r = 3 : 0;
		!r && ft_z(a) < A ? r = 1 : 0;
		!r && ft_z(a) > A && !BNULL && ft_z(b) > A ? r = 2 : 0;
		!r && ft_z(a) > A && !BNULL && ft_z(b) > ft_y(b) && ft_z(b) < B
			&& !ft_order(a) ? r = 5 : 0;
		!r && ft_z(a) > A && !BNULL && ft_z(b) > ft_y(b) && ft_z(b) < B
			&& ft_order(a) ? r = 8 : 0;
		!r && ft_z(a) > A && !ft_order(a) ? r = 3 : 0;
		!r && ft_z(a) > A && ft_order(a) ? r = 6 : 0;
		!r && ft_z(a) < A && !BNULL && ft_z(b) < ft_y(b) ? r = 10 : 0;
	}
	return (r);
}

int			ft_calls_rot(t_swap *a, t_swap *b)
{
	int		r;

	r = 0;
	//(ft_z(b) >= ft_y(b) && ft_z(b) < B ? r = 4 : 0;
	!r && ft_z(b) < ft_y(b) && ft_z(b) > B ? r = 7 : 0;
	if (ft_z(a) > ft_y(a))
	{
		!r && ft_z(a) < A && !BNULL && ft_z(b) < ft_y(b) ? r = 11 : 0;
		!r && ft_z(a) < A && !BNULL && ft_z(b) >= ft_y(b) ? r = 9 : 0;
		!r && ft_z(a) > A && !BNULL && ft_z(b) < ft_y(b) ? r = 10 : 0;
		!r && ft_z(a) > A ? r = 6 : 0;
	}
	if (ft_z(a) < ft_y(a))
	{
		!r && ft_z(a) < A && ft_y(a) < A ? r = 1 : 0;
		!r && ft_z(a) > A && !BNULL && ft_z(b) > A ? r = 2 : 0;
		!r && ft_z(a) > A && ft_z(b) > ft_y(b) && ft_z(b) < B ? r = 8 : 0;
		!r && ft_z(a) > A ? r = 6 : 0;
		!r && ft_z(a) < A && !BNULL && ft_z(b) < ft_y(b) ? r = 10 : 0;
	}
	return (r);
}
