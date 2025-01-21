/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:06:58 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/21 01:26:11 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../../mlx/mlx_int.h"
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

// Macros
	// Textures
// Basic Texture files
# define WALL		"./texture_library/wall.xpm"
# define FLOOR		"./texture_library/floor.xpm"
# define COLLECT	"./texture_library/collectibles.xpm"
# define PLAYER		"./texture_library/player.xpm"
# define EXIT		"./texture_library/exit.xpm"
// Medium Texture files
# define P_E		"./texture_library/player_on_exit.xpm"

// Structures
typedef struct s_map
{
	char	*file;
	char	**map;
	int		**visited;
	int		dx[4];
	int		dy[4];
	int		fd;
	int		w;
	int		h;
	int		file_len;
	int		count_zero;
	int		count_p;
	int		pos_p[2];
	int		cnt_c;
	int		count_e;
	int		pos_e[2];
}			t_map;

typedef struct s_mlx
{
	t_map	**map_data;
	void	*mlx_p;
	void	*win_p;
	void	*wall_img;
	void	*floor_img;
	void	*collect_img;
	void	*player_img;
	void	*exit_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		win_x;
	int		win_y;
}			t_mlx;

// Functions
// memory_manager
	// allocation_manager.c
int		my_realloc(void **ptr, int old_size, int new_size);
	// free_manager.c
void	free_manager(char *label, ...);
	// free_map_data.c
void	free_map_data(va_list arg);
void	free_map(t_map **map_data);
void	free_visited(t_map **map_data);
	// free_mlx_data.c
void    free_mlx_data(va_list arg);
void	free_img(t_mlx **mlx);
// error_manager
	// error_manager.c
void	error_manager(char *error, int level, ...);
// map_manager
	// map_manager.c
void	map_init(t_map **map_data);
void	map_init_directions(t_map **map_data);
void	map_manager(t_map **map_data);
void	map_valid_ext(t_map **map_data);
void	map_read(t_map **map_data);
	// map_checker.c
void	map_check_rectangle(t_map **map_data);
void	map_check_enclosement(t_map **map_data);
void	map_check_characters(t_map **map_data);
void	map_check_elements(t_map **map_data);
	// map_checker_bis.c
int		map_check_way(int x, int y, t_map **map_data);
int		map_is_valid_pos(int x, int y, t_map **map_data);
void	map_find_exit(t_map **map_data);
void	map_find_spawn(t_map **map_data);
// mlx_manager
	// mlx_manager.c
void	mlx_manager(t_mlx **mlx, t_map **map_data);
int		mlx_deal_key(int key, t_mlx **mlx);
int		mlx_deal_cross(t_mlx **mlx);
	// mlx_render_manager.c
int		render_manager(t_mlx **mlx);
void	render_back(t_mlx **mlx, t_map **map_data);
void	render_front(t_mlx **mlx, t_map **map_data);
void	my_img_to_win(t_mlx **mlx, void *img, int x, int y);
	// mlx_mouv_manager.c
void    move_up(t_mlx **mlx, t_map **map_data);
void    move_down(t_mlx **mlx, t_map **map_data);
void    move_left(t_mlx **mlx, t_map **map_data);
void    move_right(t_mlx **mlx, t_map **map_data);
	// mlx_mouv_utils.c
void    swap_player_image(int form, t_mlx **mlx, t_map **map_data);
void	update_tile(char *move, int x, int y, t_mlx **mlx, t_map **map_data);	
	// mlx_init_data.c
void	mlx_init_data(t_mlx **mlx, t_map **map_data);
void    mlx_init_win(t_mlx **mlx, t_map **map_data);
void    mlx_init_img_front(t_mlx **mlx, t_map **map_data);
void    mlx_init_img_back(t_mlx **mlx, t_map **map_data);
	// mlx_init_data_utils.c
void  	calculate_scale_x(t_mlx **mlx, t_map **map_data);
void  	calculate_scale_y(t_mlx **mlx, t_map **map_data);

#endif
