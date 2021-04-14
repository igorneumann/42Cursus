# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ineumann <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 12:47:51 by ineumann          #+#    #+#              #
#    Updated: 2019/11/25 18:01:10 by ineumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_split.c

SRCSBONUS =	ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

GCC	 = @gcc -Wall -Wextra -Werror -c
OBJS	= $(SRCS:.c=.o)
OBJSBONUS   = $(SRCSBONUS:.c=.o)
INCLUDES	= ./

all: $(NAME)
$(NAME):	$(SRCS) libft.h
			$(GCC) -I$(INCLUDES) -c $(SRCS)
			-@ar rc $(NAME) $(OBJS)
			-@ranlib $(NAME)

bonus:	  $(SRCS) $(SRCSBONUS) libft.h
			$(GCC) -I$(INCLUDES) -c $(SRCSBONUS) $(SRCS)
			-@ar rc $(NAME) $(OBJS) $(OBJSBONUS)
			-@ranlib $(NAME)
clean:
			-@$(RM) $(OBJS) $(OBJSBONUS)
fclean:	 clean
			-@$(RM) $(NAME)
re:		 fclean all
