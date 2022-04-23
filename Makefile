# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 00:49:56 by ysakine           #+#    #+#              #
#    Updated: 2022/04/20 13:09:16 by ysakine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := ft_atoi.c main.c time.c philosopher.c exit.c manager.c
NAME := philosophers
CFLAGS := -Wall -Wextra -Werror
OBJS := ${SRCS:.c=.o}

all:${NAME}

${NAME} : ${OBJS}
	cc ${OBJS} -o ${NAME}

%.o : %.c
	cc -c ${CFLAGS} $<

clean:
	rm -rf ${OBJS}

fclean:clean
	rm -rf ${NAME}

re:fclean ${NAME}
