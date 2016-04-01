/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:28:47 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 12:49:10 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_c(va_list pa, t_flags flags)
{
	int		local_pa;

	if (flags.l == 1)
		return (ft_lc(pa, flags));
	local_pa = va_arg(pa, unsigned int);
	ft_before_c(&flags, 1);
	(!flags.display) ? ft_putchar(local_pa) : 0;
	ft_after_c(&flags, 1);
	return (1 + flags.spaces_count);
}

int		ft_lc(va_list pa, t_flags flags)
{
	wchar_t		local_pa;
	int			i;
	char		*bin;
	int			*nbr;
	int			ln;

	i = 0;
	ln = 0;
	local_pa = (wchar_t)va_arg(pa, int);
	if (local_pa > 55295 && local_pa < 57344)
		return (-1);
	ft_before_c(&flags, 1);
	bin = ft_itoa_base(local_pa, 2);
	nbr = ft_parse_binary(ft_atoi_ll(bin));
	ft_strdel(&bin);
	while (nbr[i] != -1)
	{
		nbr[i] = ft_binary_to_decimal(nbr[i]);
		(!flags.display) ? ft_putchar(nbr[i]) : 0;
		i++;
		ln++;
	}
	ft_after_c(&flags, ln);
	free(nbr);
	return (ln + flags.spaces_count);
}
