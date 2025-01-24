/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_init_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:40:52 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/24 08:56:48 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	sl_game_init_manager(t_sl_game **game, t_sl_map **map, t_sl_img **img)
{
	*game = (t_sl_game *)malloc(sizeof(t_sl_game));
	if (!*game)
		sl_error_game("Error\nMemory allocation error", -2, map, game);
	(*game)->map = map;
	(*game)->img = img;
	(*game)->mlx_p = mlx_init();
	if (!(*game)->mlx_p)
		sl_error_game("Error\nFailed to connect to Xserver", -2, map, game);
	mlx_get_screen_size((*game)->mlx_p, &(*game)->screen_x, &(*game)->screen_y);
	if (sl_game_init_window(game) == -1)
		sl_error_game("Error\nFailed to create window", -2, map, game);
	if (sl_game_init_image((*game)->mlx_p, img) == -1)
		sl_error_game("Error\nFailed to create images", -2, map, game);
	(*game)->biome_x = 0;
	(*game)->biome_y = 0;
	(*game)->moves = 0;
}

int	sl_game_init_window(t_sl_game **game)
{
	int	tile_x;
	int	tile_y;
	int	win_x;
	int	win_y;

	tile_x = ((*game)->screen_x / TILE);
	if (((*(*game)->map)->width) <= tile_x)
		win_x = TILE * (*(*game)->map)->width;
	else
		win_x = tile_x * TILE;
	tile_y = ((*game)->screen_y / TILE);
	if (((*(*game)->map)->height) <= tile_y)
		win_y = TILE * (*(*game)->map)->height;
	else
		win_y = tile_y * TILE;
	(*game)->win_p = mlx_new_window((*game)->mlx_p, win_x, win_y, "so_long");
	if (!(*game)->win_p)
		return (-1);
	return (0);
}

int	sl_game_init_image(void *mlx_p, t_sl_img **img)
{
	int	tile;

	tile = TILE;
	*img = (t_sl_img *)malloc(sizeof(t_sl_img));
	if (!*img)
		return (-1);
	(*img)->wall = mlx_xpm_file_to_image(mlx_p, WALL, &tile, &tile);
	if (!(*img)->wall)
		return (-1);
	(*img)->floor = mlx_xpm_file_to_image(mlx_p, FLOOR, &tile, &tile);
	if (!(*img)->floor)
		return (-1);
	(*img)->exit = mlx_xpm_file_to_image(mlx_p, EXIT_OFF, &tile, &tile);
	if (!(*img)->exit)
		return (-1);
	(*img)->collect = mlx_xpm_file_to_image(mlx_p, COLLECT, &tile, &tile);
	if (!(*img)->collect)
		return (-1);
	(*img)->player = mlx_xpm_file_to_image(mlx_p, PLAYERR, &tile, &tile);
	if (!(*img)->player)
		return (-1);
	return (0);
}
