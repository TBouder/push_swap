/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:26:22 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 11:11:18 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_d_i(va_list pa, t_flags flag)
{
	long long	lpa;
	int			space;
	int			len;
	int			sign;

	flag.l == 0 ? lpa = va_arg(pa, int) : 0;
	flag.l == 3 ? lpa = (short)va_arg(pa, int) : 0;
	flag.l == 4 ? lpa = (char)va_arg(pa, int) : 0;
	flag.l != 0 && flag.l != 3 && flag.l != 4 ? lpa = va_arg(pa, long) : 0;
	(flag.empty == 1 && lpa > 0 && (!flag.display)) ? ft_putchar(' ') : 0;
	space = (flag.empty == 1) && (lpa > 0) ? 1 : 0;
	sign = (lpa < 0) ? 1 : 0;
	len = (ft_nbrlen_ll(lpa) == 0) ? 1 : ft_nbrlen_ll(lpa);
	ft_before_d_i(&flag, len, lpa);
	ft_put_preci_int(&flag, lpa, 0);
	ft_after_d_i(&flag, len, lpa);
	return (len + flag.spaces_count + sign + space);
}

int		ft_ld(va_list pa, t_flags flag)
{
	long long	lpa;
	int			sign;
	int			space;
	int			len;

	lpa = va_arg(pa, long);
	(flag.empty == 1 && lpa > 0 && (!flag.display)) ? ft_putchar(' ') : 0;
	space = (flag.empty == 1) && (lpa > 0) ? 1 : 0;
	sign = (lpa < 0) ? 1 : 0;
	len = (ft_nbrlen_ll(lpa) == 0) ? 1 : ft_nbrlen_ll(lpa);
	ft_before_d_i(&flag, len, lpa);
	ft_put_preci_int(&flag, lpa, 1);
	ft_after_d_i(&flag, len, lpa);
	return (len + flag.spaces_count + sign + space);
}
