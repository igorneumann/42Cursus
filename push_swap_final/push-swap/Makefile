# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 19:32:05 by ineumann          #+#    #+#              #
#    Updated: 2021/05/20 20:42:20 by ineumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -g

SANIT = -g -g3 -fsanitize=address

SRCS = push_swap.c orderit.c push_func.c orderbig.c orderhundred.c orderhuge.c

COMMON = ../common/movements.c ../common/func.c ../common/common.c ../common/print.c

OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	@$(CC) $(CFLAGS) $(SRCS) $(COMMON) -o $(NAME)

sanit: $(OBJS)
	@$(CC) $(CFLAGS) $(SANIT) $(SRCS) $(COMMON) -o $(NAME)

clean:
	@rm -rf *.o *.gch *.dSYM
	@rm -rf ../common/*.o ../common/*.gch ../common/*.dSYM

fclean: clean
	@rm -f *.o $(NAME)

re: fclean all

.PHONY: all re clean fclean sanit