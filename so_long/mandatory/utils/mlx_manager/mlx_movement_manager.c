/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_movement_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 03:40:14 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/23 22:46:34 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	mlx_movement_manager(int move, t_mlx **mlx, t_map **map)
{
	if (move == 1)
	{
		if (move_up(mlx, (*map)->map, &(*map)->count_c_mlx) == 0)
			error_mlx("Game session succesfully ended", 0, map, mlx);
	}
	else if (move == 2)
	{
		if (move_down(mlx, (*map)->map, &(*map)->count_c_mlx) == 0)
			error_mlx("Game session succesfully ended", 0, map, mlx);
	}
	else if (move == 3)
	{
		if (move_left(mlx, (*map)->map, &(*map)->count_c_mlx) == 0)
			error_mlx("Game session succesfully ended", 0, map, mlx);
	}
	else if (move == 4)
	{
		if (move_right(mlx, (*map)->map, &(*map)->count_c_mlx) == 0)
			error_mlx("Game session succesfully ended", 0, map, mlx);
	}
}

int	move_up(t_mlx **mlx, char **map, int *count_c)
{
	int	pos[2];

	pos[0] = (*(*(*mlx)->map)->spawn)->x;
	pos[1] = (*(*(*mlx)->map)->spawn)->y - 1;
	(*mlx)->moves++;
	if (map[pos[1]][pos[0]] != '1')
	{
		if (pos[1] == (*mlx)->biome_y)
			(*mlx)->biome_y -= ((*mlx)->screen_y / TILE);
		if (map[pos[1]][pos[0]] == 'E' && *count_c != 0)
			mlx_update_manager(2, 2, pos, mlx);
		else if (map[pos[1]][pos[0]] == 'E')
			return (0);
		else if (map[pos[1]][pos[0]] == 'C'
			&& ((*count_c)-- == 0 || *count_c == 0))
			mlx_update_manager(3, 2, pos, mlx);
		map[pos[1]][pos[0]] = 'P';
		mlx_update_manager(0, 4, pos, mlx);
		(*(*(*mlx)->map)->spawn)->y = pos[1];
	}
	return (-1);
}

int	move_down(t_mlx **mlx, char **map, int *count_c)
{
	int	pos[2];

	pos[0] = (*(*(*mlx)->map)->spawn)->x;
	pos[1] = (*(*(*mlx)->map)->spawn)->y + 1;
	(*mlx)->moves++;
	if (map[pos[1]][pos[0]] != '1')
	{
		if ((pos[1] - ((*mlx)->screen_y / TILE)) == (*mlx)->biome_y)
			(*mlx)->biome_y += ((*mlx)->screen_y / TILE);
		if (map[pos[1]][pos[0]] == 'E' && *count_c != 0)
			mlx_update_manager(2, 2, pos, mlx);
		else if (map[pos[1]][pos[0]] == 'E')
			return (0);
		else if (map[pos[1]][pos[0]] == 'C'
			&& ((*count_c)-- == 0 || *count_c == 0))
			mlx_update_manager(3, 2, pos, mlx);
		map[pos[1]][pos[0]] = 'P';
		mlx_update_manager(0, 3, pos, mlx);
		(*(*(*mlx)->map)->spawn)->y = pos[1];
	}
	return (-1);
}

int	move_left(t_mlx **mlx, char **map, int *count_c)
{
	int	pos[2];

	pos[0] = (*(*(*mlx)->map)->spawn)->x - 1;
	pos[1] = (*(*(*mlx)->map)->spawn)->y;
	(*mlx)->moves++;
	if (map[pos[1]][pos[0]] != '1')
	{
		if (pos[0] == (*mlx)->biome_x)
			(*mlx)->biome_x -= ((*mlx)->screen_x / TILE);
		if (map[pos[1]][pos[0]] == 'E' && *count_c != 0)
			mlx_update_manager(2, 2, pos, mlx);
		else if (map[pos[1]][pos[0]] == 'E')
			return (0);
		else if (map[pos[1]][pos[0]] == 'C'
			&& ((*count_c)-- == 0 || *count_c == 0))
			mlx_update_manager(3, 2, pos, mlx);
		else
			mlx_update_manager(1, 2, pos, mlx);
		map[pos[1]][pos[0]] = 'P';
		mlx_update_manager(0, 2, pos, mlx);
		(*(*(*mlx)->map)->spawn)->x = pos[0];
	}
	return (-1);
}

int	move_right(t_mlx **mlx, char **map, int *count_c)
{
	int	pos[2];

	pos[0] = (*(*(*mlx)->map)->spawn)->x + 1;
	pos[1] = (*(*(*mlx)->map)->spawn)->y;
	(*mlx)->moves++;
	if (map[pos[1]][pos[0]] != '1')
	{
		if ((pos[0] - ((*mlx)->screen_x / TILE)) == (*mlx)->biome_x)
			(*mlx)->biome_x += ((*mlx)->screen_x / TILE);
		if (map[pos[1]][pos[0]] == 'E' && *count_c != 0)
			mlx_update_manager(2, 1, pos, mlx);
		else if (map[pos[1]][pos[0]] == 'E')
			return (0);
		else if (map[pos[1]][pos[0]] == 'C'
			&& ((*count_c)-- == 0 || *count_c == 0))
			mlx_update_manager(3, 2, pos, mlx);
		else
			mlx_update_manager(1, 1, pos, mlx);
		map[pos[1]][pos[0]] = 'P';
		mlx_update_manager(0, 1, pos, mlx);
		(*(*(*mlx)->map)->spawn)->x = pos[0];
	}
	return (-1);
}
