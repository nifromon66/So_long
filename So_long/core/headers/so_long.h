/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:06:58 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/18 02:53:06 by nifromon         ###   ########.fr       */
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
	int		fd;
	int		width;
	int		height;
	int		file_len;
	int		count_p;
	int		count_c;
	int		count_e;
}			t_map;

// Functions
// memory_manager
	// allocation_manager.c
int		my_realloc(void **ptr, int old_size, int new_size);
	// free_manager.c
void	free_map(va_list arg);
void	free_manager(char *label, ...);
// error_manager
	// error_manager.c
void	error_manager(char *error, int level, ...);
// map_manager
	// map_manager.c
void	map_init(t_map **map_data);
void	map_manager(t_map **map_data);
void	map_valid_ext(t_map **map_data);
void	map_read(t_map **map_data);
	// map_checker.c
void    map_check_rectangle(t_map **map_data);
void	map_check_enclosement(t_map **map_data);
void	map_check_characters(t_map **map_data);
void	map_check_elements(t_map **map_data);
#endif
