/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:41:35 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/21 01:19:22 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	mlx_init_data(t_mlx **mlx, t_map **map_data)
{
    *mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!*mlx)
		error_manager("Memory allocation failed", -1, mlx, map_data);
	(*mlx)->map_data = map_data;
	(*mlx)->mlx_p = NULL;
    (*mlx)->addr = NULL;
	(*mlx)->bpp = 0;
	(*mlx)->line_len = 0;
	(*mlx)->endian = 0;
    (*mlx)->mlx_p = mlx_init();
	if (!(*mlx)->mlx_p)
		error_manager("Failed to connect to Xserver", -1, mlx, map_data);
    mlx_init_win(mlx, map_data);
    mlx_init_img_front(mlx, map_data);
	mlx_init_img_back(mlx, map_data);
}
void    mlx_init_win(t_mlx **mlx, t_map **map_data)
{
    int  width;
    int  height;

    (*mlx)->win_p = NULL;
	calculate_scale_x(mlx, map_data);
	calculate_scale_y(mlx, map_data);
    width = (*mlx)->win_x;
    height = (*mlx)->win_y;
    (*mlx)->win_p = mlx_new_window((*mlx)->mlx_p, width, height, "so_long");
    if (!(*mlx)->win_p)
        error_manager("Failed to create window", -1, mlx, map_data);
}

void    mlx_init_img_front(t_mlx **mlx, t_map **map_data)
{
    int 	tilex;
	int		tiley;
	void	*mlx_p;

    tilex = 192;
	tiley = 192;
	mlx_p = (*mlx)->mlx_p;
	(*mlx)->player_img = mlx_xpm_file_to_image(mlx_p, PLAYER, &tilex, &tiley);
	if (!(*mlx)->player_img)
		error_manager("Failed to put "PLAYER" to image", -1, mlx, map_data);
	tilex = 128;
	tiley = 128;
	(*mlx)->collect_img = mlx_xpm_file_to_image(mlx_p, COLLECT, &tilex, &tiley);
	if (!(*mlx)->collect_img)
		error_manager("Failed to put "COLLECT" to image", -1, mlx, map_data);
	tilex = 192;
	tiley = 128;
	(*mlx)->exit_img = mlx_xpm_file_to_image(mlx_p, EXIT, &tilex, &tiley);
	if (!(*mlx)->exit_img)
		error_manager("Failed to put "EXIT" to image", -1, mlx, map_data);
}
void    mlx_init_img_back(t_mlx **mlx, t_map **map_data)
{
	int 	tilex;
	int		tiley;
	void	*mlx_p;

    tilex = 192;
	tiley = 192;
	mlx_p = (*mlx)->mlx_p;
	(*mlx)->floor_img = mlx_xpm_file_to_image(mlx_p, FLOOR, &tilex, &tiley);
	if (!(*mlx)->floor_img)
		error_manager("Failed to put "FLOOR" to image", -1, mlx, map_data);
	tilex = 192;
	tiley = 192;
	(*mlx)->wall_img = mlx_xpm_file_to_image(mlx_p, WALL, &tilex, &tiley);
	if (!(*mlx)->wall_img)
		error_manager("Failed to put "WALL" to image", -1, mlx, map_data);
}
