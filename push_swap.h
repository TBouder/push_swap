/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:27:33 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/30 16:41:34 by tbouder          ###   ########.fr       */
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

void	ft_error();

void		ft_swapend(t_swap **swap, int value, int activ);
t_swap		*ft_last(t_swap *a);
t_swap		*ft_end(t_swap *swap);
void		ft_print_swap(t_swap *a);


int		ft_atoi_swap(const char *str);
void	ft_check_min_man(long value);
void	ft_check_duplicates(t_swap *a);
void	ft_launcher(t_swap *a, t_swap *b);
void	ft_push_front(t_swap *stack);

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
