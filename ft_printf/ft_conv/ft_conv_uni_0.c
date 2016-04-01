/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uni_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:44:17 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/29 11:16:30 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_before_u_spaces() functions adds spaces before the output when
** the conditions are met.
*/

static void		ft_before_u_spaces(t_flags *flags, int v_len,
					long long local_pa)
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

/*
** The ft_before_u_zero() functions adds zeros before the output when
** the conditions are met.
*/

static void		ft_before_u_zero(t_flags *flags, int v_len)
{
	while (flags->zero-- - v_len > 0)
	{
		flags->spaces_count++;
		(!flags->display) ? ft_putchar('0') : 0;
	}
}

/*
** The ft_before_u() function is a launcher for the two functions above.
*/

void			ft_before_u(t_flags *flags, int v_len, long long local_pa)
{
	if (flags->spaces && flags->spaces - v_len > 0)
		ft_before_u_spaces(flags, v_len, local_pa);
	else if (flags->zero && flags->zero - v_len > 0)
		ft_before_u_zero(flags, v_len);
}

/*
** The ft_after_u() function adds spaces after the output when the conditions
** are met.
*/

void			ft_after_u(t_flags *flags, int v_len)
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
