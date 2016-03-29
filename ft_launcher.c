/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:05:00 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 14:33:01 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a. (ne fait rien s’il n’y en a qu’un ou aucun).
// sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b. (ne fait rien s’il n’y en a qu’un ou aucun).
// ss : sa et sb en même temps.
// pa : push a - prend le premier élément au sommet de b et le met sur a. (ne fait rien si b est vide).
// pb : push b - prend le premier élément au sommet de a et le met sur b. (ne fait rien si a est vide).
// ra : rotate a - décale d’une position tous les élements de la pile a. (vers le haut, le premier élément devient le dernier).
// rb : rotate b - décale d’une position tous les élements de la pile b. (vers le haut, le premier élément devient le dernier).
// rr : ra et rb en meme temps. rra : reverse rotate a (vers le bas, le dernier élément devient le premier).
// rrb : reverse rotate b (vers le bas, le dernier élément devient le premier).
// rrr : rra et rrb en même temps.

void	sa(int **a, int len)
{
	int		tmp;

	len--;
	if (len > 0)
	{
		tmp = a[0][len];
		a[0][len] = a[0][len - 1];
		a[0][len - 1] = tmp;
	}
}

void	sb(int **b, int len)
{
	int		tmp;

	len--;
	if (len > 0)
	{
		tmp = b[0][len];
		b[0][len] = b[0][len - 1];
		b[0][len - 1] = tmp;
	}
}

void	ss(int **a, int **b, int len)
{
	sa(a, len);
	sb(b, len);
}

int		*ft_launcher(int **a, int len)
{
	int		i;
	int		*b;

	i = 0;
	if(!(b = (int *)malloc(sizeof(int) * len)))
		ft_error();
	while (i < len)
		b[i++] = 0;
	sa(&b, len);
	sa(a, len);
	ss(a, &b, len);


	ft_print(*a, len);
	ft_print(b, len);
	return (*a);
}
