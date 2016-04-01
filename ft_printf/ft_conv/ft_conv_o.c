/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:29:36 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 23:52:08 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_o() function launchs the conversion for o specifier.
*/

int		ft_o(va_list pa, t_flags flag)
{
	char		*s;
	long long	lpa;
	long long	value;
	int			len;

	lpa = va_arg(pa, long);
	if (flag.l == 0)
		value = (lpa < 0) ? 4294967296 + lpa : lpa % 4294967296;
	else if (flag.l == 3)
		value = (lpa < 0) ? 65536 + lpa : lpa % 65536;
	else if (flag.l == 4)
		value = (lpa < 0) ? 256 + lpa : lpa % 256;
	else
		value = lpa;
	s = ft_itoa_base_ll(value, 8);
	len = ft_strlen(s);
	ft_before_o(&flag, len, 0, value);
	ft_put_precision_oct(&flag, value);
	ft_after_o(&flag, len);
	(flag.l == 0 && value == 0 && flag.preci == -1) ? len-- : 0;
	ft_strdel(&s);
	return (len + flag.spaces_count);
}

/*
** The ft_lo() function launchs the conversion for O specifier.
*/

int		ft_lo(va_list pa, t_flags flag)
{
	char		*s;
	long long	lpa;
	long long	value;
	int			len;

	lpa = va_arg(pa, long long);
	value = lpa;
	s = ft_itoa_base_ll(value, 8);
	len = ft_strlen(s);
	ft_strdel(&s);
	ft_before_o(&flag, len, 0, value);
	ft_put_precision_oct(&flag, value);
	ft_after_o(&flag, len);
	(flag.l == 0 && value == 0 && flag.preci == -1) ? len-- : 0;
	return (len + flag.spaces_count);
}
