# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 15:19:47 by nifromon          #+#    #+#              #
#    Updated: 2025/01/27 01:28:54 by nifromon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Argument
NAME =					so_long
NAME_BONUS =			so_long_bonus

# Compilation
CC =					@gcc
CFLAGS =				-Wall -Werror -Wextra -L $(LIBFT_DIR)/
MFLAGS = 				-L $(MLX_DIR)/ -L /usr/include/X11/ \
						-L /usr/lib/x86_64-linux-gnu/ \
						-lmlx -lXext -lX11 -lXrandr -lm -lbsd -lXfixes

INCLUDES = 				-I $(HEADER_DIR)/ -I $(LIBFT_DIR)/headers/ -I $(MLX_DIR)/ \
						-I /usr/include/X11/ -I /usr/include/X11/extensions/ \
						-I /usr/lib/x86_64-linux-gnu/

INCLUDE_BONUS = 		-I $(HEADER_BONUS_DIR)/ -I $(LIBFT_DIR)/headers/ -I $(MLX_DIR)/ \
						-I /usr/include/X11/ -I /usr/include/X11/extensions/ \
						-I /usr/lib/x86_64-linux-gnu/

# Directories
SRC_DIR =				mandatory/src
UTILS_DIR =				mandatory/utils
HEADER_DIR =			mandatory/headers

OBJ_DIR =				obj
OBJ_SRC_DIR =			$(OBJ_DIR)/src_obj
OBJ_UTILS_DIR =			$(OBJ_DIR)/utils_obj

SRC_BONUS_DIR =			bonus/src
UTILS_BONUS_DIR =		bonus/utils
HEADER_BONUS_DIR =		bonus/headers

OBJ_BONUS_DIR =			obj_bonus
OBJ_SRC_BONUS_DIR =		$(OBJ_BONUS_DIR)/src_obj
OBJ_UTILS_BONUS_DIR =	$(OBJ_BONUS_DIR)/utils_obj

MLX_DIR =				mlx
MLX =					$(MLX_DIR)/libmlx.a

LIBFT_DIR =				libft
LIBFT =					$(LIBFT_DIR)/libft_inc.a

# Utils
RM =					@rm -rf

