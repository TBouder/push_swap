/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 21:46:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/06/09 19:40:20 by tbouder          ###   ########.fr       */
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
	while (end_b && end_b->prev && end_b->activ == 0)
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

int		ft_rpa_b(t_swap *a, t_swap *b, t_flag *flg)
{
	if (ft_sorted_a(a) && !ft_is_null(b))
		ft_rpb_a(a, b, flg);
	else
	{
		if ((!flg->display || flg->all) && flg->color)
			flg->verbose ? ft_printf("{75}pb{0}\n") : ft_printf("{75}pb{0} ");
		else if (!flg->display || flg->all)
			flg->verbose ? ft_printf("pb\n") : ft_printf("pb ");
		pa(b, a);
		flg->verbose ? ft_flag_v(a, b) : 0;
		flg->cnt += 1;
	}
	return (1);
}

int		ft_rpb_a(t_swap *a, t_swap *b, t_flag *flg)
{
	if ((!flg->display || flg->all) && flg->color)
		flg->verbose ? ft_printf("{166}pa{0}\n") : ft_printf("{166}pa{0} ");
	else if (!flg->display || flg->all)
		flg->verbose ? ft_printf("pa\n") : ft_printf("pa ");
	pa(a, b);
	flg->prev == 1 ? flg->prev = 2 : 0;
	flg->verbose ? ft_flag_v(a, b) : 0;
	flg->cnt += 1;
	return (1);
}
