/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_interactions_manager_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:24:12 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/27 09:57:26 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long_bonus.h"

void	sl_game_interact_manager(t_sl_game **game, void *win_p)
{
	mlx_hook(win_p, 3, (1L << 1), &sl_game_key, game);
	mlx_hook(win_p, 17, (1L << 17), &sl_game_cross, game);
}

int	sl_game_key(int key, t_sl_game **game)
{
	char	*moves;
	int		x;
	int		y;

	moves = NULL;
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
	sl_game_render(game, (*game)->img, (*game)->map);
	moves = ft_itoa((*game)->moves);
	if (!moves)
		sl_error_game("Memory allocation error", -2, (*game)->map, game);
	x = (((1 + (*game)->biome_x)) * 192) - 96;
	y = (((1 + (*game)->biome_y)) * 192) - 96;
	sl_draw_large_text_bonus(game, x, y, moves);
	free(moves);
	return (0);
}

int	sl_game_cross(t_sl_game **game)
{
	sl_error_game("Game session succesfully ended", 0, (*game)->map, game);
	return (0);
}

void	sl_draw_large_text_bonus(t_sl_game **game, int x, int y, char *str)
{
	void	*mlxp;
	void	*winp;
	int		i;
	int		offset_x;
	int		offset_y;

	offset_x = 0;
	offset_y = 0;
	mlxp = (*game)->mlx_p;
	winp = (*game)->win_p;
	i = -1;
	while (str[++i])
	{
		mlx_string_put(mlxp, winp, x + offset_x, y + offset_y, PIX, str);
		offset_x++;
	}
}
