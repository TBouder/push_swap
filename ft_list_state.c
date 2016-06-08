/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 13:51:05 by tbouder           #+#    #+#             */
/*   Updated: 2016/06/08 19:55:22 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

int		ft_is_sorted(t_swap *swap)
{
	long	value;

	value = swap->stack;
	while (swap)
	{
		if (value >= swap->stack)
			value = swap->stack;
		else
			return (0);
		swap = swap->next;
	}
	return (1);
}

int		ft_is_r_sorted(t_swap *swap)
{
	long	value;

	if (swap->prev)
		swap = swap->prev;
	else
		return (0);
	value = swap->stack;
	while (swap)
	{
		if (value <= swap->stack)
			value = swap->stack;
		else
			return (0);
		swap = swap->prev;
	}
	return (1);
}

int		ft_is_null(t_swap *swap)
{
	while (swap)
	{
		if (swap->activ == 1)
			return (0);
		swap = swap->next;
	}
	return (1);
}

int		ft_swap_len(t_swap *swap)
{
	int		i;

	i = 0;
	while (swap)
	{
		if (swap->activ == 1)
			i++;
		swap = swap->next;
	}
	return (i);
}
