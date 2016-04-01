/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hex_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:20:09 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 23:52:33 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_put_preci_hex() function adjusts the precision before displaying
** the output.
*/

void	ft_put_preci_hex(t_flags *flags, long long local_pa, int maj, int flag)
{
	char	*s;
	int		len;

	s = ft_itoa_base(local_pa, 16);
	len = ft_strlen(s);
	while (flags->preci - len > 0)
	{
		(!flags->display) ? ft_putchar('0') : 0;
		flags->spaces_count += 1;
		flags->preci -= 1;
		flags->preci_diff += 1;
	}
	if (s[0] == '0' && flags->preci != -1 && flag == 0)
		(!flags->display) ? ft_putnbr_base_ull(local_pa, 16, maj) : 0;
	else if (s[0] != '0' || flag != 0)
		(!flags->display) ? ft_putnbr_base_ull(local_pa, 16, maj) : 0;
	ft_strdel(&s);
}
