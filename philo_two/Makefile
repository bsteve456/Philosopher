# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 17:55:40 by stbaleba          #+#    #+#              #
#    Updated: 2020/11/10 14:27:07 by stbaleba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pthread

NAME=philo_two
INC= -Iincludes
FILES=philo_two.c \
		src/static_init.c \
		src/waiter_init.c \
		src/philo_fork_state.c \
		src/philo_utils.c \
		src/philo_utils2.c src/sem_init.c \
		src/unlock_lock.c src/left_right.c \
		src/display.c src/send_msg.c \
		src/usleep.c
OBJ=$(FILES:.c=.o)

all:$(NAME)

$(NAME) : $(OBJ) ./includes/philo_two.h
	$(CC) $(CFLAGS) $(INC) $(OBJ) -lpthread -o $(NAME)
.c.o: $(FILES)
		$(CC) $(CFLAGS) -c $(INC) $< -lpthread -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
