# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 19:32:05 by ineumann          #+#    #+#              #
#    Updated: 2021/04/20 17:54:38 by ineumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -I libft -g

SRCS = checker.c func.c movements.c

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