/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:40:57 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/21 05:12:01 by nifromon         ###   ########.fr       */
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
	if (key == XK_Escape)
    {
        free_manager("all",(*mlx)->map_data, mlx);
        exit(0);
    }
	if (key == KEY_W)
		move_up(mlx, (*mlx)->map_data);
	if (key == KEY_S)
		move_down(mlx, (*mlx)->map_data);
	if (key == KEY_A)
		move_left(mlx, (*mlx)->map_data);
	if (key == KEY_D)
		move_right(mlx, (*mlx)->map_data);
	ft_printf("Number of moves : [%d]\n", (*mlx)->moves);
	return (0);
}

int	mlx_deal_cross(t_mlx **mlx)
{
	free_manager("all", (*mlx)->map_data, mlx);
	exit(0);
	return (0);
}

