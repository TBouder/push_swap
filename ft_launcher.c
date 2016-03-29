/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:05:00 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 17:21:53 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// pa : push a - prend le premier élément au sommet de b et le met sur a. (ne fait rien si b est vide).
// pb : push b - prend le premier élément au sommet de a et le met sur b. (ne fait rien si a est vide).
// ra : rotate a - décale d’une position tous les élements de la pile a. (vers le haut, le premier élément devient le dernier).
// rb : rotate b - décale d’une position tous les élements de la pile b. (vers le haut, le premier élément devient le dernier).
// rr : ra et rb en meme temps. rra : reverse rotate a (vers le bas, le dernier élément devient le premier).
// rrb : reverse rotate b (vers le bas, le dernier élément devient le premier).
// rrr : rra et rrb en même temps.

void	pa(t_swap **a, t_swap **b)
{
	int		temp;
	t_swap	*end;
	t_swap	*b_end;

	if (a)
	{
		end = (*a)->end;
		b_end = (*a)->end->prev;
		if (end != NULL && b_end != NULL)
		{
			temp = end->stack;
			b_end->next = NULL;
			free(end);
			ft_swapend(b, temp);
		}
		else if (end != NULL && b_end == NULL)
		{
			temp = end->stack;
			*a = NULL;
			ft_swapend(b, temp);
		}
	}
	// ft_putstr("pa");
}

void	ft_launcher(t_swap **a)
{
	t_swap	*b;

	b = NULL;
	// ss(*a, b);
	pa(a, &b);
	ft_putstr("b : ");ft_print_swap(b);

}
