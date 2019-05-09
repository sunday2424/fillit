# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junpark <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/07 11:42:40 by junpark           #+#    #+#              #
#    Updated: 2019/05/07 16:25:56 by junpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c lstfn.c solve.c blocks.c map.c valid.c

OBJ = $(SRC:.c=.o)

LIBFT = libft -lft

INCLUDES = fillit.h

$(NAME):
	@make -C $(LIBFT)
	@gcc -c -Wall -Werror -Wextra $(SRC) -I$(INCLUDES)
	@gcc $(OBJ) -L $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re