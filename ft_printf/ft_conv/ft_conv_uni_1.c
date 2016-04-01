/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uni_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:48:44 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 23:52:28 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_put_preci_uni() function adjusts the precision before displaying
** the output.
*/

void	ft_put_preci_uni(t_flags *flags, long long local_pa)
{
	int		len;
	int		i;

	i = 0;
	len = (ft_nbrlen_ll(local_pa) == 0) ? 1 : ft_nbrlen_ll(local_pa);
	while (flags->preci - len - flags->diaiz > 0)
	{
		(!flags->display) ? ft_putchar('0') : 0;
		flags->spaces_count++;
		flags->preci--;
		flags->preci_diff++;
	}
	if (local_pa == 0 && flags->preci != -1)
		(!flags->display) ? ft_putnbr_base_ull(local_pa, 10, 0) : 0;
	else if (local_pa != 0)
		(!flags->display) ? ft_putnbr_base_ull(local_pa, 10, 0) : 0;
}
