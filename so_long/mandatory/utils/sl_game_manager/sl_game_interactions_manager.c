/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_interactions_manager.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:41:01 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/24 08:57:51 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	sl_game_interact_manager(t_sl_game **game, void *win_p)
{
	mlx_hook(win_p, 3, (1L << 1), &sl_game_key, game);
	mlx_hook(win_p, 17, (1L << 17), &sl_game_cross, game);
}

int	sl_game_key(int key, t_sl_game **game)
{
	if (key == KEY_ESC)
		sl_error_game("Game session succesfully ended", 0, (*game)->map, game);
	if (key == KEY_W)
		sl_game_movement_manager(1, game, (*game)->map);
	if (key == KEY_S)
		sl_game_movement_manager(2, game, (*game)->map);
	if (key == KEY_A)
		sl_game_movement_manager(3, game, (*game)->map);
	if (key == KEY_D)
		sl_game_movement_manager(4, game, (*game)->map);
	ft_printf("Number of moves : [ %d ]\n", (*game)->moves);
	sl_game_render_manager(game);
	return (0);
}

int	sl_game_cross(t_sl_game **game)
{
	sl_error_game("Game session succesfully ended", 0, (*game)->map, game);
	return (0);
}
