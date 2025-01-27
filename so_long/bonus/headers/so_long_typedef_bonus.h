/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_typedef_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 05:38:59 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/27 05:38:48 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_TYPEDEF_BONUS_H
# define SO_LONG_TYPEDEF_BONUS_H

// Structures
	// Positions
typedef struct s_sl_pos
{
	int		x;
	int		y;
}			t_sl_pos;
	// Map
typedef struct s_sl_map
{
	t_sl_pos	**spawn;
	t_sl_pos	**exit;
	t_sl_pos	**foe;
	char		**map;
	char		*file;
	int			**visited;
	int			dx[4];
	int			dy[4];
	int			fd;
	int			width;
	int			height;
	int			count_c;
	int			count_c_game;
}				t_sl_map;
	// Image
typedef struct s_sl_img
{
	void	*wall;
	void	*floor;
	void	*collect;
	void	*player;
	void	*foe;
	void	*exit;
}			t_sl_img;
	// game
typedef struct s_sl_game
{
	t_sl_map	**map;
	t_sl_img	**img;
	void		*mlx_p;
	void		*win_p;
	int			biome_x;
	int			biome_y;
	int			moves;
	int			screen_x;
	int			screen_y;
	int			direction;
	int			boom;
}				t_sl_game;

#endif