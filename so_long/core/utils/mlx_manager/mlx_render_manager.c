/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 05:26:45 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/22 14:47:59 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	mlx_render_manager(t_mlx **mlx)
{
	mlx_render_player(mlx, (*mlx)->img, (*mlx)->map);
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
		}
	}
}

void	mlx_render_player(t_mlx **mlx, t_img **img, t_map **map)
{
	int	pos[2];

	if (!mlx || !*mlx || !map || !*map)
		return ;
	pos[0] = -1;
	while (++(pos[0]) < (*map)->height)
	{
		pos[1] = -1;
		while (++(pos[1]) < (*map)->width)
		{
			if ((*map)->map[pos[0]][pos[1]] == 'P'
				&& (pos[0] == (*(*map)->exit)->y)
				&& (pos[1] == (*(*map)->exit)->x))
				mlx_animation_player(mlx, img, ((*mlx)->direction + 2), pos);
			else if ((*map)->map[pos[0]][pos[1]] == 'P')
				mlx_animation_player(mlx, img, (*mlx)->direction, pos);
		}
	}
}

void	my_img_to_win(t_mlx **mlx, void *img, int x, int y)
{
	x = (x - (*mlx)->biome_x) * TILE;
	y = (y - (*mlx)->biome_y) * TILE;
	mlx_put_image_to_window((*mlx)->mlx_p, (*mlx)->win_p, img, x, y);
}
