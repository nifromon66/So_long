/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_images_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:40:43 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/27 09:58:21 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long_bonus.h"

void	sl_game_images_swap(t_sl_game **game, void **img, char *new)
{
	int	tile;

	tile = TILE;
	if (*img)
	{
		mlx_destroy_image((*game)->mlx_p, *img);
		*img = mlx_xpm_file_to_image((*game)->mlx_p, new, &tile, &tile);
		if (!*img)
			sl_error_game("Error\nImage swap failed", -2, (*game)->map, game);
	}
}
