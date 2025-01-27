/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_path_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:40:13 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/26 23:13:47 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long_bonus.h"

void	sl_map_path_manager(t_sl_map **map)
{
	int	width;
	int	height;
	int	spawn_x;
	int	spawn_y;

	width = (*map)->width;
	height = (*map)->height;
	sl_map_find_spawn((*map)->map, width, height, (*map)->spawn);
	sl_map_find_exit((*map)->map, (*map)->width, (*map)->height, (*map)->exit);
	spawn_x = (*(*map)->spawn)->x;
	spawn_y = (*(*map)->spawn)->y;
	sl_map_init_visited(map, (*map)->width, (*map)->height);
	if (sl_map_path_to_exit(map, spawn_x, spawn_y) == -1)
		sl_error_map("Error\nPlayer can't access the exit", map);
	sl_free_visited(map, (*map)->height);
	sl_map_init_visited(map, (*map)->width, (*map)->height);
	if (sl_map_path_to_collect(map, spawn_x, spawn_y, &(*map)->count_c) == -1)
		sl_error_map("Error\nPlayer can't find all collectibles", map);
}

int	sl_map_path_to_exit(t_sl_map **map, int x, int y)
{
	int	i;
	int	nx;
	int	ny;

	if ((*map)->map[y][x] == 'E')
		return (0);
	(*map)->visited[y][x] = 1;
	i = -1;
	while (++i != 4)
	{
		nx = x + (*map)->dx[i];
		ny = y + (*map)->dy[i];
		if (!((*map)->visited[ny][nx]) && ((*map)->map[ny][nx] == '0'
			|| (*map)->map[ny][nx] == 'C' || (*map)->map[ny][nx] == 'E'))
		{
			if (sl_map_path_to_exit(map, nx, ny) == 0)
				return (0);
		}
	}
	return (-1);
}

int	sl_map_path_to_collect(t_sl_map **map, int x, int y, int *count_c)
{
	int	i;
	int	nx;
	int	ny;

	if ((*map)->map[y][x] == 'C')
	{
		(*map)->foe[(*count_c - (*map)->count_c_game) * -1]->x = x;
		(*map)->foe[(*count_c - (*map)->count_c_game) * -1]->y = y;
		if ((*count_c)-- == 0 || *count_c == 0)
			return (0);
	}
	(*map)->visited[y][x] = 1;
	i = -1;
	while (++i != 4)
	{
		nx = x + (*map)->dx[i];
		ny = y + (*map)->dy[i];
		if (!((*map)->visited[ny][nx]) && ((*map)->map[ny][nx] == '0'
			|| (*map)->map[ny][nx] == 'C' || (*map)->map[ny][nx] == 'E'))
		{
			if (sl_map_path_to_collect(map, nx, ny, count_c) == 0)
				return (0);
		}
	}
	return (-1);
}

void	sl_map_find_spawn(char **map, int x, int y, t_sl_pos **spawn)
{
	int			i;
	int			j;

	j = -1;
	while (++j != y)
	{
		i = -1;
		while (++i != x)
		{
			if (map[j][i] == 'P')
			{
				(*spawn)->x = i;
				(*spawn)->y = j;
			}
		}
	}
}

void	sl_map_find_exit(char **map, int x, int y, t_sl_pos **exit)
{
	int			i;
	int			j;

	j = -1;
	while (++j != y)
	{
		i = -1;
		while (++i != x)
		{
			if (map[j][i] == 'E')
			{
				(*exit)->x = i;
				(*exit)->y = j;
			}
		}
	}
}
