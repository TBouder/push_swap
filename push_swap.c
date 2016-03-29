/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:30:01 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 17:21:11 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_extract_stack(char **str, int len, t_swap **a)
{
	long	value;

	while (len > 0)
	{
		value = ft_atoi_swap(str[len]);
		ft_check_min_man(value);
		ft_swapend(a, value);
		len--;
	}
}

void	ft_print_swap(t_swap *a)
{
	if (a && a->next)
	{
		while (a->next)
		{
			ft_putnbr(a->stack);
			ft_putchar(' ');
			a = a->next;
			if (a->next == NULL)
				ft_putnbr(a->stack);
		}
	}
	else if (a && a->next == NULL)
		ft_putnbr(a->stack);
	ft_putchar('\n');
}

int		main(int ac, char **av)
{
	int		i;
	t_swap	*a;

	i = ac - 1;
	if (ac == 0)
		ft_error();
	else
	{
		ft_extract_stack(av, i, &a);
		ft_check_duplicates(a);
		ft_end(a);
		ft_putstr("a : ");ft_print_swap(a);
		ft_launcher(&a);
		ft_putstr("a : ");ft_print_swap(a);
	}
	return (0);
}
