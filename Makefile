# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memilio <memilio@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/21 23:49:17 by memilio           #+#    #+#              #
#    Updated: 2020/05/26 01:59:10 by memilio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCS = ft_printf.h
FILES =		ft_atoi.c \
			ft_itoa_hex.c \
			ft_itoa_u.c \
			ft_numlen.c \
			ft_printf.c \
			ft_printf_addprefix.c \
			ft_printf_char.c \
			ft_printf_hexs.c \
			ft_printf_n.c \
			ft_printf_padding.c \
			ft_printf_parse.c \
			ft_printf_parse_format.c \
			ft_printf_pointer.c \
			ft_printf_print.c \
			ft_printf_sint.c \
			ft_printf_specifiers.c \
			ft_printf_string.c \
			ft_printf_unint.c \
			ft_putchar_fd.c \
			ft_putchar_pf.c \
			ft_strdup.c \
			ft_strlcpy.c \
			ft_strlcut.c \
			ft_strlen.c \
			ft_strchr.c \
			ft_toupper.c
OBJS = $(FILES:.c=.o)
FLAGS = -Wall -Wextra -Werror
LIBC = ar rcs

.PHONY: all clean fclean re .c.o bonus

.c.o:
	gcc ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${INCS}
	${LIBC} $(NAME) $(OBJS)

all: $(NAME)

bonus: $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
