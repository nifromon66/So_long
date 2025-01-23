/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 06:10:28 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/23 18:42:41 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	free_mlx_data(t_mlx **mlx)
{
	if (*mlx)
	{
		free_mlx_img((*mlx)->mlx_p, (*mlx)->img);
		if ((*mlx)->win_p)
		{
			mlx_destroy_window((*mlx)->mlx_p, (*mlx)->win_p);
			(*mlx)->win_p = NULL;
		}
		if ((*mlx)->mlx_p)
		{
			mlx_destroy_display((*mlx)->mlx_p);
			free((*mlx)->mlx_p);
			(*mlx)->mlx_p = NULL;
		}
		(*mlx)->map = NULL;
		free(*mlx);
		*mlx = NULL;
	}
}

void	free_mlx_img(void *mlx_p, t_img **img)
{
	if (*img)
	{
		free_img(mlx_p, &(*img)->wall);
		free_img(mlx_p, &(*img)->floor);
		free_img(mlx_p, &(*img)->exit);
		free_img(mlx_p, &(*img)->collect);
		free_img(mlx_p, &(*img)->player);
		free(*img);
		*img = NULL;
	}
}

void	free_img(void *mlx_p, void **img)
{
	if (*img)
	{
		mlx_destroy_image(mlx_p, *img);
		*img = NULL;
	}
}
