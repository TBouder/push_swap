/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:03:11 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 15:24:46 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error()
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int		ft_atoi_swap(const char *str)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	if (ft_strlen(str) == 0 || (*str < 32 && !ft_isspace(*str)))
		return (0);
	while (*str <= 32)
		str++;
	if ((*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isnumber(*str))
		result = (result + *str++ - '0') * 10;
	if (!(ft_isnumber(*str)) && *str != '\0')
		ft_error();
	return (result / 10 * sign);
}

void	ft_check_min_man(long value)
{
	if (value > 2147483647 || value <= -2147483648)
		ft_error();
}

void	ft_check_duplicates(t_swap *a)
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
