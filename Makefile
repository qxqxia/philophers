# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qxia <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 10:56:47 by qxia              #+#    #+#              #
#    Updated: 2022/05/10 11:23:48 by qxia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGE = -Wall -Wextra -Werror

SRC := src/main.c \
		src/utils.c \
		src/init.c \
		src/philo.c \
		src/check.c 

OBJ := $(SRC:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGE) -I. -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGE) $(OBJ) -lpthread -I. -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
