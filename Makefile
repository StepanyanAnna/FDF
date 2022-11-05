# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 20:47:03 by annstepa          #+#    #+#              #
#    Updated: 2022/11/03 20:53:12 by annstepa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf

CC 			= gcc

CFLAGS 		= -Wall -Wextra -Werror

MLX 		= -lmlx -L ./mlx -framework AppKit -framework OpenGL

SRCS		= $(shell find "." -maxdepth 1 -name '*.c' ! -name "*_bonus.c")

BONUS_SRCS 	= $(shell find "." -maxdepth 1 -name '*.c' ! -name "fdf.c")

OBJS 		= $(SRCS:%.c=%.o)

BONUS_OBJS	= $(BONUS_SRCS:%.c=%.o)

%.c:
	@$(CC) $(CFLAGS) $(BONUS_SRCS)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX) -o $(NAME)
	@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@rm -f ./*.o
	@echo -e "$(YELLOW) Object files deleted!$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo -e "$(RED)All deleted!$(DEFAULT)"

bonus: $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(MLX) -o $(NAME)
	@echo -e "$(GREEN)$(NAME)_bonus created!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

