# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 09:50:21 by rothiery          #+#    #+#              #
#    Updated: 2024/07/15 09:10:38 by rothiery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	push_swap

SRC= 	./src/parsing/check.c	./src/parsing/prnt_error.c	./src/utils/check_utils.c	\
		./src/utils/lst_utils.c	./src/utils/p_moves.c	./src/utils/push_swap_utils.c	\
		./src/utils/r_moves.c	./src/utils/rr_moves.c			./src/utils/s_moves.c	\
		./src/push_swap.c		./src/sorting/sort_utils.c		 ./src/sorting/algo.c	\

OFILES= ${SRC:.c=.o}
OFILESB=${SRCB:.c=.o}
OFILESALL=${OFILES} ${OFILESB}

${NAME}:${OFILES}
	@${NAME} $?
	@echo "\n\n ${GRAS}${RED}push_swap EST COMPILÉ${RESET}"

CC= 	cc
CFLAGS= -Wall -Wextra -Werror -fsanitize=address -g3

RESET = \033[0m
GRAS = \033[1m
ITALIQUE = \033[3m
SOULIGN = \033[4m
UP = \033[A
BLINK = \033[6m

ORANGE = \033[38;5;216m
DARKBLUE = \033[38;5;21m
RED = \033[38;5;130m
DARK_RED = \033[38;5;88m
GREEN = \033[38;5;85m

#change value with number of src files !
NBR_TOT_FICHIER = 12

FICH_COUNT = 0
NBR_COMPILER = ${shell expr 100 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}
BAR =  ${shell expr 23 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}
REST = ${shell expr 23 - ${BAR}}

all:	${NAME}

${NAME}:		${OFILES}
		@${CC} ${CFLAGS} ${OFILES} -o ${NAME}
		@echo "\n\n${GREEN}[✓] - ${_GREEN}Push Swap${GREEN} Successfully Compiled!${RESET}"

%.o:%.c
	@${eval FICH_COUNT = ${shell expr ${FICH_COUNT} + 1}}
	@${CC} ${CFLAGS} -c -I . $< -o ${<:.c=.o}
	@echo " ${GRAS}${RED}-> COMPILATION EN COURS${RESET}${GRAS}${GREEN}${RESET}"
	@printf " ${RED}${GRAS}[${GREEN}%-.${BAR}s${DARK_RED}%-.${REST}s${RED}] [%d/%d (%d%%)] ${GREEN}$<  ✓                         ${DEF_COLOR}" "-----------------------" "-----------------------" ${FICH_COUNT} ${NBR_TOT_FICHIER} ${NBR_COMPILER}
	@echo "${UP}${UP}${UP}"
	@echo ""

clean:
	@rm -f ${OFILESALL}
	@echo "${ORANGE}${GRAS}\tNETTOYAGE${RESET}"
	@echo "${RED}${ITALIQUE} -les fichiers sont supprimés${RESET}"

fclean:	clean
	@rm -f ${NAME}
	@${RM} ${NAME}
	@echo "${RED}${ITALIQUE} -${NAME} est supprimê${RESET}"

re:	fclean all

.PHONY:		all bonus clean fclean re
