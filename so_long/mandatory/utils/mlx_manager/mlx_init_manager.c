/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:35:16 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/23 22:37:32 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	mlx_init_manager(t_mlx **mlx, t_map **map, t_img **img)
{
	*mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!*mlx)
		error_mlx("Error\nMemory allocation error", -2, map, mlx);
	(*mlx)->map = map;
	(*mlx)->img = img;
	(*mlx)->mlx_p = mlx_init();
	if (!(*mlx)->mlx_p)
		error_mlx("Error\nFailed to connect to Xserver", -2, map, mlx);
	mlx_get_screen_size((*mlx)->mlx_p, &(*mlx)->screen_x, &(*mlx)->screen_y);
	if (mlx_init_window(mlx) == -1)
		error_mlx("Error\nFailed to create window", -2, map, mlx);
	if (mlx_init_image((*mlx)->mlx_p, img) == -1)
		error_mlx("Error\nFailed to create images", -2, map, mlx);
	(*mlx)->biome_x = 0;
	(*mlx)->biome_y = 0;
	(*mlx)->moves = 0;
}

int	mlx_init_window(t_mlx **mlx)
{
	int	tile_x;
	int	tile_y;
	int	win_x;
	int	win_y;

	tile_x = ((*mlx)->screen_x / TILE);
	if (((*(*mlx)->map)->width) <= tile_x)
		win_x = TILE * (*(*mlx)->map)->width;
	else
		win_x = tile_x * TILE;
	tile_y = ((*mlx)->screen_y / TILE);
	if (((*(*mlx)->map)->height) <= tile_y)
		win_y = TILE * (*(*mlx)->map)->height;
	else
		win_y = tile_y * TILE;
	(*mlx)->win_p = mlx_new_window((*mlx)->mlx_p, win_x, win_y, "so_long");
	if (!(*mlx)->win_p)
		return (-1);
	return (0);
}

int	mlx_init_image(void *mlx_p, t_img **img)
{
	int	tile;

	tile = TILE;
	*img = (t_img *)malloc(sizeof(t_img));
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
