# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 16:23:52 by ineumann          #+#    #+#              #
#    Updated: 2021/05/11 18:31:53 by ineumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VAR = 239 757 576 505 818 541 465 560 947 32 81 21 726 922 630 688 840 568 900 390 498 580 635 19 249 561 784 344 75 242 710 833 143 337 863 416 931 601 324 768 723 301 693 978 494 138 320 269 264 582 650 771 996 792 170 408 861 412 198 440 651 980 304 973 140 523 873 912 268 691 552 34 64 802 575 60 277 173 654 362 23 539 625 817 489 707 787 990 371 246 968 436 442 668 798 197 944 533 497 336

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
	@echo "\n\033[0;33mAyuda para PUSH-SWAP!"
	@echo "\n\033[0;31mMake\033[0m para compilar todo."
	@echo "\033[0;31mMake clean\033[0m para borrar los objectos."
	@echo "\033[0;31mMake fclean\033[0m para borrar objectos y ejecutables."
	@echo "\033[0;31mMake help\033[0m para ayuda."
	@echo "\033[0;31mMake push\033[0m par ejecutar push_shwap con la variable del Makefile."
	@echo "\033[0;31mMake checker\033[0m para ejecutar el checker con la variabble del Makefile."
	@echo "\033[0;31mMake count\033[0m para ejecutar push_swap y contar los movimientos.\n"
	@echo "\033[0;33;5;7mPD.: ESO CUENTA COMO BONUS!\033[0m\n"

.PHONY: all re clean fclean count checker print push make_both help