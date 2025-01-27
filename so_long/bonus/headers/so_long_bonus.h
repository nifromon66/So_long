/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:39:01 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/27 05:51:33 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// Includes
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../../mlx/mlx_int.h"
# include "../../mlx/mlx.h"
# include "../../libft/headers/ft_printf_H/ft_printf.h"
# include "../../libft/headers/get_next_line_H/get_next_line.h"
# include "../../libft/headers/libft_H/libft.h"
# include "./so_long_typedef_bonus.h"
# include "./so_long_define_bonus.h"

// Functions
// sl_map_manager
	// so_long.c
void	sl_map_manager(t_sl_map **map);
	// sl_map_init_manager.c
void	sl_map_init_manager(t_sl_map **map, t_sl_pos **spawn, t_sl_pos **exit);
int		sl_map_init_map_data(t_sl_map **map);
int		sl_map_init_positions(t_sl_pos **spawn, t_sl_pos **exit);
int		sl_map_init_directions(t_sl_map **map);
int		sl_map_init_visited(t_sl_map **map, int height, int width);
	// sl_map_read.c
int		sl_map_check_format(char *file);
void	sl_map_read(t_sl_map **map);
	// sl_map_check_manager.c
void	sl_map_check_manager(t_sl_map **map);
int		sl_map_check_rectangle(char **map, int x, int y);
int		sl_map_check_closed(char **map, int x, int y);
int		sl_map_check_char(char **map, int x, int y, int *count_c);
	// sl_map_path_manager.c
void	sl_map_path_manager(t_sl_map **map);
int		sl_map_path_to_exit(t_sl_map **map, int x, int y);
int		sl_map_path_to_collect(t_sl_map **map, int x, int y, int *count_c);
void	sl_map_find_spawn(char **map, int x, int y, t_sl_pos **spawn);
void	sl_map_find_exit(char **map, int x, int y, t_sl_pos **exit);
// sl_game_manager   
	// so_long.c
void	sl_game_manager(t_sl_game **game);
	// sl_game_init_manager.c
void	sl_game_init_manager(t_sl_game **game, t_sl_map **map, t_sl_img **img);
int		sl_game_init_window(t_sl_game **game);
int		sl_game_init_image(void *mlx_p, t_sl_img **img);
	// sl_game_interaction_manager.c
void	sl_game_interact_manager(t_sl_game **game, void *win_p);
int		sl_game_key(int key, t_sl_game **game);
int		sl_game_cross(t_sl_game **game);
	// sl_game_movement_manager.c
void	sl_game_movement_manager(int move, t_sl_game **game, t_sl_map **map);
int		sl_player_move_up(t_sl_game **game, char **map, int *count_c);
int		sl_player_move_down(t_sl_game **game, char **map, int *count_c);
int		sl_player_move_left(t_sl_game **game, char **map, int *count_c);
int		sl_player_move_right(t_sl_game **game, char **map, int *count_c);
	// sl_game_update_manager.c
void	sl_game_update_manager(int xpm, int form, int pos[], t_sl_game **game);
void	sl_game_update_tile(int move, int pos[], t_sl_game **game);
void	sl_game_update_player(int form, t_sl_game **game);
void	sl_game_update_player_exit(int form, t_sl_game **game);
void	sl_game_update_exit(int form, t_sl_game **game);
	// sl_game_images_swap.c
void	sl_game_images_swap(t_sl_game **game, void **img, char *new);
	// sl_game_render_manager.c
int		sl_game_render_manager(t_sl_game **game);
void	sl_game_render(t_sl_game **game, t_sl_img **img, t_sl_map **map);
void	my_img_to_win(t_sl_game **game, void *img, int x, int y);
// error_manager
	// so_long.c
void	sl_error_map(char *error, t_sl_map **map);
void	sl_error_game(char *error, int level, t_sl_map **map, t_sl_game **game);
// memory_manager
	// allocation_manager.c
int		my_realloc(void **ptr, int old_size, int new_size);
	// sl_free_map_data.c
void	sl_free_map_data(t_sl_map **map);
void	sl_free_map(t_sl_map **map, int y);
void	sl_free_pos(t_sl_pos **spawn, t_sl_pos **exit, t_sl_pos **foe);
void	sl_free_visited(t_sl_map **map, int y);
	// sl_free_game_data.c
void	sl_free_game_data(t_sl_game **game);
void	sl_free_game_img(void *mlx_p, t_sl_img **img);
void	sl_free_images(void *mlx_p, void **img);

// Bonus fonctions
// sl_game_manager
	// sl_game_interactions_manager.c
void	sl_draw_large_text_bonus(t_sl_game **game, int x, int y, char *str);
	// sl_game_render_manager.c
void	sl_game_render_player(t_sl_game **game, t_sl_map **map, t_sl_pos **ext);
void	sl_game_render_foe(t_sl_game **game, t_sl_pos **foe, int x, int y);
	// sl_game_animation_player.c
void	sl_game_animation_player(t_sl_game **game, int move, int pos[]);
void	sl_game_animation_pr(t_sl_game **game, t_sl_img **img, int x, int y);
void	sl_game_animation_pl(t_sl_game **game, t_sl_img **img, int x, int y);
void	sl_game_animation_pre(t_sl_game **game, t_sl_img **img, int x, int y);
void	sl_game_animation_ple(t_sl_game **game, t_sl_img **img, int x, int y);
	// sl_game_animation_foe.c
void	sl_game_animation_foe(t_sl_game **game, int move, t_sl_pos *foe);
void	sl_game_animation_fo(t_sl_game **game, t_sl_img **img, int x, int y);
void	sl_game_animation_fc(t_sl_game **game, t_sl_img **img, int x, int y);
void	sl_game_animation_fb(t_sl_game **game, t_sl_img **img, int x, int y);
void	sl_game_animation_boom(t_sl_game **game, t_sl_img **img, int x, int y);
	// sl_game_foe_manager.c
void	sl_game_place_foe(t_sl_map **map, t_sl_pos **foe);
void	sl_game_update_foe_pos(t_sl_pos **foe, int move, int i);
void	sl_game_foe_patrol(t_sl_game **game, t_sl_pos **foe, int x, int y);
void	sl_game_foe_move(t_sl_game **game, int dx, int dy, int i);

# define UNDEFINE_SO_LONG_BONUS_MACROS

#endif
