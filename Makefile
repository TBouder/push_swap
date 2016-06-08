# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 15:48:47 by tbouder           #+#    #+#              #
#    Updated: 2016/06/08 19:56:45 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	push_swap

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra -g -O3

SRC 		= 	ft_push_swap.c ft_launcher.c ft_algo.c \
				ft_tools.c ft_swap_struct.c ft_flags.c ft_exit.c \
				ft_push.c ft_swap.c ft_rotate.c ft_reverse_rotate.c \
				ft_list_state.c ft_part.c

LIB			=	-Lft_printf -lftprintf

OBJ			=	$(SRC:.c=.o)

HEADER 		=	ft_push_swap.h ft_printf/ft_printf.h

all: $(NAME)

.SILENT : $(NAME)
$(NAME): $(OBJ)
	$(MAKE) re -C ft_printf
	@$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(LIB)

.SILENT : clean
clean:
	$(MAKE) clean -C ft_printf
	rm -f $(OBJ)
	rm -f *.gch
	rm -f ft_printf/libft/libft.h.gch
	rm -f *.dSYM

.SILENT : fclean
fclean: clean
	$(MAKE) fclean -C ft_printf
	rm -f $(NAME)

re: fclean all
