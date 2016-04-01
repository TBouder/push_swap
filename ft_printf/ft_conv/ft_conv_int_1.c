/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:23:55 by Tbouder           #+#    #+#             */
/*   Updated: 2016/03/28 17:18:01 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** The ft_put_preci_int() function adjusts the precision before displaying
** the output.
*/

static void		ft_preci_int_l(t_flags *flags, long long lpa)
{
	if (lpa < (long)-2147483648)
		(!flags->display) ? ft_putnbr_ull(-lpa) : 0;
	else if (!(flags->preci == -1 && lpa == 0))
		(!flags->display) ? ft_putnbr_ll(lpa) : 0;
	else
		flags->spaces_count--;
}

static void		ft_preci_int(t_flags *flags, long long lpa)
{
	if (!(flags->preci == -1 && lpa == 0))
		(!flags->display) ? ft_putnbr_base(lpa, 10, 0) : 0;
	else
		flags->spaces_count--;
}

void			ft_put_preci_int(t_flags *flags, long long lpa, int id)
{
	int		len;

	len = (ft_nbrlen_ll(lpa) == 0) ? 1 : ft_nbrlen_ll(lpa);
	if (lpa < 0 && flags->temp == 0)
		(!flags->display) ? ft_putchar('-') : 0;
	while (flags->preci - len > 0)
	{
		(!flags->display) ? ft_putchar('0') : 0;
		flags->spaces_count += 1;
		flags->preci -= 1;
		flags->preci_diff += 1;
	}
	(lpa < 0) ? lpa = -lpa : 0;
	if ((flags->l == 0 || flags->l == 3 || flags->l == 4) && id == 0)
		ft_preci_int(flags, lpa);
	if ((flags->l == 1 || flags->l == 5 || flags->l == 6) && id == 0)
		ft_preci_int_l(flags, lpa);
	if (flags->l == 2 || id == 1)
		(!flags->display) ? ft_putnbr_ull(lpa) : 0;
}
