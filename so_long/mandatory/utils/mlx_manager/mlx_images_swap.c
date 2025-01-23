/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_images_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 05:04:49 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/23 22:37:32 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	mlx_images_swap(t_mlx **mlx, void **img, char *new)
{
	int	tile;

	tile = TILE;
	mlx_destroy_image((*mlx)->mlx_p, *img);
	*img = mlx_xpm_file_to_image((*mlx)->mlx_p, new, &tile, &tile);
	if (!*img)
		error_mlx("Error\nFailed to swap images", -2, (*mlx)->map, mlx);
}
