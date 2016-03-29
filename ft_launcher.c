/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:05:00 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/30 00:04:50 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	*ft_last_activ(t_swap *swap)
{
	t_swap	*tmp;

	tmp = swap->end;
	while (tmp->activ == 0)
		tmp = tmp->prev;
	return (tmp);
}

t_swap	*ft_a_last_activ(t_swap *swap)
{
	t_swap	*tmp;

	tmp = swap->end;
	while (tmp->activ == 0)
		tmp = tmp->prev;
	if (tmp != NULL)
		tmp = tmp->prev;
	return (tmp);
}

void	ft_launcher(t_swap *a, t_swap *b)
{
	int		i;

	i = 0;
	if (ft_last_activ(a) > ft_a_last_activ(a) && ft_a_last_activ(a) != NULL)
	{
		i++;
		ft_putstr("sa ");
		sa(a);
	}
	ft_putchar('\n');
	ft_putstr("a : ");ft_print_swap(a);
	ft_putstr("b : ");ft_print_swap(b);

}
