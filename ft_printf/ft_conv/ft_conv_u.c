/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:31:02 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 23:52:24 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_u(va_list pa, t_flags flag)
{
	char		*s;
	long long	lpa;
	long long	value;
	int			len;

	flag.l == 0 || flag.l == 4 ? lpa = va_arg(pa, unsigned int) : 0;
	flag.l == 1 || flag.l == 2 || flag.l == 3 || flag.l == 5 || flag.l == 6
		? lpa = va_arg(pa, long) : 0;
	value = (flag.l == 0 && lpa < 0) ? 4294967296 + lpa : lpa;
	value = (flag.l == 4) ? lpa % 256 : lpa;
	s = ft_itoa_base_ull(value, 10);
	len = ft_strlen(s);
	ft_before_u(&flag, len, value);
	ft_put_preci_uni(&flag, value);
	ft_after_u(&flag, len);
	(flag.l == 0 && value == 0 && flag.preci == -1) ? len-- : 0;
	ft_strdel(&s);
	return (len + flag.spaces_count);
}

int		ft_lu(va_list pa, t_flags flag)
{
	char		*s;
	long long	local_pa;
	int			len;

	local_pa = va_arg(pa, long long);
	s = ft_itoa_base_ull(local_pa, 10);
	len = ft_strlen(s);
	ft_before_u(&flag, len, local_pa);
	ft_put_preci_uni(&flag, local_pa);
	ft_after_u(&flag, len);
	ft_strdel(&s);
	return (len + flag.spaces_count);
}
