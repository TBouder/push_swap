/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:07:04 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 11:15:35 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_before_d_i_spaces() functions adds spaces before the output when
** the conditions are met.
*/

static void		ft_before_d_i_spaces(t_flags *flags, int v_len, long long value,
					int i)
{
	(value < 0) ? flags->spaces-- : 0;
	(v_len < flags->preci) ? v_len = flags->preci : 0;
	(flags->empty && flags->spaces > v_len && flags->preci <= 0) ? v_len++ : 0;
	(flags->plus == 1 && value < 0) ? flags->spaces++ : 0;
	(flags->plus == 1 && flags->preci == 0) ? v_len++ : 0;
	while (flags->spaces-- - v_len != 0)
	{
		flags->spaces_count++;
		(!flags->display) ? ft_putchar(' ') : 0;
	}
	if (i == 1)
	{
		if (flags->plus == 1 && value >= 0)
			(!flags->display) ? ft_putchar('+') : 0;
		(flags->plus == 1 && value >= 0) ? flags->spaces_count++ : 0;
	}
}

/*
** The ft_before_d_i_zero() functions adds zeros before the output when
** the conditions are met.
*/

static void		ft_before_d_i_zero(t_flags *flags, int v_len, long long value,
					int i)
{
	(value < 0 && !flags->display) ? ft_putchar('-') : 0;
	(value < 0) ? flags->temp = 1 : 0;
	(value < 0) ? flags->zero-- : 0;
	(flags->plus == 1 && value < 0) ? flags->zero++ : 0;
	(flags->plus == 1) ? v_len++ : 0;
	if (flags->empty == 1 && value >= 0)
	{
		v_len++;
		(value == 0) ? flags->spaces_count++ : 0;
		(value == 0 && !flags->display) ? ft_putchar(' ') : 0;
	}
	while (flags->zero-- - v_len != 0)
	{
		flags->spaces_count++;
		(!flags->display) ? ft_putchar('0') : 0;
	}
	if (i == 1)
	{
		if (flags->plus == 1 && value >= 0)
			(!flags->display) ? ft_putchar('+') : 0;
		(flags->plus == 1 && value >= 0) ? flags->spaces_count++ : 0;
	}
}

/*
** The ft_before_d_i() function is a launcher for the two functions above.
*/

void			ft_before_d_i(t_flags *flags, int v_len, long long value)
{
	int		i;

	i = 0;
	(flags->preci != 0 && flags->zero != 0) ? flags->spaces = flags->zero : 0;
	(flags->preci > v_len) ? v_len = flags->preci : 0;
	if (flags->plus == 1 && flags->spaces > v_len)
		i = 1;
	else
	{
		if (flags->plus == 1 && value >= 0)
			(!flags->display) ? ft_putchar('+') : 0;
		(flags->plus == 1 && value >= 0) ? flags->spaces_count++ : 0;
	}
	(flags->preci > 0 && flags->preci > v_len) ? v_len = flags->preci : 0;
	if (flags->preci > 0 && flags->spaces > flags->preci && flags->empty == 1)
		v_len++;
	if (flags->preci > 0 && flags->spaces > flags->preci && flags->plus == 1)
		v_len++;
	(flags->preci == -1 && value == 0) ? v_len-- : 0;
	if (flags->spaces && flags->spaces - v_len > 0)
		ft_before_d_i_spaces(flags, v_len, value, i);
	else if (flags->zero && flags->zero - v_len > 0)
		ft_before_d_i_zero(flags, v_len, value, i);
}

/*
** The ft_after_d_i() function adds spaces after the output when the conditions
** are met.
*/

void			ft_after_d_i(t_flags *flags, int v_len, long long local_pa)
{
	(local_pa < 0) ? v_len++ : 0;
	(flags->plus == 1 && flags->minus == 1 && (flags->spaces > 0 ||
		local_pa > 0)) ? v_len++ : 0;
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
