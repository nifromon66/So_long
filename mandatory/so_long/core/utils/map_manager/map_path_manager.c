/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:26:21 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/22 06:47:17 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	map_path_manager(t_map **map)
{
	int	spawn_x;
	int	spawn_y;

	map_find_spawn((*map)->map, (*map)->width, (*map)->height, (*map)->spawn);
	map_find_exit((*map)->map, (*map)->width, (*map)->height, (*map)->exit);
	spawn_x = (*(*map)->spawn)->x;
	spawn_y = (*(*map)->spawn)->y;
	map_init_visited(map, (*map)->width, (*map)->height);
	if (map_path_to_exit(map, spawn_x, spawn_y) == -1)
		error_manager("Player can't access the exit", -1, map);
	free_visited(map, (*map)->height);
	map_init_visited(map, (*map)->width, (*map)->height);
	if (map_path_to_collect(map, spawn_x, spawn_y, &(*map)->count_c) == -1)
		error_manager("Player can't find all collectibles", -1, map);
}

int	map_path_to_exit(t_map **map, int x, int y)
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
			if (map_path_to_exit(map, nx, ny) == 0)
				return (0);
		}
	}
	return (-1);
}

int	map_path_to_collect(t_map **map, int x, int y, int *count_c)
{
	int	i;
	int	nx;
	int	ny;

	if ((*map)->map[y][x] == 'C')
		(*count_c)--;
	if (*count_c == 0)
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
			if (map_path_to_collect(map, nx, ny, count_c) == 0)
				return (0);
		}
	}
	return (-1);
}

void	map_find_spawn(char **map, int x, int y, t_pos **spawn)
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

void	map_find_exit(char **map, int x, int y, t_pos **exit)
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
