/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursiv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:22:24 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/01 17:56:44 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_success(t_swap *a, t_swap *b, int *i)
{
	a = NULL;
	b = NULL;
	free(a);
	free(b);
	ft_putstr("i : ");ft_nbrendl(*i);ft_putstr("\n\n");
	exit(EXIT_SUCCESS);
}

/*----------------*/

void		ft_calls_swap(t_swap *a, t_swap *b, int *i)
{
	if (ft_z(a) < ft_y(a))
	{
		if (ft_z(a) > a->stack)
		{
			if (ft_z(b) > ft_y(b) && ft_z(b) < b->stack)
				ft_rot_ab_r(a, b, i);
			else if (ft_z(b) > a->stack)
				ft_push_to_a_r(a, b, i);
			else
				ft_rot_a_r(a, b, i);
		}
		else
			ft_push_to_b_r(a, b, i);
	}
	else if (ft_z(b) > ft_y(b))
		if (ft_z(b) < b->stack)
			ft_rot_b_r(a, b, i);
}

/*----------------*/

void		ft_calls_push(t_swap *a, t_swap *b, int *i)
{
	if (ft_z(a) < ft_y(a))
	{
		if (ft_z(a) > a->stack)
			ft_z(b) > ft_y(b) && ft_z(b) < b->stack ? ft_rot_ab_r(a, b, i)
				: ft_rot_a_r(a, b, i);
		else if (ft_z(a) < a->stack)
			ft_push_to_b_r(a, b, i);
	}
	else if (ft_z(a) > ft_y(a))
	{
		if (ft_z(a) < a->stack)
			ft_z(b) < ft_y(b) ? ft_swap_ab_r(a, b, i) : ft_swap_a_r(a, b, i);
		if (ft_z(a) > a->stack)
			!ft_swaprev(a) ? ft_rot_a_r(a, b, i) : ft_rev_rot_a_r(a, b, i);
	}
	else if (ft_z(b) > ft_y(b) && ft_z(b) < b->stack)
		ft_rot_b_r(a, b, i);
	else if (ft_z(b) < ft_y(b))
		ft_swap_b_r(a, b, i);
}

/*----------------*/

void		ft_calls_rot(t_swap *a, t_swap *b, int *i)
{
	if (ft_z(a) > ft_y(a))
		ft_z(b) < ft_y(b) ? ft_swap_ab_r(a, b, i) : ft_swap_a_r(a, b, i);
	else if (ft_z(a) < ft_y(a))
	{
		if (ft_z(a) < a->stack)
			ft_y(a) > a->stack ? ft_rot_a_r(a, b, i) : ft_push_to_b_r(a, b, i);
		else if (ft_z(a) > a->stack)
		{
			if (ft_z(b) > a->stack)
				ft_push_to_a_r(a, b, i);
			else if (ft_z(a) > a->stack)
				ft_z(b) > ft_y(b) && ft_z(b) < b->stack ? ft_rot_ab_r(a, b, i) : ft_rot_a_r(a, b, i);
		}
	}
	else if (ft_z(b) < ft_y(b))
		ft_swap_b_r(a, b, i);
	else if (ft_z(b) > ft_y(b))
		ft_z(b) < b->stack ? ft_rot_b_r(a, b, i) : 0;
}

/*----------------*/

void		ft_calls_rev_rot(t_swap *a, t_swap *b, int *i)
{
	if (ft_z(a) > ft_y(a))
	{
		if (ft_z(a) < a->stack)
			ft_z(b) < ft_y(b) ? ft_swap_ab_r(a, b, i) : ft_swap_a_r(a, b, i);
		if (ft_z(a) > a->stack)
			ft_rev_rot_a_r(a, b, i);
	}
	else if (ft_z(a) < ft_y(a))
	{
		if (ft_z(a) < a->stack)
			ft_y(a) > a->stack ? ft_rot_a_r(a, b, i) : ft_push_to_b_r(a, b, i);
		else if (ft_z(a) > a->stack)
		{
			if (ft_z(b) > a->stack)
				ft_push_to_a_r(a, b, i);
			else if (ft_z(a) > a->stack)
				ft_z(b) > ft_y(b) && ft_z(b) < b->stack ? ft_rot_ab_r(a, b, i) : ft_rot_a_r(a, b, i);
		}
	}
	else if (ft_z(b) < ft_y(b))
		ft_swap_b_r(a, b, i);
	else if (ft_z(b) > ft_y(b))
		ft_z(b) < b->stack ? ft_rot_b_r(a, b, i) : 0;
}
