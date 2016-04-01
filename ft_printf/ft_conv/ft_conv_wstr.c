/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:00:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/28 22:54:24 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_conv_ws_case1(t_flags flags)
{
	int		ln;

	ln = flags.zero;
	ft_before_str(&flags, 0);
	ft_put_precision_str(flags, NULL, -1);
	ft_after_str(&flags, 0);
	ln = (flags.zero_base != 0) ? flags.zero_base : flags.spaces_count;
	return (ln);
}

static int	ft_conv_ws_case3(t_flags flags, wchar_t *lpa, int i)
{
	int		j;
	int		ln;
	char	*bin;
	int		*nbr;

	ln = flags.preci != 0 ? ft_wstrlen_flags(lpa, flags) : ft_wstrlen(lpa);
	ft_before_str(&flags, ln);
	while (lpa[i])
	{
		j = 0;
		bin = ft_itoa_base(lpa[i], 2);
		nbr = ft_parse_binary(ft_atoi_ll(bin));
		ft_strdel(&bin);
		while (nbr[j] != -1)
		{
			nbr[j] = ft_binary_to_decimal(nbr[j]);
			(!flags.display) ? ft_putchar(nbr[j]) : 0;
			j++;
		}
		i++;
		free(nbr);
	}
	ft_after_str(&flags, ln);
	return (ln + flags.spaces_count);
}

static int	ft_conv_ws_case4(t_flags flags, wchar_t *lpa, int i, int lnn)
{
	int		j;
	int		ln;
	char	*bin;
	int		*nbr;

	ln = flags.preci != 0 ? ft_wstrlen_flags(lpa, flags) : ft_wstrlen(lpa);
	ft_before_str(&flags, ln);
	while (lpa[i] && lnn < flags.preci)
	{
		j = 0;
		bin = ft_itoa_base(lpa[i], 2);
		nbr = ft_parse_binary(ft_atoi_ll(bin));
		lnn += ft_wchar_len(nbr);
		ft_strdel(&bin);
		while (nbr[j] != -1 && lnn <= flags.preci)
		{
			nbr[j] = ft_binary_to_decimal(nbr[j]);
			(!flags.display) ? ft_putchar(nbr[j]) : 0;
			j++;
		}
		i++;
	}
	free(nbr);
	ft_after_str(&flags, ln);
	return (ln + flags.spaces_count);
}

int			ft_ls(va_list pa, t_flags flags)
{
	wchar_t		*lpa;

	lpa = (wchar_t *)va_arg(pa, char *);
	if (flags.preci == -1)
		return (ft_conv_ws_case1(flags));
	else if (lpa == NULL && flags.preci >= 0)
		return (ft_conv_s_case2(flags));
	else if (lpa != NULL && flags.preci == 0)
		return (ft_conv_ws_case3(flags, lpa, 0));
	else
		return (ft_conv_ws_case4(flags, lpa, 0, 0));
}
