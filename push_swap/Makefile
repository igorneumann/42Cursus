# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ineumann <ineumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 16:23:52 by ineumann          #+#    #+#              #
#    Updated: 2021/05/01 20:11:25 by ineumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VAR = 125 90 251 273 188 30 221 82 270 274 293 59 160 126 253 81 194 237 70 287 9 215 211 229 167 22 96 159 68 93 204 275 179 74 230 226 245 239 236 8 278 178 197 101 118 200 255 285 279 132 257 127 36 175 99 130 41 140 58 34 190 18 142 62 161 55 216 206 280 153 2 133 0 26 16 181 155 85 71 24 65 212 47 29 177 238 32 272 49 5 242 286 185 219 150 207 259 84 184

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
	./push_swap $(VAR)

print: re
	./push_swap $(VAR) > result.txt

checker: re
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

.PHONY: all re clean fclean