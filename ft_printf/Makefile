# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 15:48:47 by tbouder           #+#    #+#              #
#    Updated: 2016/03/29 11:34:11 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libftprintf.a

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

PRINTF 		= 	ft_printf.c

PRINTF_CONV	=	ft_conv/ft_conv_percent.c ft_conv/ft_conv_p.c ft_conv/ft_conv_f.c \
				ft_conv/ft_conv_d_i.c ft_conv/ft_conv_int_0.c ft_conv/ft_conv_int_1.c \
				ft_conv/ft_conv_x.c ft_conv/ft_conv_hex_0.c ft_conv/ft_conv_hex_1.c \
				ft_conv/ft_conv_u.c ft_conv/ft_conv_uni_0.c ft_conv/ft_conv_uni_1.c \
				ft_conv/ft_conv_s.c ft_conv/ft_conv_str_0.c ft_conv/ft_conv_wstr.c \
				ft_conv/ft_conv_c.c ft_conv/ft_conv_char_0.c \
				ft_conv/ft_conv_o.c ft_conv/ft_conv_oct_0.c ft_conv/ft_conv_oct_1.c \
				ft_conv/ft_conv_f.c ft_conv/ft_conv_flt_0.c ft_conv/ft_conv_b.c

PRINTF_FUNC	=	ft_funcs/ft_tools_itoa.c ft_funcs/ft_tools_nbr.c \
				ft_funcs/ft_tools_binary.c ft_funcs/ft_tools_wchar.c \
				ft_funcs/ft_flags_0.c ft_funcs/ft_flags_1.c \
				ft_funcs/ft_printf_conv.c

FT_IS		=	libft/ft_is/ft_isalnum.c libft/ft_is/ft_isalpha.c libft/ft_is/ft_isascii.c \
				libft/ft_is/ft_isdigit.c libft/ft_is/ft_isprint.c libft/ft_is/ft_isnumber.c \
				libft/ft_is/ft_isspace.c libft/ft_is/ft_isprime.c libft/ft_is/ft_ishexa.c

FT_LEN		=	libft/ft_len/ft_nbrlen.c libft/ft_len/ft_nbrlen_base.c\
				libft/ft_len/ft_strlen.c libft/ft_len/ft_linelen.c libft/ft_len/ft_hexalen.c

FT_LST		=	libft/ft_lst/ft_lstnew.c libft/ft_lst/ft_lstadd.c libft/ft_lst/ft_lstclr.c \
				libft/ft_lst/ft_lstdelone.c libft/ft_lst/ft_lstdel.c libft/ft_lst/ft_lstiter.c \
				libft/ft_lst/ft_lstmap.c libft/ft_lst/ft_lstnew.c libft/ft_lst/ft_lststart.c \
				libft/ft_lst/ft_lstend.c libft/ft_lst/ft_lstlen.c libft/ft_lst/ft_lstprint.c \
				libft/ft_lst/ft_lstcontentsize.c libft/ft_lst/ft_lsttostr.c

FT_MEM		=	libft/ft_mem/ft_memccpy.c libft/ft_mem/ft_memchr.c libft/ft_mem/ft_memcmp.c \
				libft/ft_mem/ft_memcpy.c libft/ft_mem/ft_memmove.c libft/ft_mem/ft_memset.c \
				libft/ft_mem/ft_memalloc.c libft/ft_mem/ft_memdel.c libft/ft_mem/ft_bzero.c \
				libft/ft_mem/ft_realloc.c

FT_NB		=	libft/ft_nb/ft_atoi.c libft/ft_nb/ft_atoi_part.c  libft/ft_nb/ft_atoi_hexa.c \
				libft/ft_nb/ft_nbrsmallest.c libft/ft_nb/ft_nbrlargest.c \
				libft/ft_nb/ft_next_prime.c libft/ft_nb/ft_nbrnew.c

