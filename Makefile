# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 15:48:47 by tbouder           #+#    #+#              #
#    Updated: 2016/04/06 16:42:55 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	push_swap

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra -g

SRC 		= 	ft_push_swap.c ft_launcher.c ft_recursiv.c \
				ft_tools.c ft_swap_struct.c ft_flags.c ft_exit.c \
				ft_push.c ft_swap.c ft_rotate.c ft_reverse_rotate.c \
				ft_list_state.c

LIB			=	-Lft_printf -lftprintf

OBJ			=	$(SRC:.c=.o)

HEADER 		=	ft_push_swap.h ft_printf/ft_printf.h

all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	$(MAKE) re -C ft_printf
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

.SILENT : clean
clean:
	$(MAKE) clean -C ft_printf
	rm -f $(OBJ)
	rm -f *.gch
	rm -rf *.dSYM

.SILENT : fclean
fclean: clean
	$(MAKE) fclean -C ft_printf
	rm -f $(NAME)

re: fclean all
