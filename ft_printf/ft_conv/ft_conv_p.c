/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:31:32 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 23:54:32 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_before(t_flags *flags, int v_len)
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
}

void	ft_middle(t_flags *flags, int v_len)
{
	if (flags->zero && flags->zero - v_len > 0)
	{
		while (flags->zero-- - v_len != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar('0') : 0;
		}
	}
	else if (flags->preci && flags->preci - v_len + 2 > 0)
	{
		while (flags->preci-- - v_len + 2 != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar('0') : 0;
		}
	}
}

void	ft_after(t_flags *flags, int v_len)
{
	if (flags->spaces + v_len < 0)
	{
		flags->spaces_count = 0;
		while (flags->spaces++ + v_len != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar(' ') : 0;
		}
	}
}

void	ft_after_null(t_flags *flags, int v_len)
{
	if (flags->spaces + v_len < 0)
	{
		flags->spaces_count = 0;
		while (flags->spaces++ + v_len != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar(' ') : 0;
		}
	}
	else if (flags->zero && flags->zero - v_len > 0)
	{
		while (flags->zero-- - v_len != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar('0') : 0;
		}
	}
	else if (flags->preci && flags->preci - 1 > 0)
	{
		while (flags->preci-- - 1 != 0)
		{
			flags->spaces_count++;
			(!flags->display) ? ft_putchar('0') : 0;
		}
	}
}

int		ft_p(va_list pa, t_flags flags)
{
	int		*local_pa;
	int		len;

	local_pa = (va_arg(pa, int*));
	if (local_pa == NULL)
	{
		len = (flags.preci == -1) ? 2 : 3;
		ft_before(&flags, len);
		(!flags.display) ? ft_putstr("0x") : 0;
		(len == 3 && (!flags.display)) ? ft_putstr("0") : 0;
		ft_after_null(&flags, len);
		return (len + flags.spaces_count);
	}
	ft_before(&flags, ft_printf("%!lx", local_pa) + 2);
	(!flags.display) ? ft_putstr("0x") : 0;
	ft_middle(&flags, ft_printf("%!lx", local_pa) + 2);
	(!flags.display) ? ft_printf("%lx", local_pa) : 0;
	ft_after(&flags, ft_printf("%!lx", local_pa) + 2);
	return (ft_printf("%!lx", local_pa) + flags.spaces_count + 2);
}
