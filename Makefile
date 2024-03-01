# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 17:35:15 by bsantana          #+#    #+#              #
#    Updated: 2024/02/29 15:48:06 by bsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors to print message
GREEN := \033[1;32m
WHITE := \033[1;37m

# Executable name
NAME	:= so_long
NAME_BONUS	:= so_long_bonus

# Flags
CFLAGS	:=  -Wextra -Wall -Werror

# Libraries path
LIBMLX	:= ./MLX42
LIBFT_PATH := ./libft/
LIBFT := $(addprefix $(LIBFT_PATH), libft.a)

# Files

# Source directory where .c files are located
SRC_DIR:= src
SRC_DIR_BONUS:= src_bonus

# List of source files
FILES_SRC := flood_fill.c game.c hooks.c images_draw.c images_put.c map_utils.c map.c \
			updates.c validations.c

FILES_SRC_BONUS := animations_bonus.c flood_fill_bonus.c game_bonus.c hooks_bonus.c \
				image_steps_bonus.c images_draw_bonus.c images_put_bonus.c map_bonus.c \
				map_utils_bonus.c updates_bonus.c validations_bonus.c moves_bonus.c moves_utils_bonus.c
					
# List of object files derived from source files
FILES_SRC_O := $(FILES_SRC:.c=.o)
FILES_SRC_BONUS_O := $(FILES_SRC_BONUS:.c=.o)

# List of header files directories
HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
HEADERS_FILE := ./include/so_long.h ./include/so_long_bonus.h

# List of libraries to link against
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Get the list of source files with the correct path
SRCS	:= $(addprefix $(SRC_DIR)/, $(FILES_SRC))
OBJS	:= ${addprefix $(SRC_DIR)/, $(FILES_SRC_O)}
SRCS_BONUS	:= ${addprefix $(SRC_DIR_BONUS)/, $(FILES_SRC_BONUS)}
OBJS_BONUS	:= ${addprefix $(SRC_DIR_BONUS)/, $(FILES_SRC_BONUS_O)}

# Compile MLX library
all: libmlx $(NAME)

bonus: libmlx $(NAME_BONUS)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# Compile LIBFT library
$(LIBFT):
	@make -C $(LIBFT_PATH)

# Compile .c file into .o file
%.o: ./src_bonus/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

# Build the final executable
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)\nCompilation complete! Use the so_long executable to start playing!"

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) $(LIBFT) -o $(NAME_BONUS)
	@echo "$(GREEN)\nCompilation complete! Use the so_long_bonus executable to start playing!"
	
# Clean object files
clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)

# Clean everything (including temporary build artifacts)
fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@rm -rf $(LIBMLX)/build
	@make fclean -C$(LIBFT_PATH)
	@echo "$(WHITE)\nCleaning - SO LONG - completed!"

# Clean and rebuild everything
re: clean all

# Targets that are not associated with files
.PHONY: all, clean, fclean, re, libmlx, libft