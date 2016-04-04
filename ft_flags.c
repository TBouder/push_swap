/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 10:14:47 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/04 10:15:35 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_flag_v(t_swap *a, t_swap *b)
{
	ft_printf("Stack a :\t");
	ft_print_swap(a);
	ft_putchar('\n');
	ft_printf("Stack b :\t");
	ft_print_swap(b);
	ft_putchar('\n');
}
