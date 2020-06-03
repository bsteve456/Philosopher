# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 17:55:40 by stbaleba          #+#    #+#              #
#    Updated: 2020/06/03 16:46:29 by blacking         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pthread

NAME=philo_one
INC= -Iincludes
FILES=philo_one.c \
		src/static_init.c \
		src/waiter_init.c \
		src/philo_fork_state.c
OBJ=$(FILES:.c=.o)

all:$(NAME)

$(NAME) : $(OBJ) ./includes/philo_one.h
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)
.c.o: $(FILES)
		$(CC) $(CFLAGS) -c $(INC) $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
