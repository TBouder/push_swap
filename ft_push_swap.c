/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:30:01 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/01 13:39:48 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_swap	*ft_end(t_swap *swap)
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

static void		ft_extract_stack(char **str, int len, t_swap **a)
{
	long	value;

	while (len > 0)
	{
		value = ft_atoi_swap(str[len]);
		ft_check_min_man(value);
		ft_swapend(a, value, 1);
		len--;
	}
}

static void		ft_init_b(int len, t_swap **b)
{
	while (len > 0)
	{
		ft_swapend(b, 0, 0);
		len--;
	}
}

static void		ft_check_duplicates(t_swap *a)
{
	t_swap	*i;

	while (a)
	{
		i = a->next;
		while (i)
		{
			if (a->stack == i->stack)
				ft_error();
			i = i->next;
		}
		a = a->next;
	}
}

int		main(int ac, char **av)
{
	int		i;
	t_swap	*a;
	t_swap	*b;

	a = NULL;
	b = NULL;
	i = ac - 1;
	if (ac < 2)
		ft_error();
	else
	{
		ft_extract_stack(av, i, &a);
		ft_check_duplicates(a);
		ft_init_b(i, &b);
		ft_end(a);
		ft_end(b);

		ft_putstr("s : ");ft_print_swap(a);ft_putchar('\n');ft_putchar('\n');
		ft_launcher(a, b);
	}
	return (0);
}
