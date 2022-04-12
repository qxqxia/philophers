# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qxia <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 15:10:32 by qxia              #+#    #+#              #
#    Updated: 2022/04/11 16:32:59 by qxia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= philo

CC 		= gc

CFLAG 	= -Wall -Wextra -Werror -g3 -fsanitize=address

SRC		= 

OBJ		= $(SRC:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAG) -I. -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -I. -O $@

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
