/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:25:40 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/23 22:37:46 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	map_init_manager(t_map **map, t_pos **spawn, t_pos **exit)
{
	*map = (t_map *)malloc(sizeof(t_map));
	if (!*map)
		error_map("Error\nMemory allocation error", map);
	if (map_init_map_data(map) == -1)
		error_map("Error\nMemory allocation error", map);
	(*map)->spawn = spawn;
	(*map)->exit = exit;
	if (map_init_positions((*map)->spawn, (*map)->exit) == -1)
		error_map("Error\nMemory allocation error", map);
	map_init_directions(map);
}

int	map_init_map_data(t_map **map)
{
	(*map)->visited = NULL;
	(*map)->file = NULL;
	(*map)->fd = -1;
	(*map)->map = (char **)malloc(sizeof(char *));
	if (!(*map)->map)
		return (-1);
	(*map)->map[0] = NULL;
	(*map)->width = 0;
	(*map)->height = 0;
	(*map)->count_c = 0;
	(*map)->count_c_mlx = 0;
	return (0);
}

int	map_init_positions(t_pos **spawn, t_pos **exit)
{
	*spawn = (t_pos *)malloc(sizeof(t_pos));
	if (!*spawn)
		return (-1);
	(*spawn)->x = 0;
	(*spawn)->y = 0;
	*exit = (t_pos *)malloc(sizeof(t_pos));
	if (!*exit)
		return (-1);
	(*exit)->x = 0;
	(*exit)->y = 0;
	return (0);
}

int	map_init_directions(t_map **map)
{
	(*map)->dx[0] = 1;
	(*map)->dx[1] = -1;
	(*map)->dx[2] = 0;
	(*map)->dx[3] = 0;
	(*map)->dy[0] = 0;
	(*map)->dy[1] = 0;
	(*map)->dy[2] = 1;
	(*map)->dy[3] = -1;
	return (0);
}

int	map_init_visited(t_map **map, int x, int y)
{
	int	i;
	int	j;

	(*map)->visited = (int **)malloc(y * sizeof(int *));
	if (!(*map)->visited)
		return (-1);
	j = -1;
	while (++j != y)
	{
		(*map)->visited[j] = (int *)malloc(x * sizeof(int));
		if (!(*map)->visited[j])
			return (-1);
		i = -1;
		while (++i != x)
			(*map)->visited[j][i] = 0;
	}
	return (0);
}
