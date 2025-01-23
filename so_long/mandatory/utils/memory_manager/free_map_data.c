/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:48:42 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/23 18:42:17 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	free_map_data(t_map **map)
{
	if (*map)
	{
		if ((*map)->fd != -1)
		{
			close((*map)->fd);
			(*map)->fd = -1;
		}
		free_map(map, (*map)->height);
		free_positions((*map)->spawn, (*map)->exit);
		free_visited(map, (*map)->height);
		free(*map);
		*map = NULL;
	}
}

void	free_map(t_map **map, int y)
{
	int	j;

	j = -1;
	if ((*map)->map)
	{
		while (++j != y)
		{
			if ((*map)->map[j])
			{
				free((*map)->map[j]);
				(*map)->map[j] = NULL;
			}
		}
		free((*map)->map);
		(*map)->map = NULL;
	}
}

void	free_positions(t_pos **spawn, t_pos **exit)
{
	if (*spawn)
	{
		free(*spawn);
		*spawn = NULL;
	}
	if (*exit)
	{
		free(*exit);
		*exit = NULL;
	}
}

void	free_visited(t_map **map, int y)
{
	int	j;

	j = -1;
	if ((*map)->visited)
	{
		while (++j != y)
		{
			if ((*map)->visited[j])
			{
				free((*map)->visited[j]);
				(*map)->visited[j] = NULL;
			}
		}
		free((*map)->visited);
		(*map)->visited = NULL;
	}
}