# Colors
BLACK =					\033[1;30m
RED =					\033[1;31m
GREEN =					\033[1;32m
YELLOW =				\033[1;33m
BLUE =					\033[1;34m
PURPLE =				\033[1;35m
CYAN =					\033[1;36m
WHITE =					\033[1;37m
RESET =					\033[1;0m

# Sources and objects
SRC =					\
						$(SRC_DIR)/so_long.c


OBJ_SRC =				$(SRC:$(SRC_DIR)/%.c=$(OBJ_SRC_DIR)/%.o)

UTILS =					\
						$(UTILS_DIR)/sl_map_manager/sl_map_init_manager.c \
						$(UTILS_DIR)/sl_map_manager/sl_map_read.c \
						$(UTILS_DIR)/sl_map_manager/sl_map_check_manager.c \
						$(UTILS_DIR)/sl_map_manager/sl_map_path_manager.c \
						$(UTILS_DIR)/sl_game_manager/sl_game_init_manager.c \
						$(UTILS_DIR)/sl_game_manager/sl_game_render_manager.c \
						$(UTILS_DIR)/sl_game_manager/sl_game_interactions_manager.c \
						$(UTILS_DIR)/sl_game_manager/sl_game_movement_manager.c \
						$(UTILS_DIR)/sl_game_manager/sl_game_update_manager.c \
						$(UTILS_DIR)/sl_game_manager/sl_game_images_swap.c \
						$(UTILS_DIR)/sl_memory_manager/sl_allocation_manager.c \
						$(UTILS_DIR)/sl_memory_manager/sl_free_map_data.c \
						$(UTILS_DIR)/sl_memory_manager/sl_free_game_data.c

OBJ_UTILS =				$(UTILS:$(UTILS_DIR)/%.c=$(OBJ_UTILS_DIR)/%.o)

SRC_BONUS =				\
						$(SRC_BONUS_DIR)/so_long_bonus.c


OBJ_SRC_BONUS =			$(SRC_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_SRC_BONUS_DIR)/%.o)

UTILS_BONUS =			\
						$(UTILS_BONUS_DIR)/sl_map_manager/sl_map_init_manager.c \
						$(UTILS_BONUS_DIR)/sl_map_manager/sl_map_read.c \
						$(UTILS_BONUS_DIR)/sl_map_manager/sl_map_check_manager.c \
						$(UTILS_BONUS_DIR)/sl_map_manager/sl_map_path_manager.c \
						$(UTILS_BONUS_DIR)/sl_game_manager/sl_game_init_manager.c \
						$(UTILS_BONUS_DIR)/sl_game_manager/sl_game_render_manager_bonus.c \
						$(UTILS_BONUS_DIR)/sl_game_manager/sl_game_interactions_manager_bonus.c \
						$(UTILS_BONUS_DIR)/sl_game_manager/sl_game_movement_manager_bonus.c \
						$(UTILS_BONUS_DIR)/sl_game_manager/sl_game_update_manager.c \
						$(UTILS_BONUS_DIR)/sl_game_manager/sl_game_foe_manager_bonus.c \
						$(UTILS_BONUS_DIR)/sl_game_manager/sl_game_animation_player_bonus.c \
						$(UTILS_BONUS_DIR)/sl_game_manager/sl_game_animation_foe_bonus.c \
						$(UTILS_BONUS_DIR)/sl_game_manager/sl_game_images_swap.c \
						$(UTILS_BONUS_DIR)/sl_memory_manager/sl_allocation_manager.c \
						$(UTILS_BONUS_DIR)/sl_memory_manager/sl_free_map_data.c \
						$(UTILS_BONUS_DIR)/sl_memory_manager/sl_free_game_data.c

OBJ_UTILS_BONUS =		$(UTILS_BONUS:$(UTILS_BONUS_DIR)/%.c=$(OBJ_UTILS_BONUS_DIR)/%.o)

# Rules and dependencies
all:					$(LIBFT) $(MLX) $(NAME)

$(LIBFT):
						@echo "$(YELLOW)[-------------]COMPILING ᕦ(òᴥó)ᕥ SO_LONG...[-------------]$(RESET)\n\n"
						@echo "$(PURPLE)o()xxxx[]::::::::::::::::::>	Building Libft...$(RESET)"
						@make -s -C $(LIBFT_DIR) all
						@echo "$(GREEN)o()xxxx[]::::::::::::::::::>	Successfully built Libft !$(RESET)\n"

$(MLX):
						@echo "$(PURPLE)o()xxxx[]::::::::::::::::::>	Building MinilibX...$(RESET)"
						@make -s -C $(MLX_DIR) all >/dev/null 2>&1
						@echo "$(GREEN)o()xxxx[]::::::::::::::::::>	Successfully built MinilibX !$(RESET)"

$(NAME): 				$(LIBFT) $(MLX) $(OBJ_SRC) $(OBJ_UTILS)
						$(CC) $(OBJ_SRC) $(OBJ_UTILS) $(LIBFT) $(MLX) -o $(NAME) $(CFLAGS) $(INCLUDES) $(MFLAGS)
						@echo "\n\n$(GREEN)[-----]ʕ·͡ᴥ·ʔ SUCCESSFULLY COMPILED SO_LONG...ʕ·͡ᴥ·ʔ[-----]$(RESET)\n\n"

$(OBJ_SRC_DIR)/%.o: $(SRC_DIR)/%.c
						@mkdir -p $(OBJ_DIR)
						@mkdir -p $(OBJ_SRC_DIR)
						$(CC) -s -c $(CFLAGS) $(INCLUDES) $(MFLAGS) $< -o $@

$(OBJ_UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
						@mkdir -p $(OBJ_DIR)
						@mkdir -p $(OBJ_UTILS_DIR)
						@mkdir -p $(OBJ_UTILS_DIR)/sl_map_manager
						@mkdir -p $(OBJ_UTILS_DIR)/sl_game_manager
						@mkdir -p $(OBJ_UTILS_DIR)/sl_memory_manager
						$(CC) -s -c $(CFLAGS) $(INCLUDES) $(MFLAGS) $< -o $@

bonus:					$(LIBFT) $(MLX) $(NAME_BONUS)

$(NAME_BONUS):			$(LIBFT) $(MLX) $(OBJ_SRC_BONUS) $(OBJ_UTILS_BONUS)
						$(CC) $(OBJ_SRC_BONUS) $(OBJ_UTILS_BONUS) $(LIBFT) $(MLX) -o $(NAME_BONUS) $(CFLAGS) $(INCLUDES_BONUS) $(MFLAGS)
						@echo "\n\n$(GREEN)[-----]ʕ·͡ᴥ·ʔ SUCCESSFULLY COMPILED SO_LONG_BONUS...ʕ·͡ᴥ·ʔ[-----]$(RESET)\n\n"

$(OBJ_SRC_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
						@mkdir -p $(OBJ_BONUS_DIR)
						@mkdir -p $(OBJ_SRC_BONUS_DIR)
						$(CC) -s -c $(CFLAGS) $(INCLUDES_BONUS) $(MFLAGS) $< -o $@

$(OBJ_UTILS_BONUS_DIR)/%.o: $(UTILS_BONUS_DIR)/%.c
						@mkdir -p $(OBJ_BONUS_DIR)
						@mkdir -p $(OBJ_UTILS_BONUS_DIR)
						@mkdir -p $(OBJ_UTILS_BONUS_DIR)/sl_map_manager
						@mkdir -p $(OBJ_UTILS_BONUS_DIR)/sl_game_manager
						@mkdir -p $(OBJ_UTILS_BONUS_DIR)/sl_memory_manager
						$(CC) -s -c $(CFLAGS) $(INCLUDES_DIR) $(MFLAGS) $< -o $@

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
						$(RM) $(OBJ_BONUS_DIR)

fclean:					clean
						@make -s -C $(LIBFT_DIR) fclean
						$(RM) $(NAME)
						$(RM) $(NAME_BONUS)

re:						fclean all

re_bonus:				fclean bonus

.PHONY:					all bonus clean fclean re re_bonus
