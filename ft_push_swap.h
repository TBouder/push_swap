/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:27:33 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/31 19:51:37 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_swap
{
	int				stack;
	int				activ;
	struct s_swap	*start;
	struct s_swap	*end;
	struct s_swap	*next;
	struct s_swap	*prev;
}					t_swap;

int		ft_launcher(t_swap *a, t_swap *b);

void	ft_print_swap(t_swap *a);

/*Tools*/
void	ft_error();
int		ft_atoi_swap(const char *str);
void	ft_check_min_man(long value);
int		ft_is_sorted(t_swap *swap);
int		ft_is_null(t_swap *swap);

/*Swap_struct*/
void	ft_swapend(t_swap **swap, int value, int activ);
void	ft_push_front(t_swap *stack);
int		ft_swaplen(t_swap *swap);
int		ft_swaprev(t_swap *swap);


/*Launcher*/
int			ft_z(t_swap *swap);
int			ft_y(t_swap *swap);
int			ft_sorted_a(t_swap *swap);



void	ft_swap_a_r(t_swap *a, t_swap *b, int *i);
void	ft_swap_b_r(t_swap *a, t_swap *b, int *i);
void	ft_swap_ab_r(t_swap *a, t_swap *b, int *i);

void	ft_push_to_b_r(t_swap *a, t_swap *b, int *i);
void	ft_push_to_a_r(t_swap *a, t_swap *b, int *i);

void	ft_rot_a_r(t_swap *a, t_swap *b, int *i);
void	ft_rot_b_r(t_swap *a, t_swap *b, int *i);
void	ft_rot_ab_r(t_swap *a, t_swap *b, int *i);

void	ft_rev_rot_a_r(t_swap *a, t_swap *b, int *i);


void	sa(t_swap *a);
void	sb(t_swap *b);
void	ss(t_swap *a, t_swap *b);
void	pa(t_swap *a, t_swap *b);
void	pb(t_swap *a, t_swap *b);
void	ra(t_swap *a);
void	rb(t_swap *b);
void	rr(t_swap *a, t_swap *b);
void	rra(t_swap *a);
void	rrb(t_swap *b);
void	rrr(t_swap *a, t_swap *b);

#endif
