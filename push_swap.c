/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:30:01 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 14:22:51 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(int *a, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putnbr(a[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int		*ft_extract_a(char **str, int len)
{
	int		*a;
	int		j;
	long	value;

	j = 0;
	if (!(a = (int *)malloc(sizeof(int) * len)))
		ft_error();
	while (len != 0)
	{
		value = ft_atoi_swap(str[len]);
		ft_check_min_man(value);
		a[j] = value;
		len--;
		j++;
	}
	return (a);
}

int		main(int ac, char **av)
{
	int		i;
	int		*a;

	i = ac - 1;
	if (ac == 0)
		ft_error();
	else
	{
		a = ft_extract_a(av, i);
		ft_check_duplicates(a, i);
		ft_launcher(&a, i);
		// ft_print(a, i);
	}
	return (0);
}
