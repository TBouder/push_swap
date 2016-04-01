/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 12:57:02 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/28 22:37:31 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_wstrlen_flags(wchar_t *str, t_flags flags)
{
	int		i;
	int		len;
	int		to_add;
	char	*b;

	i = 0;
	len = 0;
	while (str[i] && len < flags.preci)
	{
		b = ft_itoa_base(str[i], 2);
		(ft_strlen(b) <= 7) ? to_add = 1 : 0;
		(ft_strlen(b) >= 8 && ft_strlen(b) <= 11) ? to_add = 2 : 0;
		(ft_strlen(b) >= 12 && ft_strlen(b) <= 16) ? to_add = 3 : 0;
		(ft_strlen(b) >= 17 && ft_strlen(b) <= 21) ? to_add = 4 : 0;
		len += to_add;
		if (len > flags.preci)
			len -= to_add;
		i++;
		ft_strdel(&b);
	}
	return (len);
}

int			ft_wstrlen(wchar_t *str)
{
	int		i;
	int		len;
	int		to_add;
	char	*b;

	i = 0;
	len = 0;
	while (str[i])
	{
		b = ft_itoa_base(str[i], 2);
		(ft_strlen(b) <= 7) ? to_add = 1 : 0;
		(ft_strlen(b) >= 8 && ft_strlen(b) <= 11) ? to_add = 2 : 0;
		(ft_strlen(b) >= 12 && ft_strlen(b) <= 16) ? to_add = 3 : 0;
		(ft_strlen(b) >= 17 && ft_strlen(b) <= 21) ? to_add = 4 : 0;
		len += to_add;
		i++;
		ft_strdel(&b);
	}
	return (len);
}

int			ft_wchar_len(int *nbr)
{
	int		i;

	i = 0;
	while (nbr[i] != -1)
		i++;
	return (i);
}
