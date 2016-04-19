/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 13:47:53 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/19 12:44:00 by tbouder          ###   ########.fr       */
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
		flg.color ? ft_printf("Number of operations : {g}%d{0}\n", flg.cnt)
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

void	ft_usage(char *str)
{
	ft_putstr_fd("usage : ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" [-vcoia] [n1 n2 ...]", 2);
	ft_putendl_fd("\tn1, n2, etc.: numbers between -2147483648 and 2147483647"
		, 2);
	ft_putendl_fd("\t-v : Enable verbose mode", 2);
	ft_putendl_fd("\t-c : Enable color mode", 2);
	ft_putendl_fd("\t-o : Display the number of operations", 2);
	ft_putendl_fd("\t-i : Display starting and ending 'a' stack", 2);
	ft_putendl_fd("\t-a : Enable all the previous tags", 2);
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
