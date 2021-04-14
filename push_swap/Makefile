# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 19:32:05 by ineumann          #+#    #+#              #
#    Updated: 2021/04/14 18:54:48 by ineumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = -o checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I libft -g

SRCS = checker.c func.c movements.c

LIB = libft/libft.a

make_libft:
	@make -C libft/

all: $(NAME)

$(NAME): make_libft
	gcc -Wall -Wextra -Werror -I libft -g checker.c func.c movements.c libft/libft.a -o checker
#	$(CC) $(CFLAGS) $(SRCS) $(LIB) $(NAME)

clean:
	@rm -rf *.o *.gch *.dSYM

fclean: clean
	@rm -f *.o $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: all re clean fclean