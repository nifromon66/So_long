/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_movement_manager_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:41:10 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/27 06:00:32 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long_bonus.h"

void	sl_game_movement_manager(int move, t_sl_game **game, t_sl_map **map)
{
	if (move == 1)
	{
		if (sl_player_move_up(game, (*map)->map, &(*map)->count_c_game) == 0)
			sl_error_game("YOU WON", 0, map, game);
	}
	else if (move == 2)
	{
		if (sl_player_move_down(game, (*map)->map, &(*map)->count_c_game) == 0)
			sl_error_game("YOU WON", 0, map, game);
	}
	else if (move == 3)
	{
		if (sl_player_move_left(game, (*map)->map, &(*map)->count_c_game) == 0)
			sl_error_game("YOU WON", 0, map, game);
	}
	else if (move == 4)
	{
		if (sl_player_move_right(game, (*map)->map, &(*map)->count_c_game) == 0)
			sl_error_game("YOU WON", 0, map, game);
	}
}

int	sl_player_move_up(t_sl_game **game, char **map, int *count_c)
{
	int	pos[2];

	pos[0] = (*(*(*game)->map)->spawn)->x;
	pos[1] = (*(*(*game)->map)->spawn)->y - 1;
	if (map[pos[1]][pos[0]] != '1')
	{
		(*game)->moves++;
		if (pos[1] == (*game)->biome_y)
			(*game)->biome_y -= ((*game)->screen_y / TILE);
		if (map[pos[1]][pos[0]] == 'E' && *count_c == 0)
			return (0);
		else if (map[pos[1]][pos[0]] == 'C'
			&& ((*count_c)-- == 0 || *count_c == 0))
			sl_game_update_manager(3, 2, pos, game);
		map[pos[1]][pos[0]] = 'P';
		sl_game_update_manager(0, 4, pos, game);
		(*(*(*game)->map)->spawn)->y = pos[1];
	}
	return (-1);
}

int	sl_player_move_down(t_sl_game **game, char **map, int *count_c)
{
	int	pos[2];

	pos[0] = (*(*(*game)->map)->spawn)->x;
	pos[1] = (*(*(*game)->map)->spawn)->y + 1;
	if (map[pos[1]][pos[0]] != '1')
	{
		(*game)->moves++;
		if ((pos[1] - ((*game)->screen_y / TILE)) == (*game)->biome_y)
			(*game)->biome_y += ((*game)->screen_y / TILE);
		if (map[pos[1]][pos[0]] == 'E' && *count_c == 0)
			return (0);
		else if (map[pos[1]][pos[0]] == 'C'
			&& ((*count_c)-- == 0 || *count_c == 0))
			sl_game_update_manager(3, 2, pos, game);
		map[pos[1]][pos[0]] = 'P';
		sl_game_update_manager(0, 3, pos, game);
		(*(*(*game)->map)->spawn)->y = pos[1];
	}
	return (-1);
}

int	sl_player_move_left(t_sl_game **game, char **map, int *count_c)
{
	int	pos[2];

	pos[0] = (*(*(*game)->map)->spawn)->x - 1;
	pos[1] = (*(*(*game)->map)->spawn)->y;
	(*game)->direction = 2;
	if (map[pos[1]][pos[0]] != '1')
	{
		(*game)->moves++;
		if (pos[0] == (*game)->biome_x)
			(*game)->biome_x -= ((*game)->screen_x / TILE);
		if (map[pos[1]][pos[0]] == 'E' && *count_c == 0)
			return (0);
		else if (map[pos[1]][pos[0]] == 'C'
			&& ((*count_c)-- == 0 || *count_c == 0))
			sl_game_update_manager(3, 2, pos, game);
		else
			sl_game_update_manager(1, 2, pos, game);
		map[pos[1]][pos[0]] = 'P';
		sl_game_update_manager(0, 2, pos, game);
		(*(*(*game)->map)->spawn)->x = pos[0];
	}
	return (-1);
}

int	sl_player_move_right(t_sl_game **game, char **map, int *count_c)
{
	int	pos[2];

	pos[0] = (*(*(*game)->map)->spawn)->x + 1;
	pos[1] = (*(*(*game)->map)->spawn)->y;
	(*game)->direction = 1;
	if (map[pos[1]][pos[0]] != '1')
	{
		(*game)->moves++;
		if ((pos[0] - ((*game)->screen_x / TILE)) == (*game)->biome_x)
			(*game)->biome_x += ((*game)->screen_x / TILE);
		if (map[pos[1]][pos[0]] == 'E' && *count_c == 0)
			return (0);
		else if (map[pos[1]][pos[0]] == 'C'
			&& ((*count_c)-- == 0 || *count_c == 0))
			sl_game_update_manager(3, 2, pos, game);
		else
			sl_game_update_manager(1, 1, pos, game);
		map[pos[1]][pos[0]] = 'P';
		sl_game_update_manager(0, 1, pos, game);
		(*(*(*game)->map)->spawn)->x = pos[0];
	}
	return (-1);
}
