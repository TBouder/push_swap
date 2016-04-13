/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:56:44 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/13 18:26:11 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sa(t_swap *swap)
{
	int		temp;
	t_swap	*end;
	t_swap	*end_2;

	end = swap->end;
	while (end && end->activ == 0 && end->prev)
		end = end->prev;
	end_2 = end->prev;
	if (end != NULL && end_2 != NULL)
	{
		temp = end->stack;
		end->stack = end_2->stack;
		end_2->stack = temp;
	}
}

void	ss(t_swap *a, t_swap *b)
{
	sa(a);
	sa(b);
}

void	ft_rs_a(t_swap *a, t_swap *b, t_flag *flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, *flg) : 0;
	if (flg->color)
		flg->verbose ? ft_printf("{c}sa{0}\n") : ft_printf("{c}sa{0} ");
	else
		flg->verbose ? ft_printf("sa\n") : ft_printf("sa ");
	sa(a);
	flg->verbose ? ft_flag_v(a, b) : 0;
	flg->cnt += 1;
	ft_calls_swap(a, b, flg);
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, *flg) : 0;
}

void	ft_rs_b(t_swap *a, t_swap *b, t_flag *flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, *flg) : 0;
	if (flg->color)
		flg->verbose ? ft_printf("{b}sb{0}\n") : ft_printf("{b}sb{0} ");
	else
		flg->verbose ? ft_printf("sb\n") : ft_printf("sb ");
	sa(b);
	flg->verbose ? ft_flag_v(a, b) : 0;
	flg->cnt += 1;
	ft_calls_swap(a, b, flg);
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, *flg) : 0;
}

void	ft_rs_ab(t_swap *a, t_swap *b, t_flag *flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, *flg) : 0;
	if (flg->color)
		flg->verbose ? ft_printf("{y}ss{0}\n") : ft_printf("{y}ss{0} ");
	else
		flg->verbose ? ft_printf("ss\n") : ft_printf("ss ");
	ss(a, b);
	flg->verbose ? ft_flag_v(a, b) : 0;
	flg->cnt += 1;
	ft_calls_swap(a, b, flg);
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, *flg) : 0;
}
