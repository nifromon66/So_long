/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_update_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:41:28 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/24 09:00:20 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	sl_game_update_manager(int xpm, int form, int pos[], t_sl_game **game)
{
	if (xpm == 0)
		sl_game_update_tile(form, pos, game);
	if (xpm == 1)
		sl_game_update_player(form, game);
	if (xpm == 2)
		sl_game_update_player_exit(form, game);
	if (xpm == 3)
		sl_game_update_exit(form, game);
}

void	sl_game_update_tile(int move, int pos[], t_sl_game **game)
{
	int	x;
	int	y;

	x = pos[0];
	y = pos[1];
	if (move == 1)
		x--;
	else if (move == 2)
		x++;
	else if (move == 3)
		y--;
	else if (move == 4)
		y++;
	if (x == (*(*(*game)->map)->exit)->x && y == (*(*(*game)->map)->exit)->y)
	{
		if (move == 2)
			sl_game_update_player(2, game);
		else
			sl_game_update_player(1, game);
		(*(*game)->map)->map[y][x] = 'E';
	}
	else
		(*(*game)->map)->map[y][x] = '0';
}

void	sl_game_update_player(int form, t_sl_game **game)
{
	if (form == 1)
		sl_game_images_swap(game, &(*(*game)->img)->player, PLAYERR);
	else if (form == 2)
		sl_game_images_swap(game, &(*(*game)->img)->player, PLAYERL);
}

void	sl_game_update_player_exit(int form, t_sl_game **game)
{
	if (form == 1)
		sl_game_images_swap(game, &(*(*game)->img)->player, PLAYER_RE);
	else if (form == 2)
		sl_game_images_swap(game, &(*(*game)->img)->player, PLAYER_LE);
}

void	sl_game_update_exit(int form, t_sl_game **game)
{
	if (form == 1)
		sl_game_images_swap(game, &(*(*game)->img)->exit, EXIT_OFF);
	else if (form == 2)
		sl_game_images_swap(game, &(*(*game)->img)->exit, EXIT_ON);
}
