# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 00:49:56 by ysakine           #+#    #+#              #
#    Updated: 2022/05/10 16:07:51 by ysakine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := philo/ft_atoi.c philo/main.c philo/time.c philo/philosopher.c\
philo/exit.c philo/manager.c philo/eat.c philo/sleep.c
NAME := philosophers
CFLAGS := -Wall -Wextra -Werror
OBJS := ${SRCS:.c=.o}

all:${NAME}

${NAME} : ${OBJS}
	cc ${OBJS} -pthread -lpthread -o ${NAME}

%.o : philo/%.c
	cc -c ${CFLAGS} $<

clean:
	rm -rf ${OBJS}

fclean:clean
	rm -rf ${NAME}

re:fclean ${NAME}
