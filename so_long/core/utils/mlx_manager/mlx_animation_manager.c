/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animation_manager.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 04:36:12 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/22 14:28:40 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	mlx_animation_manager(int asset, int form, int pos[], t_mlx **mlx)
{
	if (asset == 0)
		mlx_animation_putback(form, pos, mlx);
	if (asset == 1)
		mlx_animation_player_shift(form, mlx);
	if (asset == 3)
		mlx_animation_exit(form, mlx);
}

void	mlx_animation_putback(int move, int pos[], t_mlx **mlx)
{
	int	x;
	int	y;

	x = pos[0];
	y = pos[1];
	if (move == 1)
		x--;
	else if (move == 2)
		x++;
	else if (move == 3)
		y--;
	else if (move == 4)
		y++;
	if (x == (*(*(*mlx)->map)->exit)->x && y == (*(*(*mlx)->map)->exit)->y)
	{
		if (move == 2)
			mlx_animation_player_shift(2, mlx);
		else
			mlx_animation_player_shift(1, mlx);
		(*(*mlx)->map)->map[y][x] = 'E';
	}
	else
		(*(*mlx)->map)->map[y][x] = '0';
}

void	mlx_animation_player_shift(int form, t_mlx **mlx)
{
	if (form == 1)
		mlx_animation_swap(mlx, &(*(*mlx)->img)->player, PLAYERR);
	else if (form == 2)
		mlx_animation_swap(mlx, &(*(*mlx)->img)->player, PLAYERL);
}

void	mlx_animation_exit(int form, t_mlx **mlx)
{
	if (form == 1)
		mlx_animation_swap(mlx, &(*(*mlx)->img)->exit, EXIT_OFF);
	else if (form == 2)
		mlx_animation_swap(mlx, &(*(*mlx)->img)->exit, EXIT_ON);
}
