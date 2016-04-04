/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:56:44 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/04 10:52:35 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
// sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a.
// (ne fait rien s’il n’y en a qu’un ou aucun).
// sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b.
// (ne fait rien s’il n’y en a qu’un ou aucun).
// ss : sa et sb en même temps.

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

void	ft_swap_a_r(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	flg.verbose ? ft_printf("{g}sa{0}\n") : ft_printf("{g}sa{0} \0");
	sa(a);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;
	ft_calls_swap(a, b, i, flg);
}

void	ft_swap_b_r(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	flg.verbose ? ft_printf("{g}sb{0}\n") : ft_printf("{g}sb{0} \0");
	sa(b);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;
	ft_calls_swap(a, b, i, flg);
}

void	ft_swap_ab_r(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	flg.verbose ? ft_printf("{g}ss{0}\n") : ft_printf("{g}ss{0} \0");
	ss(a, b);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;
	ft_calls_swap(a, b, i, flg);
}
