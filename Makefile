# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 00:49:56 by ysakine           #+#    #+#              #
#    Updated: 2022/05/08 19:02:41 by ysakine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := ft_atoi.c main.c time.c philosopher.c exit.c manager.c eat.c sleep.c
NAME := philosophers
CFLAGS := -Wall -Wextra -Werror
OBJS := ${SRCS:.c=.o}

all:${NAME}

${NAME} : ${OBJS}
	cc ${OBJS} -pthread -lpthread -o ${NAME}

%.o : %.c
	cc -c ${CFLAGS} $<

clean:
	rm -rf ${OBJS}

fclean:clean
	rm -rf ${NAME}

re:fclean ${NAME}
