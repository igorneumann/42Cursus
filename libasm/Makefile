# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 19:33:42 by ineumann          #+#    #+#              #
#    Updated: 2021/04/08 17:16:45 by ineumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
NAMEBONUS = libasmbonus.a

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_read.s ft_write.s ft_strdup.s
SRCBONUS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_read.s ft_write.s ft_strdup.s ft_list_push_front.s ft_list_size.s

OBJS = $(SRCS:%.s=%.o)
%.o: %.s
	nasm -f macho64 $<
all: $(NAME)

OBJSBONUS = $(SRCBONUS:%.s=%.o)
%.o: %.s
	nasm -f macho64 $<
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
bonus: $(NAMEBONUS)

$(NAMEBONUS): $(OBJSBONUS) $
	ar rcs $(NAME) $(OBJSBONUS)

clean:
	rm $(OBJS)
	rm $(OBJSBONUS)
fclean: clean
	rm $(NAME)
re: fclean all
test: $(NAME)
	gcc -Wall -Werror -Wextra -L. -lasm main.c 
	./a.out
	rm ./a.out
	rm $(NAME)
	rm $(OBJS)
.PHONY: all re clean fclean test