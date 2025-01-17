# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 15:19:47 by nifromon          #+#    #+#              #
#    Updated: 2025/01/17 18:20:30 by nifromon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Argument
NAME =				so_long

# Compilation
CC =				@gcc
CFLAGS =			-Wall -Werror -Wextra -L $(LIBFT_DIR)
MFLAGS =			-L $(MLX_DIR) -lm -lmlx -lft -lXext -lX11
INCLUDES =			-I $(HEADER_DIR)/ -I $(LIBFT_DIR)/headers -I $(MLX_DIR)/

# Directories
SRC_DIR =			core/src
UTILS_DIR =			core/utils
HEADER_DIR =		core/headers

OBJ_DIR =			obj
OBJ_SRC_DIR =		$(OBJ_DIR)/src_obj
OBJ_UTILS_DIR =		$(OBJ_DIR)/utils_obj

MLX_DIR =			mlx
MLX =				$(MLX_DIR)/libmlx.a

LIBFT_DIR =			libft
LIBFT =				$(LIBFT_DIR)/libft.a

# Utils
RM =				@rm -rf

# Colors
BLACK =				\033[1;30m
RED =				\033[1;31m
GREEN =				\033[1;32m
YELLOW =			\033[1;33m
BLUE =				\033[1;34m
PURPLE =			\033[1;35m
CYAN =				\033[1;36m
WHITE =				\033[1;37m
RESET =				\033[1;0m

# Sources and objects
SRC =				\
					$(SRC_DIR)/main.c


OBJ_SRC =			$(SRC:$(SRC_DIR)/%.c=$(OBJ_SRC_DIR)/%.o)

UTILS =				\
					$(UTILS_DIR)/error_manager.c $(UTILS_DIR)/utils.c \
					$(UTILS_DIR)/map_manager.c $(UTILS_DIR)/free_manager.c \
					$(UTILS_DIR)/allocation_manager.c

OBJ_UTILS =			$(UTILS:$(UTILS_DIR)/%.c=$(OBJ_UTILS_DIR)/%.o)

# Rules and dependencies
all:				$(LIBFT) $(MLX) $(NAME)

$(LIBFT):
					@echo "$(YELLOW)[-------------]COMPILING ᕦ(òᴥó)ᕥ SO_LONG...[-------------]$(RESET)\n\n"
					@echo "$(PURPLE)o()xxxx[]::::::::::::::::::>	Building Libft...$(RESET)"
					@make -s -C $(LIBFT_DIR) all
					@echo "$(GREEN)o()xxxx[]::::::::::::::::::>	Successfully built Libft !$(RESET)\n"

$(MLX):
					@echo "$(PURPLE)o()xxxx[]::::::::::::::::::>	Building MinilibX...$(RESET)"
					@make -s -C $(MLX_DIR) all >/dev/null 2>&1
					@echo "$(GREEN)o()xxxx[]::::::::::::::::::>	Successfully built MinilibX !$(RESET)"

$(NAME):			$(LIBFT) $(MLX) $(OBJ_SRC) $(OBJ_UTILS)
					$(CC) $(CFLAGS) $(MFLAGS) $(INCLUDES) $(OBJ_SRC) $(OBJ_UTILS) $(LIBFT) $(MLX) -o $(NAME)
					@echo "\n\n$(GREEN)[-----]ʕ·͡ᴥ·ʔ SUCCESSFULLY COMPILED SO_LONG...ʕ·͡ᴥ·ʔ[-----]$(RESET)\n\n"

$(OBJ_SRC_DIR)/%.o: $(SRC_DIR)/%.c
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_SRC_DIR)
					$(CC) -s -c $(CFLAGS) $(INCLUDES) $< -o $@

$(OBJ_UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_UTILS_DIR)
					$(CC) -s -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
					@echo "$(YELLOW)[-------------]CLEANING ᕦ(òᴥó)ᕥ SO_LONG...[-------------]$(RESET)\n\n"
					@echo "$(CYAN)o()xxxx[]::::::::::::::::::>	Cleaning MinilibX...$(RESET)"
					@make -s -C $(MLX_DIR) clean >/dev/null 2>&1
					@echo "$(GREEN)o()xxxx[]::::::::::::::::::>	Successfully cleaned MinilibX !$(RESET)\n"
					@echo "$(CYAN)o()xxxx[]::::::::::::::::::>	Cleaning Libft...$(RESET)"
					@make -s -C $(LIBFT_DIR) clean
					@echo "$(GREEN)o()xxxx[]::::::::::::::::::>	Successfully cleaned Libft !$(RESET)"
					@echo "\n\n$(GREEN)[-----]ʕ·͡ᴥ·ʔ SUCCESSFULLY CLEANED SO_LONG...ʕ·͡ᴥ·ʔ[-----]$(RESET)\n\n"
					$(RM) $(OBJ_DIR)

fclean:				clean
					@make -s -C $(LIBFT_DIR) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
