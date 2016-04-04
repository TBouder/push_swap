/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:05:00 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/04 10:15:10 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_print_swap(t_swap *a)
{
	if (a && a->next)
	{
		while (a->next)
		{
			if (a->activ)
			{
				ft_putnbr(a->stack);
				ft_putchar(' ');
			}
			a = a->next;
			if (a->next == NULL && a->activ)
				ft_putnbr(a->stack);
		}
	}
	else if (a && a->next == NULL && a->activ)
		ft_putnbr(a->stack);
}

int		ft_z(t_swap *swap)
{
	t_swap	*tmp;

	tmp = swap->end;
	while (tmp && tmp->activ == 0 && tmp->prev)
		tmp = tmp->prev;
	return (tmp->stack);
}

int		ft_y(t_swap *swap)
{
	t_swap	*tmp;

	tmp = swap->end;
	while (tmp && tmp->activ == 0 && tmp->prev)
		tmp = tmp->prev;
	if (tmp != NULL && tmp->prev)
		tmp = tmp->prev;
	return (tmp->stack);
}

int		ft_sorted_a(t_swap *swap)
{
	long	value;

	value = swap->stack;
	while (swap && swap->activ)
	{
		if (value >= swap->stack && swap->activ)
			value = swap->stack;
		else
			return (0);
		swap = swap->next;
	}
	return (1);
}

int		ft_launcher(t_swap *a, t_swap *b)
{
	int		i;

	i = 0;
	if (ft_z(a) < ft_y(a) && ft_z(a) < a->stack)
		ft_push_to_b_r(a, b, &i);
	else if (ft_z(a) < ft_y(a) && ft_z(a) > a->stack)
		!ft_swaprev(a) ? ft_rot_a_r(a, b, &i) : ft_rev_rot_a_r(a, b, &i);
	else if (ft_z(a) > ft_y(a))
		ft_swap_a_r(a, b, &i);
	else if (ft_z(b) < ft_y(b))
		ft_swap_b_r(a, b, &i);
	return (1);
}
