/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 21:46:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/04 14:28:01 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	pa(t_swap *a, t_swap *b)
{
	int		temp;
	t_swap	*end_a;
	t_swap	*end_b;

	end_a = a->end;
	end_b = b->end;
	while (end_b && end_b->activ == 0)
		end_b = end_b->prev;
	if (end_a != NULL && end_b != NULL && end_b->activ)
	{
		temp = end_b->stack;
		if (end_a->activ == 0)
		{
			while (end_a->prev && end_a->prev->activ == 0)
				end_a = end_a->prev;
		}
		end_a->activ = 1;
		end_a->stack = temp;
		end_b->activ = 0;
		end_b->stack = 0;
	}
}

void	ft_rpa_b(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i, flg) : 0;

	if (ft_sorted_a(a))
		ft_rpb_a(a, b, i, flg); /*ICI MODIF REQUISE SANS DOUTE : 15 14 13 6 4 9 8 5 7 0*/
	else
	{
		if (flg.color)
			flg.verbose ? ft_printf("{b}pb{0}\n") : ft_printf("{b}pb{0} ");
		else
			flg.verbose ? ft_printf("pb\n") : ft_printf("pb ");
		pa(b, a);
		flg.verbose ? ft_flag_v(a, b) : 0;
		*i += 1;
	}
	ft_calls_push(a, b, i, flg);
}

void	ft_rpb_a(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i, flg) : 0;
	if (flg.color)
		flg.verbose ? ft_printf("{c}pa{0}\n") : ft_printf("{c}pa{0} ");
	else
		flg.verbose ? ft_printf("pa\n") : ft_printf("pa ");
	pa(a, b);
	flg.verbose ? ft_flag_v(a, b) : 0;
	*i += 1;
	ft_calls_push(a, b, i, flg);
}
