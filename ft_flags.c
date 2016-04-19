/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 10:14:47 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/19 11:33:24 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
}

void	ft_print_infos(t_swap *a)
{
	ft_putstr("Starting stack : ");
	ft_print_swap(a);
	ft_putendl("\n");
}

void	ft_flag_v(t_swap *a, t_swap *b)
{
	ft_printf("Stack a :\t");
	ft_print_swap(a);
	ft_putchar('\n');
	ft_printf("Stack b :\t");
	ft_print_swap(b);
	ft_putchar('\n');
}

void	ft_init_flag(t_flag *flg)
{
	flg->verbose = 0;
	flg->color = 0;
	flg->ope = 0;
	flg->infos = 0;
	flg->total_mod = 0;
	flg->cnt = 0;
	flg->prev = -1;
	flg->display = 0;
}
