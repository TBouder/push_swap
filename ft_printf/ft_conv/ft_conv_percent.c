/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:23:27 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 23:54:07 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_before() function adds spaces or zeros before the output if needed.
*/

static void		ft_before(t_flags *flags, int v_len)
{
	flags->spaces_count = 0;
	if (flags->spaces && flags->spaces - v_len > 0)
	{
		while (flags->spaces-- - v_len != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar(' ') : 0;
		}
	}
	else if (flags->spaces == 0 && flags->zero != 0)
	{
		while (flags->zero-- - v_len != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar('0') : 0;
		}
	}
}

/*
** The ft_after() function adds spaces after the output when the conditions
** are met.
*/

static void		ft_after(t_flags *flags, int v_len)
{
	if (flags->spaces + v_len < 0)
	{
		while (flags->spaces++ + v_len != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar(' ') : 0;
		}
	}
}

/*
** The ft_conv_percent() function launchs the conversion for % specifier.
*/

int				ft_conv_percent(t_flags flags)
{
	ft_before(&flags, ft_nbrlen(1));
	(!flags.display) ? ft_putchar('%') : 0;
	ft_after(&flags, ft_nbrlen(1));
	return (1 + flags.spaces_count);
}

/*
** The ft_conv_char() function launchs the conversion for no specifier.
*/

int				ft_conv_char(t_flags flags, char c)
{
	ft_before(&flags, ft_nbrlen(1));
	(!flags.display) ? ft_putchar(c) : 0;
	ft_after(&flags, ft_nbrlen(1));
	return (1 + flags.spaces_count);
}
