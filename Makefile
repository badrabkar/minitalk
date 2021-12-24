# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babkar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 11:32:09 by babkar            #+#    #+#              #
#    Updated: 2021/12/24 04:10:41 by babkar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client

NAME2 = server

NAME1_BONUS = client_bonus

NAME2_BONUS = server_bonus

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC1 =  client.c minitalk_utils.c

SRC2 =  server.c minitalk_utils.c

SRC1_BONUS = client_bonus.c minitalk_utils_bonus.c

SRC2_BONUS = server_bonus.c minitalk_utils_bonus.c

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

OBJ1_BONUS = $(SRC1_BONUS:.c=.o)

OBJ2_BONUS = $(SRC2_BONUS:.c=.o)

%.o: %.c minitalk.h minitalk_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME1) $(NAME2) $(NAME1_BONUS) $(NAME2_BONUS)

$(NAME1_BONUS): $(OBJ1_BONUS)
	$(CC) $(FLAGS) -o $@ $^

$(NAME2_BONUS): $(OBJ2_BONUS)
	$(CC) $(FLAGS) -o $@ $^

$(NAME1): $(OBJ1) 
	$(CC) $(FLAGS) -o $@ $^

$(NAME2): $(OBJ2)
	$(CC) $(FLAGS) -o $@ $^

clean:
	$(RM) $(OBJ1) $(OBJ2) $(OBJ1_BONUS) $(OBJ2_BONUS)

fclean: clean
	$(RM) $(NAME1) $(NAME2) $(NAME1_BONUS) $(NAME2_BONUS)

re: fclean all
