# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javjimen <javjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 14:40:29 by javjimen          #+#    #+#              #
#    Updated: 2023/11/24 15:00:20 by javjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRCS		= $(addprefix srcs/, ft_printf.c \
								 ft_printf_utils.c)

OBJS 		= $(SRCS:%.c=%.o)

CC			= cc
RM			= rm -rf
AR			= ar

CFLAGS 		+= -Wall -Wextra -Werror
ARFLAGS		= -r -c -s

.PHONY:		all libft clean fclean re

all: 		$(NAME)

$(NAME): 	$(LIBFT) $(OBJS)
			cp $(LIBFT) $(NAME)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
			make -C $(LIBFT_PATH) all

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			make -C $(LIBFT_PATH) clean
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean: 	clean
			make -C $(LIBFT_PATH) fclean
			$(RM) $(NAME)

re:			fclean all
