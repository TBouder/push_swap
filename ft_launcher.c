/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:05:00 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/30 19:22:11 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_launcher(t_swap *a, t_swap *b)
{
	int		i;

	i = 0;
	while ((ft_is_sorted(a) == 0 || ft_is_null(b) == 0) && i < 50)
	{
		if (last(a) > n_last(a))
		{
			ft_putstr("sa : ");
			sa(a);
			ft_putstr("\t");ft_print_swap(a);ft_putstr("\t||\t");ft_print_swap(b);ft_putchar('\n');
		}
		if (last(b) < n_last(b))
		{
			ft_putstr("sb : ");
			sb(b);
			ft_putstr("\t");ft_print_swap(a);ft_putstr("\t||\t");ft_print_swap(b);ft_putchar('\n');
		}


		if ((last(a) < n_last(a)) && (last(a) > a->stack))
		{
			ft_putstr("ra : ");
			ra(a);
			ft_putstr("\t");ft_print_swap(a);ft_putstr("\t||\t");ft_print_swap(b);ft_putchar('\n');
		}
		if ((last(a) < n_last(a)) && (a->stack < a->next->stack))
		{
			ft_putstr("ra : ");
			ra(a);
			ft_putstr("\t");ft_print_swap(a);ft_putstr("\t||\t");ft_print_swap(b);ft_putchar('\n');
		}
		if ((last(a) < n_last(a)) && (last(a) < a->stack))
		{

			ft_putstr("ra : ");
			ra(a);
			ft_putstr("\t");ft_print_swap(a);ft_putstr("\t||\t");ft_print_swap(b);ft_putchar('\n');
			ft_putstr("sb : ");
			sb(b);
			ft_putstr("\t");ft_print_swap(a);ft_putstr("\t||\t");ft_print_swap(b);ft_putchar('\n');
			ft_putstr("pb : ");
			pb(b, a);
			ft_putstr("\t");ft_print_swap(a);ft_putstr("\t||\t");ft_print_swap(b);ft_putchar('\n');
		}




		if ((last(a) < n_last(a)) && (last(a) < a->stack) && (ft_is_null(b)))
		{
			ft_putstr("pb : ");
			pb(b, a);
			ft_putstr("\t");ft_print_swap(a);ft_putstr("\t||\t");ft_print_swap(b);ft_putchar('\n');
		}

		if ((last(a) < n_last(a)) && (last(a) < a->stack) && (last(b) < last(a)))
		{
			ft_putstr("pb : ");
			pb(b, a);
			ft_putstr("\t");ft_print_swap(a);ft_putstr("\t||\t");ft_print_swap(b);ft_putchar('\n');
		}

		if ((last(a) < n_last(a)) && (last(a) < a->stack) && (last(b) > last(a)))
		{
			ft_putstr("pb : ");
			pb(b, a);
			ft_putstr("\t");ft_print_swap(a);ft_putstr("\t||\t");ft_print_swap(b);ft_putchar('\n');
		}

		// if ((last(a) < n_last(a)) && (last(a) < a->stack) && ((last(a) > last(b))))
		// {
		// 	ft_putstr("pb : ");
		// 	pb(b, a);
		// 	ft_putstr("\t");ft_print_swap(a);ft_putstr("\t||\t");ft_print_swap(b);ft_putchar('\n');
		// }
		// if ((last(b) < last(a)) && (last(b) > a->stack))
		// {
		// 	ft_putstr("pa : ");
		// 	pa(a, b);
		// 	ft_putstr("\t");ft_print_swap(a);ft_putstr("\t||\t");ft_print_swap(b);ft_putchar('\n');
		// }
		//
		//
		// if ((last(a) < n_last(a)) && (last(a) > a->stack))
		// {
		// 	ft_putstr("ra : ");
		// 	ra(a);
		// 	ft_putstr("\t");ft_print_swap(a);ft_putstr("\t||\t");ft_print_swap(b);ft_putchar('\n');
		// }

		i++;
	}



	ft_putchar('\n');ft_putchar('\n');

	ft_putstr("a : ");ft_print_swap(a);ft_putstr("\t||\tb : ");ft_print_swap(b);ft_putchar('\n');
	ft_putstr("i : ");ft_nbrendl(i);

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
