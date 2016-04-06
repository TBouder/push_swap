/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:05:00 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/05 16:21:39 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_z(t_swap *swap)
{
	t_swap	*tmp;

	tmp = swap->end;
	while (tmp && tmp->activ == 0 && tmp->prev)
		tmp = tmp->prev;
	return (tmp->stack);
}

int		ft_y(t_swap *swap)
{
	t_swap	*tmp;

	tmp = swap->end;
	while (tmp && tmp->activ == 0 && tmp->prev)
		tmp = tmp->prev;
	if (tmp != NULL && tmp->prev)
		tmp = tmp->prev;
	return (tmp->stack);
}

int		ft_launcher(t_swap *a, t_swap *b, t_flag *flg)
{
	if (ft_z(a) < ft_y(a) && ft_z(a) < a->stack)
		ft_rpa_b(a, b, flg);
	else if (ft_z(a) < ft_y(a) && ft_z(a) > a->stack)
		!ft_swaprev(a) ? ft_rrr_a(a, b, flg) : ft_rr_a(a, b, flg);
	else if (ft_z(a) > ft_y(a))
		ft_rs_a(a, b, flg);
	else if (ft_z(b) < ft_y(b))
		ft_rs_b(a, b, flg);
	return (1);
}
