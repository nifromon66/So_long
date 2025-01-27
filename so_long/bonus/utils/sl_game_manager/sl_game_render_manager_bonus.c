/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_render_manager_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:41:19 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/27 05:55:58 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long_bonus.h"

int	sl_game_render_manager(t_sl_game **game)
{
	static int	timing = 1;
	int			x;
	int			y;

	x = (*game)->screen_x / TILE;
	y = (*game)->screen_y / TILE;
	sl_game_render_player(game, (*game)->map, (*(*game)->map)->exit);
	sl_game_render_foe(game, (*(*game)->map)->foe, x, y);
	if (timing != 0)
		timing--;
	else if ((*game)->boom == 2)
		sl_error_game("GAME OVER", 0, (*game)->map, game);
	else
	{
		sl_game_foe_patrol(game, (*(*game)->map)->foe, x, y);
		timing = 1;
	}
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
		}
	}
}

void	sl_game_render_player(t_sl_game **game, t_sl_map **map, t_sl_pos **ext)
{
	int	pos[2];
	int	boom;

	boom = (*game)->boom;
	pos[0] = (*(*map)->spawn)->y;
	pos[1] = (*(*map)->spawn)->x;
	if (pos[0] == (*ext)->y && pos[1] == (*ext)->x && boom == 0)
		sl_game_animation_player(game, ((*game)->direction + 2), pos);
	else if (boom == 0)
		sl_game_animation_player(game, (*game)->direction, pos);
}

void	sl_game_render_foe(t_sl_game **game, t_sl_pos **foe, int x, int y)
{
	static int	door = 1;
	int			by;
	int			bx;
	int			i;

	i = 0;
	by = (*game)->biome_y;
	bx = (*game)->biome_x;
	while (foe[i] != NULL)
	{
		if (foe[i]->y > by && foe[i]->y < (y + by))
		{
			if (foe[i]->x > bx && foe[i]->x < (x + bx) && door == 1)
			{
				sl_game_animation_foe(game, (1 + (*game)->boom), foe[i]);
				door++;
			}
			else if (foe[i]->x > bx && foe[i]->x < (x + bx) && door == 2)
			{
				sl_game_animation_foe(game, (2 + (*game)->boom), foe[i]);
				door--;
			}
		}
		i++;
	}
}

void	my_img_to_win(t_sl_game **game, void *img, int x, int y)
{
	x = (x - (*game)->biome_x) * TILE;
	y = (y - (*game)->biome_y) * TILE;
	mlx_put_image_to_window((*game)->mlx_p, (*game)->win_p, img, x, y);
}
