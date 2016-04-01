# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 15:48:47 by tbouder           #+#    #+#              #
#    Updated: 2016/04/01 12:10:20 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	push_swap

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

SRC 		= 	ft_push_swap.c ft_launcher.c ft_recursiv.c \
				ft_tools.c ft_swap_struct.c \
				ft_push.c ft_swap.c ft_rotate.c ft_reverse_rotate.c \

LIB			=	-Llibft -lft

OBJ			=	$(SRC:.c=.o)

HEADER 		=	ft_push_swap.h libft/libft.h

all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	$(MAKE) re -C libft
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

.SILENT : clean
clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ)
	rm -f *.gch
	rm -rf *.dSYM

.SILENT : fclean
fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all
