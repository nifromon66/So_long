/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animation_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 05:04:49 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/22 15:22:26 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	mlx_animation_swap(t_mlx **mlx, void **img, char *new)
{
	int	tile;

	tile = TILE;
	if (*img)
	{
		mlx_destroy_image((*mlx)->mlx_p, *img);
		*img = mlx_xpm_file_to_image((*mlx)->mlx_p, new, &tile, &tile);
		if (!*img)
			error_manager("Failed to swap images", -2, mlx, (*mlx)->map);
	}
}
