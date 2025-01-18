/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:06:58 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/18 17:52:26 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes
# include <fcntl.h>
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
	int		count_c;
	int		count_e;
	int		pos_e[2];
}			t_map;

// Functions
// memory_manager
	// allocation_manager.c
int		my_realloc(void **ptr, int old_size, int new_size);
	// free_manager.c
void	free_manager(char *label, ...);
void	free_map_data(va_list arg);
void	free_map(t_map **map_data);
void	free_visited(t_map **map_data);
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

#endif
