# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 01:52:54 by tbouzalm          #+#    #+#              #
#    Updated: 2022/08/19 16:49:38 by tbouzalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

NAME = philo

FLAGS = -Wall -Wextra -Werror

HEADER = ./philo.h

SRC = 	parsing.c \
		philo.c \
		time.c \
		action.c \
		create_thread.c \
		died.c \

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $(NAME) 

%.o : %.c
	$(CC) -c $< -o $@ $(FLAGS)

all : $(NAME)

clean : 
	rm  -rf *.o
fclean : clean
	rm -rf $(NAME)
re : fclean all 