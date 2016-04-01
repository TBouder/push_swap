/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_oct_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 15:49:50 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 23:51:50 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_put_precision_oct() function adjusts the precision before displaying
** the output.
*/

void	ft_put_precision_oct(t_flags *flags, long long local_pa)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	s = ft_itoa_base_ull(local_pa, 8);
	len = ft_strlen(s);
	while (flags->preci - len - flags->diaiz > 0)
	{
		(!flags->display) ? ft_putchar('0') : 0;
		flags->spaces_count++;
		flags->preci--;
		flags->preci_diff += 1;
	}
	if (local_pa == 0 && flags->preci != -1)
		(!flags->display) ? ft_putnbr_base_ull(local_pa, 8, 0) : 0;
	else if (local_pa != 0)
		(!flags->display) ? ft_putnbr_base_ull(local_pa, 8, 0) : 0;
	ft_strdel(&s);
}
