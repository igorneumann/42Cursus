# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 19:32:05 by ineumann          #+#    #+#              #
#    Updated: 2021/04/16 20:50:04 by ineumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = -o checker

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -I libft -g

SRCS = checker.c func.c movements.c

LIB = libft/libft.a

OBJS = $(SRCS:.c=.o)

make_libft:
	@make -C libft/

all: $(NAME)

$(NAME): $(OBJS)
	make_libft
	-$(CC) $(CFLAGS) $(SRCS) $(LIB) $(NAME)

clean:
	@rm -rf *.o *.gch *.dSYM

fclean: clean
	@rm -f *.o $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: all re clean fclean