# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 16:25:39 by aniezgod          #+#    #+#              #
#    Updated: 2022/06/16 18:48:14 by aniezgod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ----------------------------------COLORS------------------------------------#

BOLD = \e[1;37m
END = \e[0;37m
UNDER = \e[4;37m
GREY = \e[0;30m
RED = \e[0;31m
GREEN = \e[0;32m
YELLOW = \e[0;33m
BLUE = \e[0;34m
PURPLE = \e[0;35m
CYAN = \e[0;36m
WHITE = \e[0;37m

SRCS =	./srcs/push_swap.c \
		./srcs/ft_check.c \
		./srcs/ft_lst.c \
		./srcs/ft_ope_a.c \
		./srcs/ft_ope_b.c \
		./srcs/ft_ope_a_and_b.c \
		./srcs/ft_lst2.c \
		./srcs/ft_error.c \
		./srcs/ft_three_nb_or_less.c \
		./srcs/ft_algo2.c \
		./srcs/ft_algo.c \
		./srcs/ft_median.c \
		./srcs/ft_place.c \
		./srcs/ft_algo_five.c \
		./srcs/ft_algo_six.c \

OBJS = ${SRCS:.c=.o}

NAME = push_swap
CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCS = -I ./includes -I ./libft/includes/

all: ${NAME}

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INCS}

$(NAME): $(OBJS)
			@printf "${WHITE}${BOLD}╔════════════════════════════════════════════════════════════════════════════╗\n"
			@printf "${BOLD}║                              .: COMPILATION :.                             ║\n"
			@printf "${BOLD}╚════════════════════════════════════════════════════════════════════════════╝\n"
			@${MAKE} -C ./libft
			@printf "${BOLD}║                                    ${PURPLE}libft                                   ${WHITE}║\n"
			@gcc ${CFLAGS} -o $(NAME) $(OBJS) ${INCS} libft/libft.a
			@printf "${BOLD}║                                  ${PURPLE}${NAME}                                 ${WHITE}║\n"
			@printf "${BOLD}╚════════════════════════════════════════════════════════════════════════════╝\n"

clean:
			@${RM} ${OBJS}
			@${MAKE} -C libft clean 
			
fclean: clean
			@printf "${BOLD}Entreprise de nettoyage bonjour ?\n"
			@${RM} ${NAME}
			@${MAKE} -C libft fclean
			@printf "${BOLD}${GREEN}Tout est propre !✨\n"

re: fclean all

.PHONY:		all clean fclean re