/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 20:36:51 by tbouder           #+#    #+#             */
/*   Updated: 2016/06/08 19:56:23 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int		ft_count_stack(t_swap *a)
{
	int		i;

	i = 0;
	while (a->next && A < a->next->stack)
	{
		a = a->next;
		i++;
	}
	return (i);
}

static int		ft_count_stack_rev(t_swap *a)
{
	int		i;

	i = 0;
	while (a->next)
	{
		if (A < a->next->stack)
			i++;
		a = a->next;
	}
	return (i);
}

static t_swap	*ft_jump_to_stack(t_swap *a, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		a = a->next;
		j++;
	}
	return (a);
}

static void		ft_unordered_helper(t_swap *a, t_swap *b, t_flag *flg, int i)
{
	int		j;

	j = 0;
	while (j++ <= i)
		ft_rrr_a(a, b, flg);
	j = ft_count_stack_rev(a);
	while (j-- > 1)
	{
		ft_rs_a(a, b, flg);
		if (j != 1)
			ft_rpa_b(a, b, flg);
		else
			ft_rr_a(a, b, flg);
	}
	j = ft_swap_len(b);
	while (j-- > 0)
	{
		ft_rpb_a(a, b, flg);
		ft_rr_a(a, b, flg);
	}
	ft_rr_a(a, b, flg);
	ft_success(a, b, *flg);
}

void			ft_start_unordered(t_swap *a, t_swap *b, t_flag *flg)
{
	int		i;

	i = ft_count_stack(a);
	if (A < a->next->stack && ft_is_sorted(a->next))
	{
		if (ft_is_sorted(ft_jump_to_stack(a, i)))
		{
			ft_rrr_a(a, b, flg);
			ft_is_sorted(a) ? ft_success(a, b, *flg) : 0;
			ft_rrr_a(a, b, flg);
			ft_rs_a(a, b, flg);
			ft_rr_a(a, b, flg);
			ft_rr_a(a, b, flg);
			ft_success(a, b, *flg);
		}
	}
 	if (ft_is_sorted(ft_jump_to_stack(a, i)))
		ft_unordered_helper(a, b, flg, i);
}
