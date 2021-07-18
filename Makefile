# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkael <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 12:11:53 by bkael             #+#    #+#              #
#    Updated: 2021/07/18 16:28:09 by bkael            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAME2 = server

NAME_BONUS = client_bonus
NAME2_BONUS = server_bonus

SRC = client.c \
	minitalk_utils.c \
	minitalk_utils2.c

SRC2 = server.c \
	minitalk_utils.c \
	minitalk_utils2.c

SRC_BONUS = ./bonus/client_bonus.c \
	./bonus/minitalk_utils_bonus.c \
	./bonus/minitalk_utils2_bonus.c

SRC2_BONUS = ./bonus/server_bonus.c \
	./bonus/minitalk_utils_bonus.c \
	./bonus/minitalk_utils2_bonus.c

SRC_CLEAN = client.c \
	minitalk_utils.c \
	minitalk_utils2.c \
	server.c \
	./bonus/client_bonus.c \
	./bonus/minitalk_utils_bonus.c \
	./bonus/minitalk_utils2_bonus.c \
	./bonus/server_bonus.c

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJ2_BONUS = $(SRC2_BONUS:.c=.o)

OBJ_CLEAN = $(SRC_CLEAN:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(NAME2)

bonus: $(NAME_BONUS) $(NAME2_BONUS)

$(NAME): $(OBJ)
	gcc $(FLAGS) $^ -o $(NAME)

$(NAME2): $(OBJ2)
	gcc $(FLAGS) $^ -o $(NAME2)

$(NAME_BONUS): $(OBJ_BONUS)
	gcc $(FLAGS) $^ -o $(NAME_BONUS)

$(NAME2_BONUS): $(OBJ2_BONUS)
	gcc $(FLAGS) $^ -o $(NAME2_BONUS)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLEAN)

fclean: clean
	rm -f $(NAME) $(NAME2) $(NAME_BONUS) $(NAME2_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
