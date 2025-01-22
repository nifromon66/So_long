/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_interactions_manager.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 03:13:49 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/22 06:58:16 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	mlx_interact_manager(t_mlx **mlx, void *win_p)
{
	mlx_hook(win_p, KeyRelease, KeyReleaseMask, &mlx_key, mlx);
	mlx_hook(win_p, DestroyNotify, StructureNotifyMask, &mlx_cross, mlx);
}

int	mlx_key(int key, t_mlx **mlx)
{
	if (key == XK_Escape)
		error_manager("None", 0, (*mlx)->map, mlx);
	if (key == KEY_W)
		mlx_movement_manager(1, mlx, (*mlx)->map);
	if (key == KEY_S)
		mlx_movement_manager(2, mlx, (*mlx)->map);
	if (key == KEY_A)
		mlx_movement_manager(3, mlx, (*mlx)->map);
	if (key == KEY_D)
		mlx_movement_manager(4, mlx, (*mlx)->map);
	ft_printf("Number of moves : [ %d ]\n", (*mlx)->moves);
	return (0);
}

int	mlx_cross(t_mlx **mlx)
{
	error_manager("None", 0, (*mlx)->map, mlx);
	return (0);
}
