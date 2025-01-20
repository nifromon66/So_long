/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:50:12 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/20 02:46:48 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	free_mlx_data(va_list arg)
{
	t_mlx	**mlx;

	mlx = va_arg(arg, t_mlx **);
	if (*mlx)
	{
		free_img(mlx);
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
		(*mlx)->map_data = NULL;
		free(*mlx);
		*mlx = NULL;
	}
}

void	free_img(t_mlx **mlx)
{
	if ((*mlx)->wall_img)
	{
		mlx_destroy_image((*mlx)->mlx_p, (*mlx)->wall_img);
		(*mlx)->wall_img = NULL;
	}
	if ((*mlx)->space_img)
	{
		mlx_destroy_image((*mlx)->mlx_p, (*mlx)->space_img);
		(*mlx)->space_img = NULL;
	}
	if ((*mlx)->collect_img)
	{
		mlx_destroy_image((*mlx)->mlx_p, (*mlx)->collect_img);
		(*mlx)->collect_img = NULL;
	}
	if ((*mlx)->player_img)
	{
		mlx_destroy_image((*mlx)->mlx_p, (*mlx)->player_img);
		(*mlx)->player_img = NULL;
	}
	if ((*mlx)->exit_img)
	{
		mlx_destroy_image((*mlx)->mlx_p, (*mlx)->exit_img);
		(*mlx)->exit_img = NULL;
	}
}
