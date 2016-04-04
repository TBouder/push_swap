/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 21:46:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/04 10:11:06 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
// pa : push a - prend le premier élément au sommet de b et le met sur a. (ne fait rien si b est vide).
// pb : push b - prend le premier élément au sommet de a et le met sur b. (ne fait rien si a est vide).

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

void	ft_push_to_b_r(t_swap *a, t_swap *b, int *i)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	if (ft_sorted_a(a))
		ft_push_to_a_r(a, b, i); /*ICI MODIF REQUISE SANS DOUTE : 15 14 13 6 4 9 8 5 7 0*/
	else
	{
		ft_printf("{g}pb{0}\n");
		pa(b, a);
		ft_flag_v(a, b);
		*i += 1;
	}
	ft_calls_push(a, b, i);
}

void	ft_push_to_a_r(t_swap *a, t_swap *b, int *i)
{
	ft_is_sorted(a) && ft_is_null(b) ? ft_success(a, b, i) : 0;

	ft_printf("{g}pa{0}\n");
	pa(a, b);
	ft_flag_v(a, b);
	*i += 1;
	ft_calls_push(a, b, i);
}
