/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:48:42 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/19 13:49:02 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	free_map_data(va_list arg)
{
	t_map	**map_data;

	map_data = va_arg(arg, t_map **);
	if (*map_data)
	{
		if ((*map_data)->fd != -1)
		{
			close((*map_data)->fd);
			(*map_data)->fd = -1;
		}
		free_map(map_data);
		free_visited(map_data);
		free(*map_data);
		*map_data = NULL;
	}
}

void	free_map(t_map **map_data)
{
	int	i;

	i = 0;
	if ((*map_data)->map)
	{
		while (i < (*map_data)->h + 1)
		{
			if ((*map_data)->map[i] != NULL)
			{
				free((*map_data)->map[i]);
				(*map_data)->map[i] = NULL;
			}
			i++;
		}
		free((*map_data)->map);
		(*map_data)->map = NULL;
	}
}

void	free_visited(t_map **map_data)
{
	int	i;

	i = 0;
	if ((*map_data)->visited)
	{
		while (i < (*map_data)->h)
		{
			if ((*map_data)->visited[i])
			{
				free((*map_data)->visited[i]);
				(*map_data)->visited[i] = 0;
			}
			i++;
		}
		free((*map_data)->visited);
		(*map_data)->visited = NULL;
	}
}
