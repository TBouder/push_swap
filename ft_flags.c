/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 10:14:47 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/04 14:25:30 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_success(t_swap *a, t_swap *b, int *i, t_flag flg)
{
	if (flg.infos)
	{
		ft_putstr("\n\nEnding stack : ");
		ft_print_swap(a);
	}
	a = NULL;
	b = NULL;
	free(a);
	free(b);
	if (flg.ope)
		flg.color ? ft_printf("\n\nNumber of operations : {g}%d{0}\n", *i)
			: ft_printf("\n\nNumber of operations : %d\n", *i);
	else
		ft_putchar('\n');
	exit(EXIT_SUCCESS);
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
