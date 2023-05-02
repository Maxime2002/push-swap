# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 19:08:47 by mlangloi          #+#    #+#              #
#    Updated: 2023/04/28 01:01:37 by mlangloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = instructions.c \
	ft_putstr.c \
	lst.c \
	push_swap.c \

OBJS =  ${SRCS:.c=.o}

.c.o:
		        $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): ${OBJS}
		$(AR) $(NAME) ${OBJS}

all:    ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		rm -f ${NAME}

re:     fclean all

bonus : ${OBJS}
		${AR} ${NAME} ${OBJS}

.PHONY: all clean fclean re






