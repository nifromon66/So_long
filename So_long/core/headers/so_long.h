/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:06:58 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/16 23:54:43 by nifromon         ###   ########.fr       */
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
# define BLACK      "\033[0;30m"
# define RED        "\033[0;31m"
# define GREEN      "\033[0;32m"
# define YELLOW     "\033[0;33m"
# define BLUE       "\033[0;34m"
# define PURPLE     "\033[0;35m"
# define CYAN       "\033[0;36m"
# define WHITE      "\033[0;37m"
# define RESET      "\033[0;0m"

// Structures
typedef struct s_map
{
    char	*file;
    char    **map;
    int		fd;
    int		width;
    int		height;
	int		file_len;
}			t_map;

// Global variable
extern t_map *g_map;

// Functions
// error_manager.c
void    error_manager(char *error, int level);
void	free_so_long(void);
// map_manager.c
void	map_init(void);
void	map_manager(void);
void	map_check_format(void);
void	map_read(void);
void	map_free(void);

#endif
