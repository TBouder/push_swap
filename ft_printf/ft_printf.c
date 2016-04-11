/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:02:47 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/11 11:54:13 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Bonus
** - flag *
** - flag !
** - %f
** - colors
** - binary
** - binary oct
*/

static int		ft_undef(const char *str, int i)
{
	while (str[i])
	{
		if (ft_is_printf(str[i]) == 1 || ft_is_printf(str[i]) == 2)
			return (1);
		i++;
	}
	return (0);
}

static int		ft_color(const char *str, int *index)
{
	if (str[*index + 1] == 'b' && str[*index + 2] == '}')
		write(1, "\033[34;01m", 8);
	else if (str[*index + 1] == 'r' && str[*index + 2] == '}')
		write(1, "\033[31;01m", 8);
	else if (str[*index + 1] == 'g' && str[*index + 2] == '}')
		write(1, "\033[32;01m", 8);
	else if (str[*index + 1] == 'y' && str[*index + 2] == '}')
		write(1, "\033[33;01m", 8);
	else if (str[*index + 1] == 'p' && str[*index + 2] == '}')
		write(1, "\033[35;01m", 8);
	else if (str[*index + 1] == 'c' && str[*index + 2] == '}')
		write(1, "\033[36;01m", 8);
	else if (str[*index + 1] == 'w' && str[*index + 2] == '}')
		write(1, "\033[37;01m", 8);
	else if (str[*index + 1] == '0' && str[*index + 2] == '}')
		write(1, "\033[00m", 5);
	else
	{
		index += 1;
		return (1);
	}
	*index += 3;
	return (0);
}

int				ft_is_printf(char c)
{
	if (c == '%' || c == 'd' || c == 'D' || c == 'i' || c == 'x' || c == 'X'
		|| c == 's' || c == 'S' || c == 'p' || c == 'c' || c == 'C' || c == 'o'
		|| c == 'O' || c == 'u' || c == 'U' || c == 'f' || c == 'F' || c == 'b'
		|| c == 'B')
		return (1);
	if (c == '.' || ft_isnumber(c) || c == '#' || c == '-' || c == '+'
		|| c == ' ' || c == 'l' || c == 'h' || c == 'j' || c == 'z' || c == '!'
		|| c == '*')
		return (0);
	return (2);
}

int				ft_printf(const char *format, ...)
{
	va_list		pa;
	int			i;
	int			r_val;

	i = -1;
	r_val = 0;
	va_start(pa, format);
	if (format == NULL)
		return (-1);
	while (format[++i])
	{
		(format[i] == '{') ? ft_color(format, &i) : 0;
		if (format[i] == '%' && ft_undef(format, i + 1) == 0)
			return (r_val);
		format[i] == '%' && format[i + 1] == '\0' ? r_val-- : 0;
		format[i] != '%' ? ft_putchar(format[i]) : 0;
		if (format[i] == '%' && format[i + 1] && ft_undef(format, i + 1))
		{
			if ((i = ft_printf_conv((char *)format, &pa, &r_val, i + 1)) == -1)
				return (-1);
		}
		r_val++;
	}
	va_end(pa);
	return (r_val);
}
