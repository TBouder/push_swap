/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 13:47:53 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/05 15:35:11 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_success(t_swap *a, t_swap *b, t_flag flg)
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
		flg.color ? ft_printf("\n\nNumber of operations : {g}%d{0}\n", flg.cnt)
			: ft_printf("\n\nNumber of operations : %d\n", flg.cnt);
	else
		ft_putchar('\n');
	exit(EXIT_SUCCESS);
}

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	ft_exit_one_nb(t_swap *a, t_flag flg)
{
	ft_printf("A list with only one number is always ordered ...\n");
	if (flg.infos)
	{
		ft_putstr("\nEnding stack : ");
		ft_print_swap(a);
	}
	ft_putchar('\n');
	exit(EXIT_SUCCESS);
}

void	ft_exit_already_ordered(t_swap *a, t_flag flg)
{
	ft_printf("Your list is alreay ordered !\n");
	if (flg.infos)
	{
		ft_putstr("\nEnding stack : ");
		ft_print_swap(a);
	}
	ft_putchar('\n');
	exit(EXIT_SUCCESS);
}
