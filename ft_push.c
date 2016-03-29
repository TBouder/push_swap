/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 21:46:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 23:53:40 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// pa : push a - prend le premier élément au sommet de b et le met sur a. (ne fait rien si b est vide).
// pb : push b - prend le premier élément au sommet de a et le met sur b. (ne fait rien si a est vide).

void	pa(t_swap *a, t_swap *b)
{
	int		temp;
	t_swap	*end_a;
	t_swap	*end_b;

	end_a = a->end;
	end_b = b->end;
	while (end_a->activ == 0)
		end_a = end_a->prev;
	if (end_a != NULL && end_b != NULL && end_a->activ)
	{
		temp = end_a->stack;
		if (end_b->activ == 0)
		{
			while (end_b->prev && end_b->prev->activ == 0)
				end_b = end_b->prev;
		}
		end_b->activ = 1;
		end_b->stack = temp;
		end_a->activ = 0;
		end_a->stack = 0;
	}
	// ft_putstr("pa");
}

void	pb(t_swap *a, t_swap *b)
{
	int		temp;
	t_swap	*end_a;
	t_swap	*end_b;

	end_a = a->end;
	end_b = b->end;
	while (end_b->activ == 0)
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
	// ft_putstr("pb");
}
