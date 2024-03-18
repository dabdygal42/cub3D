# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 15:43:23 by dabdygal          #+#    #+#              #
#    Updated: 2024/03/18 14:45:28 by dabdygal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *********************************INITIALIZE********************************* #

BIN_NAME = cub3D

SRC_DIR = src

OBJ_DIR = src

LIBFT_NAME = libft.a

LIBFT_DIR = libft

LIBMLX_NAME = libmlx.dylib

LIBMLX_DIR = minilibx_mms_20200219

INCLUDE_DIR = include

INCLUDE_FILES = cub3D.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR) -I $(LIBMLX_DIR) -L $(LIBMLX_DIR) -lmlx -framework OpenGL -framework AppKit -lz

SRC_FILES = main.c

MAIN_DIR = .

MAIN_FILE = main.c

OBJ_FILES = $(SRC_FILES:.c=.o)

# ************************************RULES*********************************** #

$(BIN_NAME): $(LIBMLX_NAME) $(LIBFT_NAME) $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(SRC_DIR)/,$(SRC_FILES)) $(addprefix $(INCLUDE_DIR)/,$(INCLUDE_FILES))
	$(CC) $(CFLAGS) $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) $(addprefix $(SRC_DIR)/,$(SRC_FILES)) -o $(BIN_NAME)

$(LIBFT_NAME):
	make $(LIBFT_NAME) -C $(LIBFT_DIR)
	cp $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) .

$(LIBMLX_NAME):
	make $(LIBMLX_NAME) -C $(LIBMLX_DIR)
	cp $(addprefix $(LIBMLX_DIR)/,$(LIBMLX_NAME)) .

all: $(BIN_NAME)

clean:
	rm -f $(LIBFT_NAME)
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)

fclean: clean
	rm -f $(BIN_NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
