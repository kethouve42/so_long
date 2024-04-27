# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 17:05:57 by kethouve          #+#    #+#              #
#    Updated: 2024/03/08 18:10:34 by kethouve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

CC = cc

FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm

SRC_DIR = ./src/

SRC_BNS_DIR = ./src_bonus/

SRC = $(addprefix $(SRC_DIR),\
		so_long.c key_event.c image.c \
		get_next_line.c get_next_line_utils.c \
		ft_print.c move.c map.c ft_strdup.c)

SRC_BNS = $(addprefix $(SRC_BNS_DIR),\
			so_long.c key_event.c image.c \
			get_next_line.c get_next_line_utils.c \
			ft_print.c move.c map.c ft_strdup.c \
			ft_itoa.c move_ennemy.c verif_move.c)

INCLUDES = -I/usr/include -Imlx

$(NAME) :
		@echo "[ .. ] | Compiling so_long"
		$(CC) $(SRC) $(FLAGS) $(MLX_FLAGS) -o $@ 
		@echo "[ OK ] | so_long ready!"

$(NAME_BONUS) :
		@echo "[ .. ] | Compiling so_long_bonus"
		$(CC) $(SRC_BNS) $(FLAGS) $(MLX_FLAGS) -o $@ 
		@echo "[ OK ] | so_long_bonus ready!"


all: $(NAME)

bonus : $(NAME_BONUS)

%.o : %.c $(HEADER_FILE)
		$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

clean :
		rm -f $(OBJ)
		@echo "object files removed."

fclean : clean
		rm -f $(NAME) $(NAME_BONUS)
		@echo "binary files removed."

re : fclean all

.PHONY : all clean fclean re