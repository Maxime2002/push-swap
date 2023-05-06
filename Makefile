# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 20:33:12 by mlangloi          #+#    #+#              #
#    Updated: 2023/05/06 17:43:35 by mlangloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

CC		= gcc
FLAGS = -Wall -Wextra -Werror

SRCS = push.c \
	reverse_rotate.c \
	rotate.c \
	ft_split.c \
	swap.c \
	func_libft.c \
	logic.c \
	lst.c \
	lst2.c \
	main.c \
	algo.c \
	check.c \

SRCS2 = checker.c \
	checker2.c \
	checker3.c \
	checker4.c \
	get_next_line.c \
	get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

OBJS2 = $(SRCS2:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(NAME2): $(OBJS2)
	$(CC) $(FLAGS) -o $(NAME2) $(OBJS2)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS2)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)

re: fclean all

.PHONY:	all clean fclean re norm