FT_PRINT	=	libft/ft_print/ft_putchar.c libft/ft_print/ft_putchar_fd.c \
				libft/ft_print/ft_putstr.c libft/ft_print/ft_putstr_fd.c \
				libft/ft_print/ft_putendl.c libft/ft_print/ft_putendl_fd.c \
				libft/ft_print/ft_putnbr.c \
				libft/ft_print/ft_putnbr_base.c \
				libft/ft_print/ft_putnbr_fd.c libft/ft_print/ft_nbrendl.c

FT_STR		=	libft/ft_str/ft_itoa.c libft/ft_str/ft_itoa_base.c \
				libft/ft_str/ft_strcat.c libft/ft_str/ft_strncat.c libft/ft_str/ft_strlcat.c \
				libft/ft_str/ft_strcpy.c libft/ft_str/ft_strncpy.c \
				libft/ft_str/ft_strchr.c libft/ft_str/ft_strrchr.c \
				libft/ft_str/ft_strstr.c libft/ft_str/ft_strnstr.c \
				libft/ft_str/ft_strcmp.c libft/ft_str/ft_strncmp.c \
				libft/ft_str/ft_strdup.c \
				libft/ft_str/ft_striter.c libft/ft_str/ft_striteri.c \
				libft/ft_str/ft_strequ.c libft/ft_str/ft_strnequ.c \
				libft/ft_str/ft_strmap.c libft/ft_str/ft_strmapi.c \
				libft/ft_str/ft_strnew.c libft/ft_str/ft_strdel.c libft/ft_str/ft_strclr.c \
				libft/ft_str/ft_strsub.c libft/ft_str/ft_strjoin.c \
				libft/ft_str/ft_strtrim.c libft/ft_str/ft_strtrim_char.c\
				libft/ft_str/ft_strsplit.c \
				libft/ft_str/ft_tolower.c libft/ft_str/ft_toupper.c

FT_MATH		=	libft/ft_math/ft_factorial.c libft/ft_math/ft_fibonacci.c \
				libft/ft_math/ft_power.c libft/ft_math/ft_sqrt.c libft/ft_math/ft_rand.c \
				libft/ft_math/ft_sin.c libft/ft_math/ft_cos.c libft/ft_math/ft_tan.c \
				libft/ft_math/ft_pgcd.c

GNL			=	libft/get_next_line/get_next_line.c

OBJ			=	$(PRINTF:.c=.o) $(PRINTF_CONV:.c=.o) $(PRINTF_FUNC:.c=.o) \
				$(FT_IS:.c=.o) $(FT_LEN:.c=.o) $(FT_LST:.c=.o) \
				$(FT_MEM:.c=.o) $(FT_NB:.c=.o) $(FT_PRINT:.c=.o) \
				$(FT_STR:.c=.o) $(FT_MATH:.c=.o) $(GNL:.c=.o)

HEADER 		=	ft_printf.h libft/libft.h libft/get_next_line/get_next_line.h

all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_IS)
	mv *.o libft/ft_is/
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_LEN)
	mv *.o libft/ft_len/
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_LST)
	mv *.o libft/ft_lst/
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_MEM)
	mv *.o libft/ft_mem/
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_NB)
	mv *.o libft/ft_nb/
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_PRINT)
	mv *.o libft/ft_print/
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_STR)
	mv *.o libft/ft_str/
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_MATH)
	mv *.o libft/ft_math/
	$(CC) $(CFLAGS) -c $(HEADER) $(GNL)
	mv *.o libft/get_next_line/
	$(CC) $(CFLAGS) -c $(HEADER) $(PRINTF_CONV)
	mv *.o ft_conv/
	$(CC) $(CFLAGS) -c $(HEADER) $(PRINTF_FUNC)
	mv *.o ft_funcs/
	$(CC) $(CFLAGS) -c $(HEADER) $(PRINTF)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

.SILENT : clean
clean:
	rm -f $(OBJ)
	rm -f *.gch

.SILENT : fclean
fclean: clean
	rm -f $(NAME)

re: fclean all
