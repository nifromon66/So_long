/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 05:26:45 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/22 06:57:11 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	mlx_render_manager(t_mlx **mlx)
{
	mlx_render(mlx, (*mlx)->img, (*mlx)->map);
	return (0);
}

void	mlx_render(t_mlx **mlx, t_img **img, t_map **map)
{
	int	i;
	int	j;

	if (!mlx || !*mlx || !map || !*map)
		return ;
	j = -1;
	while (++j < (*map)->height)
	{
		i = -1;
		while (++i < (*map)->width)
		{
			if ((*map)->map[j][i] == '1')
				my_img_to_win(mlx, (*img)->wall, i, j);
			else if ((*map)->map[j][i] == '0')
				my_img_to_win(mlx, (*img)->floor, i, j);
			else if ((*map)->map[j][i] == 'E')
				my_img_to_win(mlx, (*img)->exit, i, j);
			else if ((*map)->map[j][i] == 'C')
				my_img_to_win(mlx, (*img)->collect, i, j);
			else if ((*map)->map[j][i] == 'P')
				my_img_to_win(mlx, (*img)->player, i, j);
		}
	}
}

void	my_img_to_win(t_mlx **mlx, void *img, int x, int y)
{
	x = (x - (*mlx)->biome_x) * TILE;
	y = (y - (*mlx)->biome_y) * TILE;
	mlx_put_image_to_window((*mlx)->mlx_p, (*mlx)->win_p, img, x, y);
}
