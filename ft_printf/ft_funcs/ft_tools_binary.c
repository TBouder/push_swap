/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:06:35 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/28 22:53:22 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** Helper because of the norme
*/

static int		*ft_parse_binary_helper(long long b, int *nbr)
{
	nbr[3] = 10000000 + (b % 1000000);
	nbr[2] = 10000000 + (b / 1000000 % 1000000);
	nbr[1] = 10000000 + (b / 1000000 / 1000000 % 1000000);
	nbr[0] = 11110000 + (b / 1000000 / 1000000 / 1000000 % 1000000);
	return (nbr);
}

/*
** Divides a unique binary in 1,2,3 or 4 parts.
*/

int				*ft_parse_binary(long long b)
{
	int		*nbr;
	int		i;

	i = 0;
	if (!(nbr = (int *)malloc(sizeof(int) * 4)))
		return (NULL);
	while (i < 4)
		nbr[i++] = -1;
	if (ft_nbrlen_base(b, 10) < 8)
		nbr[0] = b;
	else if (ft_nbrlen_base(b, 10) >= 8 && ft_nbrlen_base(b, 10) <= 11)
	{
		nbr[1] = 10000000 + (b % 1000000);
		nbr[0] = 11000000 + (b / 1000000);
	}
	else if (ft_nbrlen_base(b, 10) >= 12 && ft_nbrlen_base(b, 10) <= 16)
	{
		nbr[2] = 10000000 + (b % 1000000);
		nbr[1] = 10000000 + (b / 1000000 % 1000000);
		nbr[0] = 11100000 + (b / 1000000 / 1000000 % 1000000);
	}
	else if (ft_nbrlen_base(b, 10) >= 17 && ft_nbrlen_base(b, 10) <= 21)
		nbr = ft_parse_binary_helper(b, nbr);
	return (nbr);
}

/*
** Convert from binary to decimal
*/

int				ft_binary_to_decimal(int b)
{
	char	*binary;
	char	*itoab;
	int		len;
	int		i;
	int		r_value;

	len = 0;
	i = -1;
	r_value = 0;
	len = ft_nbrlen_base(b, 10);
	if (!(binary = (char *)malloc(sizeof(char) * len)))
		return (0);
	itoab = ft_itoa(b);
	ft_memmove(binary, itoab, len);
	ft_strdel(&itoab);
	while (++i < len)
		if (binary[i] == '1')
			r_value += ft_power(2, len - i - 1);
	ft_strdel(&binary);
	return (r_value);
}
