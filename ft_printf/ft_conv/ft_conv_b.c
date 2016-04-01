/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 10:26:42 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 14:08:38 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_b(va_list pa, t_flags flag)
{
	int			lpa;
	int			sign;

	sign = 0;
	lpa = va_arg(pa, int);
	if (lpa < 0)
	{
		sign = 1;
		lpa = -lpa;
		(!flag.display) ? ft_putchar('-') : 0;
	}
	(!flag.display) ? ft_putnbr_base(lpa, 2, 0) : 0;
	return (ft_nbrlen_base(lpa, 2) + sign);
}

int		ft_lb(va_list pa, t_flags flag)
{
	wchar_t		lpa;
	int			*nbr;
	char		*bin;
	int			i;
	int			len;

	i = 0;
	len = 0;
	lpa = (wchar_t)va_arg(pa, int);
	bin = ft_itoa_base(lpa, 2);
	nbr = ft_parse_binary(ft_atoi_ll(bin));
	while (nbr[i] != -1 && i < 4)
	{
		(!flag.display) ? ft_putnbr(nbr[i]) : 0;
		len += ft_nbrlen_base(nbr[i], 10);
		(!flag.display) ? ft_putchar(' ') : 0;
		i++;
	}
	free(nbr);
	ft_strdel(&bin);
	return (len + i - 1);
}
