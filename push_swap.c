/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:30:01 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 23:51:28 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putchar('\n');
}

void	ft_extract_stack(char **str, int len, t_swap **a)
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

void	ft_init_b(int len, t_swap **b)
{
	while (len > 0)
	{
		ft_swapend(b, 0, 0);
		len--;
	}
}

int		main(int ac, char **av)
{
	int		i;
	t_swap	*a;
	t_swap	*b;

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
		ft_putstr("s : ");ft_print_swap(a);ft_putchar('\n');
		ft_launcher(a, b);
	}
	return (0);
}
