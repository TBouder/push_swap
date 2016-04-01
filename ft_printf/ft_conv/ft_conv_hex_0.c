/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hex_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:24:47 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 11:14:53 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_before_x_spaces() functions adds spaces before the output when
** the conditions are met.
*/

static void		ft_before_x_spaces(t_flags *flags, int v_len,
					long long local_pa)
{
	(flags->diaiz == 1) ? flags->spaces -= 2 : 0;
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

/*
** The ft_before_x_zero() functions adds zeros before the output when
** the conditions are met.
*/

static void		ft_before_x_zero(t_flags *flags, int v_len, long long value,
					int maj)
{
	(flags->diaiz == 1) ? flags->zero -= 2 : 0;
	(v_len < flags->preci) ? v_len += flags->preci - v_len : 0;
	if (maj == 1 && flags->diaiz == 1 && value != 0)
		(!flags->display) ? ft_putstr("0X") : 0;
	else if (maj == 0 && flags->diaiz == 1 && value != 0)
		(!flags->display) ? ft_putstr("0x") : 0;
	while (flags->zero-- - v_len > 0)
	{
		flags->spaces_count++;
		(!flags->display) ? ft_putchar('0') : 0;
	}
}

/*
** The ft_before_x() function is a launcher for the two functions above.
*/

void			ft_before_x(t_flags *flags, int v_len, long long value, int maj)
{
	if (flags->spaces && flags->spaces - v_len > 0)
		ft_before_x_spaces(flags, v_len, value);
	else if (flags->zero && flags->zero - v_len > 0)
	{
		ft_before_x_zero(flags, v_len, value, maj);
		maj = -1;
	}
	if (maj == 1 && flags->diaiz == 1 && value != 0)
		(!flags->display) ? ft_putstr("0X") : 0;
	else if (maj == 0 && flags->diaiz == 1 && value != 0)
		(!flags->display) ? ft_putstr("0x") : 0;
	(flags->diaiz == 1) && (value != 0) ? flags->spaces_count += 2 : 0;
}

/*
** The ft_after_hex() function adds spaces after the output when the conditions
** are met.
*/

void			ft_after_hex(t_flags *flags, int v_len)
{
	(flags->preci == -1) ? flags->spaces-- : 0;
	(flags->diaiz) ? flags->spaces += 2 : 0;
	if (flags->spaces + v_len + flags->preci_diff < 0)
	{
		while (flags->spaces++ + v_len + flags->preci_diff < 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar(' ') : 0;
		}
	}
}
