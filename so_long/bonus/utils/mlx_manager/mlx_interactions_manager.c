/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_interactions_manager.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 03:13:49 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/23 19:45:26 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	mlx_interact_manager(t_mlx **mlx, void *win_p)
{
	mlx_hook(win_p, 3, (1L<<1), &mlx_key, mlx);
	mlx_hook(win_p, 17, (1L<<17), &mlx_cross, mlx);
}

int	mlx_key(int key, t_mlx **mlx)
{
	int		x;
	int		y;
	char	*moves;

	moves = NULL;
	if (key == 0xff1b)
		error_manager("None", 0, (*mlx)->map, mlx);
	if (key == KEY_W)
		mlx_movement_manager(1, mlx, (*mlx)->map);
	if (key == KEY_S)
		mlx_movement_manager(2, mlx, (*mlx)->map);
	if (key == KEY_A)
		mlx_movement_manager(3, mlx, (*mlx)->map);
	if (key == KEY_D)
		mlx_movement_manager(4, mlx, (*mlx)->map);
	mlx_render(mlx, (*mlx)->img, (*mlx)->map);
	moves = ft_itoa((*mlx)->moves);
	if (!moves)
		error_manager("Memory allocation error", -2, mlx, (*mlx)->map);
	x = (((*(*(*mlx)->map)->spawn)->x - (*mlx)->biome_x) * 192) - 96;
	y = (((*(*(*mlx)->map)->spawn)->y - (*mlx)->biome_y) * 192) - 96;
	draw_large_text(mlx, x, y, moves);
	free(moves);
	return (0);
}

int	mlx_cross(t_mlx **mlx)
{
	error_manager("None", 0, (*mlx)->map, mlx);
	return (0);
}

void draw_large_text(t_mlx **mlx, int x, int y, char *str)
{
	void	*mlxp;
	void	*winp;
	int		i;
	int		offset_x = 0;
	int		offset_y = 0;

	mlxp = (*mlx)->mlx_p;
	winp = (*mlx)->win_p;
	i = -1;
	while (str[++i])
	{
		mlx_string_put(mlxp, winp, x + offset_x, y + offset_y, PIX, str);
		offset_x++;
	}
}
