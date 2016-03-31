/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:45:38 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/31 11:27:31 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_swap	*ft_swapnew(int value, t_swap *prev, int activ)
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

void			ft_swapend(t_swap **swap, int value, int activ)
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

void	ft_push_front(t_swap *stack)
{
	t_swap	*end;

	while (stack->next)
	{
		if (stack->activ == 0)
		{
			end = stack;
			while (end)
			{
				if (end->activ == 1)
				{
					stack->activ = 1;
					stack->stack = end->stack;
					end->activ = 0;
					end->stack = 0;
				}
				else
					end = end->next;
			}
		}
		stack = stack->next;
	}
}
