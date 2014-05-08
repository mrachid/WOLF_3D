# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/13 14:11:55 by mrachid           #+#    #+#              #
#    Updated: 2014/01/19 18:11:27 by mrachid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Werror -Wextra

DIR_LIBS = /usr/X11/lib

XFLAGS = -L$(DIR_LIBS) -lXext -lX11 -lmlx

SRCS = main.c touch.c img.c ft_hearts.c key_hook.c part1.c

.PHONY: clean all re fclean

all: $(NAME)

make:
	@make -C libft/

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) -L libft $(XFLAGS) -lft -g

%.o : %.c
	@make -C libft/
	@gcc -g -I libft/includes/ $(FLAG) -c $^
	@echo "\033[34m[..: The program has been compiled :..]\033[0m"

clean:
	@make -C libft/ clean
	@/bin/rm -rf $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

