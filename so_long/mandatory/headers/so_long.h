/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:39:01 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/23 21:47:28 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes
# include <fcntl.h>
# include <stdio.h>
# include "../../mlx/mlx.h"
# include "../../libft/headers/libft_H/libft.h"

// Colors
# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"
# define RESET		"\033[0;0m"

// Keycodes
# define KEY_ESC	0xff1b
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

// Tile size
# define TILE		192

// Assets
	// Background
# define WALL		"./assets/wall/wall.xpm"
# define FLOOR		"./assets/floor/floor.xpm"
# define EXIT_OFF	"./assets/exit/exit_off.xpm"
# define EXIT_ON	"./assets/exit/exit_on.xpm"
	// Collectibles
# define COLLECT	"./assets/collect/collect.xpm"
	// Player Basic
# define PLAYERR	"./assets/player/player_right.xpm"
# define PLAYERL	"./assets/player/player_left.xpm"
	// Player on exit off
# define PLAYER_RE	"./assets/player/player_on_exit_right.xpm"
# define PLAYER_LE	"./assets/player/player_on_exit_left.xpm"

// Structures
	// Positions
typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;
	// Map
typedef struct s_map
{
	t_pos	**spawn;
	t_pos	**exit;
	char	**map;
	char	*file;
	int		**visited;
	int		dx[4];
	int		dy[4];
	int		fd;
	int		width;
	int		height;
	int		count_c;
	int		count_c_mlx;
}			t_map;
	// Image
typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*collect;
	void	*player;
	void	*exit;
}			t_img;
	// MLX
typedef struct s_mlx
{
	t_map	**map;
	t_img	**img;
	void	*mlx_p;
	void	*win_p;
	int		biome_x;
	int		biome_y;
	int		moves;
	int		screen_x;
	int		screen_y;
}			t_mlx;

// Functions
// map_manager
	// main.c
void	map_manager(t_map **map);
	// map_init_manager.c
void	map_init_manager(t_map **map, t_pos **spawn, t_pos **exit);
int		map_init_map_data(t_map **map);
int		map_init_positions(t_pos **spawn, t_pos **exit);
int		map_init_directions(t_map **map);
int		map_init_visited(t_map **map, int height, int width);
	// map_read.c
int		map_check_format(char *file);
void	map_read(t_map **map);
	// map_check_manager.c
void	map_check_manager(t_map **map);
int		map_check_rectangle(char **map, int x, int y);
int		map_check_closed(char **map, int x, int y);
int		map_check_char(char **map, int x, int y, int *count_c);
	// map_path_manager.c
void	map_path_manager(t_map **map);
int		map_path_to_exit(t_map **map, int x, int y);
int		map_path_to_collect(t_map **map, int x, int y, int *count_c);
void	map_find_spawn(char **map, int x, int y, t_pos **spawn);
void	map_find_exit(char **map, int x, int y, t_pos **exit);
// mlx_manager
	// main.c
void	mlx_manager(t_mlx **mlx);
	// mlx_init_manager.c
void	mlx_init_manager(t_mlx **mlx, t_map **map, t_img **img);
int		mlx_init_window(t_mlx **mlx);
int		mlx_init_image(void *mlx_p, t_img **img);
	// mlx_interaction_manager.c
void	mlx_interact_manager(t_mlx **mlx, void *win_p);
int		mlx_key(int key, t_mlx **mlx);
int		mlx_cross(t_mlx **mlx);
	// mlx_movement_manager.c
void	mlx_movement_manager(int move, t_mlx **mlx, t_map **map);
int		move_up(t_mlx **mlx, char **map, int *count_c);
int		move_down(t_mlx **mlx, char **map, int *count_c);
int		move_left(t_mlx **mlx, char **map, int *count_c);
int		move_right(t_mlx **mlx, char **map, int *count_c);
	// mlx_update_manager.c
void	mlx_update_manager(int asset, int form, int pos[], t_mlx **mlx);
void	mlx_update_tile(int move, int pos[], t_mlx **mlx);
void	mlx_update_player(int form, t_mlx **mlx);
void	mlx_update_player_exit(int form, t_mlx **mlx);
void	mlx_update_exit(int form, t_mlx **mlx);
	// mlx_images_swap.c
void	mlx_images_swap(t_mlx **mlx, void **img, char *new);
	// mlx_render_manager.c
int		mlx_render_manager(t_mlx **mlx);
void	mlx_render(t_mlx **mlx, t_img **img, t_map **map);
void	my_img_to_win(t_mlx **mlx, void *img, int x, int y);
// error_manager
	// main.c
void	error_map(char *error, t_map **map);
void	error_mlx(char *error, int level, t_map **map, t_mlx **mlx);
// memory_manager
	// allocation_manager.c
int		my_realloc(void **ptr, int old_size, int new_size);
	// free_map_data.c
void	free_map_data(t_map **map);
void	free_map(t_map **map, int y);
void	free_positions(t_pos **spawn, t_pos **exit);
void	free_visited(t_map **map, int y);
	// free_mlx_data.c
void	free_mlx_data(t_mlx **mlx);
void	free_mlx_img(void *mlx_p, t_img **img);
void	free_img(void *mlx_p, void **img);

#endif
