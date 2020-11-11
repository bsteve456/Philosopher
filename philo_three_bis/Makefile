# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 17:55:40 by stbaleba          #+#    #+#              #
#    Updated: 2020/11/11 16:42:53 by stbaleba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pthread

NAME=philo_three
INC= -Iincludes
FILES=philo_three.c \
	  src/waiter_init.c \
	  src/philo_fork_state.c src/usleep.c \
	  src/philo_utils.c src/unlock_lock.c \
	  src/monitor.c src/display.c
OBJ=$(FILES:.c=.o)

all:$(NAME)

$(NAME) : $(OBJ) ./includes/philo_three.h
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)
.c.o: $(FILES)
		$(CC) $(CFLAGS) -c $(INC) $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
