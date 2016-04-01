/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:34:22 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/01 15:11:45 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	setlocale(LC_ALL, "en_US.UTF-8");

	int	i;
	// int	j;

	// ft_putchar(231);
	// ft_putchar(177);
	// ft_putchar(178);

	i = ft_printf("Bonjour, %C, %d\n", L'米', 42);
	// ft_printf("\n\n\n");
	// j = printf("Bonjour, %C, %d\n", 57343, 42);
	// printf("\n%d vs %d\n", i, j);


	return (0);
}
