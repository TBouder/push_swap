/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:30:01 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/04 14:14:42 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
** Bonus
** - -v for verbose mode
** - -c for color mode
** - -o for number of operation
*/

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

static void		ft_extract_stack(char **str, int len, t_swap **a, t_flag *flg)
{
	long	value;
	int		flags;
	int		i;

	flg->verbose = 0;
	flg->color = 0;
	i = 1;
	flags = 0;
	while (ft_strcmp(str[i], "-v") == 0 || ft_strcmp(str[i], "-c") == 0
		|| ft_strcmp(str[i], "-o") == 0 || ft_strcmp(str[i], "-i") == 0)
	{
		ft_strcmp(str[i], "-v") == 0 ? flg->verbose = 1 : 0;
		ft_strcmp(str[i], "-c") == 0 ? flg->color = 1 : 0;
		ft_strcmp(str[i], "-o") == 0 ? flg->ope = 1 : 0;
		ft_strcmp(str[i], "-i") == 0 ? flg->infos = 1 : 0;
		flags += 1;
		i++;
	}
	while (len > 0 + flags)
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
	t_flag	flg;
	t_swap	*a;
	t_swap	*b;

	a = NULL;
	b = NULL;
	i = ac - 1;
	if (ac < 2)
		ft_error();
	else
	{
		ft_extract_stack(av, i, &a, &flg);
		if (flg.verbose && i == 1)
			ft_error();
		ft_check_duplicates(a);
		ft_init_b(i - flg.verbose, &b);
		ft_end(a);
		ft_end(b);

		ft_putstr("s : ");ft_print_swap(a);ft_putchar('\n');ft_putchar('\n');
		ft_launcher(a, b, flg);
	}
	return (0);
}
