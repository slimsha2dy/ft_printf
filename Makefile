# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfrusciante <marvin@42.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 02:32:27 by jfruscia          #+#    #+#              #
#    Updated: 2022/08/26 02:42:44 by jfruscia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
INCS = .

SRCS_FILES =	ft_printf\
				ft_printf_csdi\
				ft_printf_unsigned\
				ft_printf_hex\
				ft_printf_ptr

SRCS = $(addsuffix .c, $(SRCS_FILES))
OBJS = $(addsuffix .o, $(SRCS_FILES))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME) $(OBJS)
	make fclean -C $(LIBFT)

re: clean all

.PHONY: all clean fclean re
