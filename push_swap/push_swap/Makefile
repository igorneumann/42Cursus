# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 19:32:05 by ineumann          #+#    #+#              #
#    Updated: 2021/04/21 17:30:01 by ineumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -I libft -g

SRCS = push_swap.c func.c movements.c orderit.c push_func.c orderbig.c

LIB = ../libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ../libft/
	@$(CC) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)

clean:
	@rm -rf *.o *.gch *.dSYM

fclean: clean
	@rm -f *.o $(NAME)
	@make fclean -C ../libft/

re: fclean all

.PHONY: all re clean fclean