# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkael <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 12:11:53 by bkael             #+#    #+#              #
#    Updated: 2021/07/17 19:00:30 by bkael            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAME2 = server

SRC = client.c \
	minitalk_utils.c \
	minitalk_utils2.c

SRC2 = server.c \
	minitalk_utils.c \
	minitalk_utils2.c

OBJ = $(SRC:%.c=%.o)
OBJ2 = $(SRC2:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	gcc $(FLAGS) $^ -o $(NAME)

$(NAME2): $(OBJ2)
	gcc $(FLAGS) $^ -o $(NAME2)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ2)

fclean: clean
	rm -f $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re