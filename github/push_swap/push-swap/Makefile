# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 19:32:05 by ineumann          #+#    #+#              #
#    Updated: 2021/05/07 17:14:48 by ineumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -g

SRCS = push_swap.c orderit.c push_func.c orderbig.c orderhundred.c orderhuge.c

COMMON = ../common/movements.c ../common/func.c ../common/common.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRCS) $(COMMON) -o $(NAME)

clean:
	@rm -rf *.o *.gch *.dSYM
	@rm -rf ../common/*.o ../common/*.gch ../common/*.dSYM

fclean: clean
	@rm -f *.o $(NAME)

re: fclean all

.PHONY: all re clean fclean