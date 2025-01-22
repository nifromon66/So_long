/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:35:16 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/22 06:57:23 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	mlx_init_manager(t_mlx **mlx, t_map **map, t_img **img)
{
	*mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!*mlx)
		error_manager("Memory allocation error", -2, mlx, map);
	(*mlx)->map = map;
	(*mlx)->img = img;
	(*mlx)->mlx_p = mlx_init();
	if (!(*mlx)->mlx_p)
		error_manager("Failed to connect to Xserver", -2, mlx, map);
	if (mlx_init_window(mlx) == -1)
		error_manager("Failed to create window", -2, mlx, map);
	if (mlx_init_image((*mlx)->mlx_p, img) == -1)
		error_manager("Failed to create images", -2, mlx, map);
	(*mlx)->biome_x = 0;
	(*mlx)->biome_y = 0;
	(*mlx)->moves = 0;
}

int	mlx_init_window(t_mlx **mlx)
{
	int	win_x;
	int	win_y;

	if ((*(*mlx)->map)->width <= 13)
		win_x = TILE * (*(*mlx)->map)->width;
	else
		win_x = 2496;
	if ((*(*mlx)->map)->height <= 7)
		win_y = TILE * (*(*mlx)->map)->height;
	else
		win_y = 1344;
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
