/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_foe_manager_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:04:20 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/27 09:56:48 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long_bonus.h"

void	sl_game_place_foe(t_sl_map **map, t_sl_pos **foe)
{
	int	i;
	int	move;

	i = 0;
	while (foe[i] != NULL)
	{
		move = 0;
		if ((*map)->map[foe[i]->y - 1][foe[i]->x] == '0' && move++ != 0)
			(*map)->map[foe[i]->y - 1][foe[i]->x] = '0';
		else if ((*map)->map[foe[i]->y + 1][foe[i]->x] == '0' && move++ != 0)
			(*map)->map[foe[i]->y + 1][foe[i]->x] = '0';
		else if ((*map)->map[foe[i]->y][foe[i]->x - 1] == '0' && move++ != 0)
			(*map)->map[foe[i]->y][foe[i]->x - 1] = '0';
		else if ((*map)->map[foe[i]->y][foe[i]->x + 1] == '0' && move++ != 0)
			(*map)->map[foe[i]->y][foe[i]->x + 1] = '0';
		else
			move++;
		sl_game_update_foe_pos(foe, move, i);
		i++;
	}
}

void	sl_game_update_foe_pos(t_sl_pos **foe, int move, int i)
{
	if (move == 5)
		return ;
	else if (move == 1)
		foe[i]->y -= 1;
	else if (move == 2)
		foe[i]->y += 1;
	else if (move == 3)
		foe[i]->x -= 1;
	else if (move == 4)
		foe[i]->x += 1;
}

void	sl_game_foe_patrol(t_sl_game **game, t_sl_pos **foe, int x, int y)
{
	int	i;
	int	dx;
	int	dy;
	int	bx;
	int	by;

	i = -1;
	by = (*game)->biome_y;
	bx = (*game)->biome_x;
	while (foe[++i] != NULL)
	{
		if ((foe[i]->y > by && foe[i]->y < (y + by))
			&& (foe[i]->x > bx && foe[i]->x < (x + bx)))
		{
			dx = (*(*(*game)->map)->spawn)->x - foe[i]->x;
			dy = (*(*(*game)->map)->spawn)->y - foe[i]->y;
			if (dx == 0 && dy == 0)
			{
				(*game)->boom = 2;
				return ;
			}
			sl_game_foe_move(game, dx, dy, i);
			sl_game_render(game, (*game)->img, (*game)->map);
		}
	}
}

void	sl_game_foe_move(t_sl_game **game, int dx, int dy, int i)
{
	int	pos_x;
	int	pos_y;

	pos_x = (*(*game)->map)->foe[i]->x;
	pos_y = (*(*game)->map)->foe[i]->y;
	if (abs(dx) > abs(dy) || abs(dx) == abs(dy))
	{
		if (dx > 0 && (*(*game)->map)->map[pos_y][pos_x + 1] != '1')
			(*(*game)->map)->foe[i]->x++;
		else if (dx < 0 && (*(*game)->map)->map[pos_y][pos_x - 1] != '1')
			(*(*game)->map)->foe[i]->x--;
	}
	else if (abs(dx) < abs(dy))
	{
		if (dy > 0 && (*(*game)->map)->map[pos_y + 1][pos_x] != '1')
			(*(*game)->map)->foe[i]->y++;
		else if (dy < 0 && (*(*game)->map)->map[pos_y - 1][pos_x] != '1')
			(*(*game)->map)->foe[i]->y--;
	}
}
