/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:05:00 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/31 19:06:48 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		last(t_swap *swap)
{
	t_swap	*tmp;

	tmp = swap->end;
	while (tmp && tmp->activ == 0 && tmp->prev)
		tmp = tmp->prev;
	return (tmp->stack);
}

int		n_last(t_swap *swap)
{
	t_swap	*tmp;

	tmp = swap->end;
	while (tmp && tmp->activ == 0 && tmp->prev)
		tmp = tmp->prev;
	if (tmp != NULL && tmp->prev)
		tmp = tmp->prev;
	return (tmp->stack);
}

int		sorted_a(t_swap *swap)
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
	// ft_putendl("SORTED");
	return (1);
}

int		sorted_b(t_swap *swap)
{
	long	value;

	value = swap->stack;
	while (swap && swap->activ)
	{
		if (value <= swap->stack && swap->activ)
			value = swap->stack;
		else
			return (0);
		swap = swap->next;
	}
	// ft_putendl("SORTED");
	return (1);
}

int		ft_swap_len(t_swap *swap)
{
	int		i;

	i = 0;
	while (swap)
	{
		swap = swap->next;
		i++;
	}
	return (i);
}

int		ft_rev_or_not(t_swap *swap)
{
	int		len;
	int		o_len;

	len = ft_swap_len(swap);
	swap = swap->end;
	while (swap && swap->activ == 0 && swap->prev)
	{
		swap = swap->prev;
		len--;
	}
	o_len = len;
	while (swap->prev)
	{
		if (swap->stack > swap->prev->stack)
		{
			if (len > o_len / 2 )
				return (1);
			else
				return (0);
		}
		swap = swap->prev;
		len--;
	}
	return (-1);
}

int		ft_launcher(t_swap *a, t_swap *b)
{
	int		i;

	i = 0;
	if (last(a) < n_last(a) && last(a) < a->stack)
		ft_push_to_b_r(a, b, &i);
	else if (last(a) < n_last(a) && last(a) > a->stack)
		!ft_rev_or_not(a) ? ft_rot_a_r(a, b, &i) : ft_rev_rot_a_r(a, b, &i);
	else if (last(a) > n_last(a))
		ft_swap_a_r(a, b, &i);
	else if (last(b) < n_last(b))
		ft_swap_b_r(a, b, &i);
	return (1);
}

// sa(a);
// pb(b, a);
// ra(a);
// pb(b, a);
// ra(a);
// ra(a);
// pb(b, a);
// sb(b);
// ra(a);
// pb(b, a);
// sb(b);
// pa(a, b);
// pa(a, b);
// pa(a, b);
// pa(a, b);
