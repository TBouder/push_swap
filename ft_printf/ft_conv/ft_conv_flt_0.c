/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_flt_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 19:45:11 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 11:13:59 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_before_f_spaces(t_flags *flags, int v_len, double local_pa)
{
	(v_len < flags->preci) ? v_len += flags->preci - v_len : 0;
	while (flags->spaces-- - v_len > 0)
	{
		flags->spaces_count++;
		(!flags->display) ? ft_putchar(' ') : 0;
	}
	if (flags->preci == -1 && local_pa == 0)
		(!flags->display) ? ft_putchar(' ') : 0;
	(flags->preci == -1) && (local_pa == 0) ? flags->spaces_count++ : 0;
}

static void		ft_before_f_zero(t_flags *flags, int v_len)
{
	while (flags->zero-- - v_len > 0)
	{
		flags->spaces_count++;
		(!flags->display) ? ft_putchar('0') : 0;
	}
}

void			ft_before_f(t_flags *flags, int v_len, double local_pa)
{
	if (flags->spaces && flags->spaces - v_len > 0)
		ft_before_f_spaces(flags, v_len, local_pa);
	else if (flags->zero && flags->zero - v_len > 0)
		ft_before_f_zero(flags, v_len);
}

void			ft_after_f(t_flags *flags, int v_len)
{
	if (flags->spaces + v_len + flags->preci_diff < 0)
	{
		while (flags->spaces + v_len + flags->preci_diff < 0)
		{
			flags->spaces++;
			flags->spaces_count++;
			(!flags->display) ? ft_putchar(' ') : 0;
		}
	}
}
