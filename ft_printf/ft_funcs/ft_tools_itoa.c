/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 11:19:12 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/28 22:09:54 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_itoa_base() function converts the initial int representation by a
** string pointed to by n, according to the base.
*/

#include "../ft_printf.h"

static void			ft_convert_base(ULL n, int base, char *s,
						int *index)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (n < (ULL)base)
	{
		s[*index] = str[n];
		*index += 1;
	}
	else
	{
		ft_convert_base(n / base, base, s, index);
		ft_convert_base(n % base, base, s, index);
	}
}

static int			ft_nbrlen_bb(ULL n, int base)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char				*ft_itoa_base_ull(ULL n, int base)
{
	char	*s;
	int		len;
	int		k;

	k = 0;
	len = ft_nbrlen_bb(n, 10);
	s = ft_strnew(len + 1);
	ft_convert_base(n, base, s, &k);
	return (s);
}

char				*ft_itoa_base_ll(ULL n, int base)
{
	char	*s;
	int		len;
	int		k;

	k = 0;
	len = ft_nbrlen_bb(n, base);
	s = ft_strnew(len + 1);
	ft_convert_base(n, base, s, &k);
	return (s);
}

ULL					ft_atoi_ll(const char *str)
{
	ULL		result;
	int		sign;

	sign = 1;
	result = 0;
	while (*str >= '0' && *str <= '1')
		result = (result + *str++ - '0') * 10;
	return (result / 10 * sign);
}
