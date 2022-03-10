# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 16:25:39 by aniezgod          #+#    #+#              #
#    Updated: 2022/03/10 17:31:38 by aniezgod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/push_swap.c \
		./srcs/ft_check.c \
		./srcs/ft_lst.c \

OBJS = ${SRCS:.c=.o}

NAME = push_swap
CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCS = -I ./includes -I ./libft/includes/

all: ${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INCS}

$(NAME): $(OBJS)
			${MAKE} -C ./libft
			gcc ${CFLAGS} -o $(NAME) $(OBJS) ${INCS} libft/libft.a

clean:
			${RM} ${OBJS}
			${MAKE} -C libft clean 
			
fclean: clean
			${RM} ${NAME}
			${MAKE} -C libft fclean

re: fclean all

.PHONY:		all clean fclean re