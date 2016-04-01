/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:06:09 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/25 15:01:01 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_flag_l_helper_0(int *index, t_flags flags)
{
	*index += 1;
	return ((flags.l == 0 || flags.l == 3 || flags.l == 4) ? 1 : flags.l);
}

static int	ft_flag_l_helper_1(int *index, t_flags flags)
{
	*index += 2;
	return ((flags.l == 0 || flags.l == 3 || flags.l == 4) ? 2 : flags.l);
}

static int	ft_flag_l_helper_2(int *index, t_flags flags)
{
	*index += 1;
	return ((flags.l == 0 || flags.l == 4) ? 3 : flags.l);
}

int			ft_flag_length(char *str, int *index, t_flags flags)
{
	if (str[*index] == 'l' && str[*index + 1] != 'l')
		return (ft_flag_l_helper_0(index, flags));
	if (str[*index] == 'l' && str[*index + 1] == 'l')
		return (ft_flag_l_helper_1(index, flags));
	if (str[*index] == 'h' && str[*index + 1] != 'h')
		return (ft_flag_l_helper_2(index, flags));
	if (str[*index] == 'h' && str[*index + 1] == 'h')
	{
		*index += 2;
		return ((flags.l == 0) ? 4 : flags.l);
	}
	if (str[*index] == 'j')
	{
		*index += 1;
		return ((flags.l == 0 || flags.l == 3 || flags.l == 4) ? 5 : flags.l);
	}
	if (str[*index] == 'z')
	{
		*index += 1;
		return ((flags.l == 0 || flags.l == 3 || flags.l == 4) ? 6 : flags.l);
	}
	return (0);
}
