/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_game_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:39:36 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/26 02:52:03 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long_bonus.h"

void	sl_free_game_data(t_sl_game **game)
{
	if (*game)
	{
		sl_free_game_img((*game)->mlx_p, (*game)->img);
		if ((*game)->win_p)
		{
			mlx_destroy_window((*game)->mlx_p, (*game)->win_p);
			(*game)->win_p = NULL;
		}
		if ((*game)->mlx_p)
		{
			mlx_destroy_display((*game)->mlx_p);
			free((*game)->mlx_p);
			(*game)->mlx_p = NULL;
		}
		(*game)->map = NULL;
		free(*game);
		*game = NULL;
	}
}

void	sl_free_game_img(void *mlx_p, t_sl_img **img)
{
	if (*img)
	{
		sl_free_images(mlx_p, &(*img)->wall);
		sl_free_images(mlx_p, &(*img)->floor);
		sl_free_images(mlx_p, &(*img)->exit);
		sl_free_images(mlx_p, &(*img)->collect);
		sl_free_images(mlx_p, &(*img)->player);
		sl_free_images(mlx_p, &(*img)->foe);
		free(*img);
		*img = NULL;
	}
}

void	sl_free_images(void *mlx_p, void **img)
{
	if (*img)
	{
		mlx_destroy_image(mlx_p, *img);
		*img = NULL;
	}
}
