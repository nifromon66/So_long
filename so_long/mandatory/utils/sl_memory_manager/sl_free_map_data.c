/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:39:22 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/24 08:39:26 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	sl_free_map_data(t_sl_map **map)
{
	if (*map)
	{
		if ((*map)->fd != -1)
		{
			close((*map)->fd);
			(*map)->fd = -1;
		}
		sl_free_map(map, (*map)->height);
		sl_free_positions((*map)->spawn, (*map)->exit);
		sl_free_visited(map, (*map)->height);
		free(*map);
		*map = NULL;
	}
}

void	sl_free_map(t_sl_map **map, int y)
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

void	sl_free_positions(t_sl_pos **spawn, t_sl_pos **exit)
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

void	sl_free_visited(t_sl_map **map, int y)
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
