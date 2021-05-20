# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 16:23:52 by ineumann          #+#    #+#              #
#    Updated: 2021/05/18 17:45:52 by ineumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VAR = 5099677 14403146 19008768 986335 19608320 -1777833 19764943 18277217 -637333 8278675 9246012 252405 347700 18691907 8319183 9876064 9002606 11952555 7279931 8811450 15975842 9975978 2674105 16260075 19871699 7235315 10230360 8313330 -1717743 14221397

NAME = count

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = countmovs.c

make_both:
	@make -C push-swap/
	@make -C ft-checker/
	@cp ./ft-checker/checker ./checker
	@cp ./push-swap/push_swap ./push_swap

push: re
	@echo "\nComando ejecutado:\n"
	./push_swap $(VAR)

print: re
	@echo "\nComando ejecutado:\n"
	./push_swap $(VAR) > result.txt
	@echo "\nLos resultados han sido guardados en result.txt\n"

checker: re
	@echo "\nComando ejecutado:\n"
	./checker $(VAR)

count: re
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	./push_swap $(VAR) | ./count

all: $(NAME)

$(NAME): make_both

clean:
	@make clean -C push-swap/
	@make clean -C ft-checker/

fclean: 
	@make fclean -C push-swap/
	@make fclean -C ft-checker/
	@rm -f ./checker ./push_swap ./result.txt ./count

re: fclean make_both

help:
	@echo "\n\033[0;33m~~ Ayuda para PUSH-SWAP! ~~"
	@echo "\n\033[0;31mMake\033[0m para compilar todo."
	@echo "\033[0;31mMake clean\033[0m para borrar los objectos."
	@echo "\033[0;31mMake fclean\033[0m para borrar objectos y ejecutables."
	@echo "\033[0;31mMake help\033[0m para ayuda."
	@echo "\033[0;31mMake push\033[0m par ejecutar push_shwap con la variable del Makefile."
	@echo "\033[0;31mMake checker\033[0m para ejecutar el checker con la variable del Makefile."
	@echo "\033[0;31mMake count\033[0m para ejecutar push_swap y contar los movimientos."
	@echo "\033[0;31mMake print\033[0m para ejecutar push_swap e imprimir el resultado en result.txt.\n"
	@echo "\033[0;33;5;7mPD.: ESO CUENTA COMO BONUS!\033[0m\n"

.PHONY: all re clean fclean count checker print push make_both help