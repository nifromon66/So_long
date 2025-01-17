/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:06:58 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/17 18:21:48 by nifromon         ###   ########.fr       */
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
}			t_map;

// Global variable
extern t_map *g_map;

// Functions
// allocation_manager.c
int		my_realloc(void **ptr, int old_size, int new_size);
// error_manager.c
void	error_manager(char *error, int level);
// map_manager.c
void	map_init(void);
void	map_manager(void);
void	map_check_format(void);
// free_manager.c
void	free_map(void);
void	free_manager(char *label);

#endif
