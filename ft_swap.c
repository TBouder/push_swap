/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:56:44 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/30 17:01:09 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a. (ne fait rien s’il n’y en a qu’un ou aucun).
// sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b. (ne fait rien s’il n’y en a qu’un ou aucun).
// ss : sa et sb en même temps.

void	sa(t_swap *a)
{
	int		temp;
	t_swap	*end;
	t_swap	*end_2;

	end = a->end;
	while (end && end->activ == 0)
		end = end->prev;
	end_2 = end->prev;
	if (end != NULL && end_2 != NULL)
	{
		temp = end->stack;
		end->stack = end_2->stack;
		end_2->stack = temp;
	}
	// ft_putstr("sa");
}

void	sb(t_swap *b)
{
	int		temp;
	t_swap	*end;
	t_swap	*end_2;

	end = b->end;
	while (end && end->activ == 0)
		end = end->prev;
	end_2 = end->prev;
	if (end != NULL && end_2 != NULL)
	{
		temp = end->stack;
		end->stack = end_2->stack;
		end_2->stack = temp;
	}
	// ft_putstr("sb");
}

void	ss(t_swap *a, t_swap *b)
{
	sa(a);
	sb(b);
}
