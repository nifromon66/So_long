/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:40:57 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/21 02:20:23 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	mlx_manager(t_mlx **mlx, t_map **map_data)
{
	mlx_init_data(mlx, map_data);
	mlx_loop_hook((*mlx)->mlx_p, &render_manager, mlx);
	mlx_hook((*mlx)->win_p, KeyRelease, KeyReleaseMask, &mlx_deal_key, mlx);
	mlx_hook((*mlx)->win_p, DestroyNotify, StructureNotifyMask, &mlx_deal_cross, mlx);
    mlx_loop((*mlx)->mlx_p);
}

int	mlx_deal_key(int key, t_mlx **mlx)
{
	ft_printf("Key pressed: %d\n", key);
	if (key == XK_Escape)
    {
        free_manager("all",(*mlx)->map_data, mlx);
        exit(0);
    }
	if (key == 65362)
		move_up(mlx, (*mlx)->map_data);
	if (key == 65364)
		move_down(mlx, (*mlx)->map_data);
	if (key == 65361)
		move_left(mlx, (*mlx)->map_data);
	if (key == 65363)
		move_right(mlx, (*mlx)->map_data);
	return (0);
}

int	mlx_deal_cross(t_mlx **mlx)
{
	free_manager("all", (*mlx)->map_data, mlx);
	exit(0);
	return (0);
}

