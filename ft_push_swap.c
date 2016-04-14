/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:30:01 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/14 15:03:18 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#define CMP ft_strcmp

/*
** Bonus
** -v for verbose mode
** -c for color mode
** -o for number of operation
** -i for infos (Starting & ending a stack)
** -a for all
** Possibility to use -vcio instead of -v -c -i -o
** Messages for errors
** Add usage message
*/

static void		ft_all(t_flag *flg)
{
	flg->verbose = 1;
	flg->color = 1;
	flg->ope = 1;
	flg->infos = 1;
}

static void		ft_extract_flg(char **str, t_flag *flg, int i)
{
	int		j;

	while (str[i] && str[i][0] == '-' && ft_isalpha(str[i][1]))
	{
		j = 1;
		while (str[i][j] && ft_isalpha(str[i][j]))
		{
			if (str[i][j] == 'v')
				flg->verbose = 1;
			else if (str[i][j] == 'c')
				flg->color = 1;
			else if (str[i][j] == 'o')
				flg->ope = 1;
			else if (str[i][j] == 'i')
				flg->infos = 1;
			else if (str[i][j] == 'a')
				ft_all(flg);
			else
				ft_usage(*str);
			j++;
		}
		flg->total_mod += 1;
		i++;
	}
}

static void		ft_extract_stack(char **str, int len, t_swap **a, t_flag *flg)
{
	long	value;

	ft_init_flag(flg);
	ft_extract_flg(str, flg, 1);
	while (len > 0 + flg->total_mod)
	{
		value = ft_atoi_swap(str[len]);
		ft_check_min_man(value);
		ft_swapend(a, value, 1);
		len--;
	}
}

int				main(int ac, char **av)
{
	int		i;
	t_flag	flg;
	t_swap	*a;
	t_swap	*b;

	a = NULL;
	b = NULL;
	i = ac - 1;
	if (ac < 2)
		ft_usage(av[0]);
	else
	{
		ft_extract_stack(av, i, &a, &flg);
		i == flg.total_mod ? ft_error() : 0;
		ft_check_duplicates(a);
		ft_init_b(i - flg.total_mod, &b);
		ft_end(a);
		ft_end(b);
		flg.infos ? ft_print_infos(a) : 0;
		a->next == NULL ? ft_exit_one_nb(a, flg) : 0;
		ft_is_sorted(a) && ft_is_null(b) ? ft_exit_already_ordered(a, flg) : 0;
		ft_launcher(a, b, &flg);
	}
	return (0);
}
