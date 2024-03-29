# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 15:43:23 by dabdygal          #+#    #+#              #
#    Updated: 2024/03/18 15:55:34 by dabdygal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *********************************INITIALIZE********************************* #

BIN_NAME = cub3D

SRC_DIR = src

SRC_FILES = main.c

INCLUDE_DIR = include

INCLUDE_FILES = cub3D.h

LIBFT_NAME = libft.a

LIBFT_DIR = libft

LIBMLX_NAME = libmlx.a

LIBMLX_DIR = minilibx_opengl_20191021

CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(LIBMLX_DIR) -L$(LIBMLX_DIR) -lmlx -framework OpenGL -framework AppKit -lz

# ************************************RULES*********************************** #

$(BIN_NAME): $(addprefix $(LIBMLX_DIR)/,$(LIBMLX_NAME)) $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) $(addprefix $(SRC_DIR)/,$(SRC_FILES)) $(addprefix $(INCLUDE_DIR)/,$(INCLUDE_FILES))
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR)/,$(SRC_FILES)) $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) -o $(BIN_NAME)

$(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)):
	make $(LIBFT_NAME) -C $(LIBFT_DIR)

$(addprefix $(LIBMLX_DIR)/,$(LIBMLX_NAME)):
	make $(LIBMLX_NAME) -C $(LIBMLX_DIR)

all: $(BIN_NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)

fclean: clean
	rm -f $(BIN_NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
