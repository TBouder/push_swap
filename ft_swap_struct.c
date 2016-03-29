/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:45:38 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 23:58:25 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap		*ft_end(t_swap *swap)
{
	t_swap		*end;
	t_swap		*start;

	end = swap;
	start = swap;
	while (end->next)
		end = end->next;
	while (swap)
	{
		swap->end = end;
		swap->start = start;
		swap = swap->next;
	}
	return (swap);
}

static t_swap		*ft_swapnew(int value, t_swap *prev, int activ)
{
	t_swap	*swap;

	if (!(swap = (t_swap *)malloc(sizeof(t_swap))))
		return (NULL);
	swap->stack = value;
	swap->next = NULL;
	swap->prev = prev;
	swap->activ = activ;
	return (swap);
}

void				ft_swapend(t_swap **swap, int value, int activ)
{
	t_swap	*new_swap;
	t_swap	*start;
	t_swap	**tmp;

	new_swap = *swap;
	start = *swap;
	if (new_swap)
	{
		tmp = &new_swap;
		while (new_swap->next != NULL)
		{
			tmp = &new_swap;
			new_swap = new_swap->next;
		}
		new_swap->next = ft_swapnew(value, *tmp, activ);
	}
	else
		*swap = ft_swapnew(value, NULL, activ);
}
