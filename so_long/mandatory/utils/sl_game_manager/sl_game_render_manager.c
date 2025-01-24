/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_render_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:41:19 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/24 08:59:55 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	sl_game_render_manager(t_sl_game **game)
{
	sl_game_render(game, (*game)->img, (*game)->map);
	return (0);
}

void	sl_game_render(t_sl_game **game, t_sl_img **img, t_sl_map **map)
{
	int	i;
	int	j;

	if (!game || !*game || !map || !*map)
		return ;
	j = -1;
	while (++j < (*map)->height)
	{
		i = -1;
		while (++i < (*map)->width)
		{
			if ((*map)->map[j][i] == '1')
				my_img_to_win(game, (*img)->wall, i, j);
			else if ((*map)->map[j][i] == '0')
				my_img_to_win(game, (*img)->floor, i, j);
			else if ((*map)->map[j][i] == 'E')
				my_img_to_win(game, (*img)->exit, i, j);
			else if ((*map)->map[j][i] == 'C')
				my_img_to_win(game, (*img)->collect, i, j);
			else if ((*map)->map[j][i] == 'P')
				my_img_to_win(game, (*img)->player, i, j);
		}
	}
}

void	my_img_to_win(t_sl_game **game, void *img, int x, int y)
{
	x = (x - (*game)->biome_x) * TILE;
	y = (y - (*game)->biome_y) * TILE;
	mlx_put_image_to_window((*game)->mlx_p, (*game)->win_p, img, x, y);
}
