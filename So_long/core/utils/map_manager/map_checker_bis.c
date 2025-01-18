/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:26:01 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/18 17:56:49 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	map_check_way(int x, int y, t_map **map_data)
{
	int	i;
	int	nx;
	int	ny;

	if ((*map_data)->map[y][x] == 'E')
		return (1);
	(*map_data)->visited[y][x] = 1;
	i = 0;
	while (++i != 4)
	{
		nx = x + (*map_data)->dx[i];
		ny = y + (*map_data)->dy[i];
		if (map_is_valid_pos(nx, ny, map_data)
			&& !((*map_data)->visited[ny][nx])
			&& ((*map_data)->map[ny][nx] == '0'
			|| (*map_data)->map[ny][nx] == 'C'
			|| (*map_data)->map[ny][nx] == 'E'))
		{
			if (map_check_way(nx, ny, map_data) == 1)
				return (1);
		}
	}
	return (0);
}

int	map_is_valid_pos(int x, int y, t_map **map_data)
{
	int	w;
	int	h;

	w = (*map_data)->w;
	h = (*map_data)->h;
	return ((x >= 0 && x < w) && (y >= 0 && y < h));
}

void	map_find_spawn(t_map **map_data)
{
	char		c;
	int			i;
	int			j;

	j = 0;
	c = 0;
	while (j != (*map_data)->h)
	{
		i = 0;
		while (i != (*map_data)->w)
		{
			c = (*map_data)->map[j][i];
			if (c == 'P')
			{
				(*map_data)->pos_p[0] = j;
				(*map_data)->pos_p[1] = i;
			}
			i++;
		}
		j++;
	}
}

void	map_find_exit(t_map **map_data)
{
	char		c;
	int			i;
	int			j;

	j = 0;
	c = 0;
	while (j != (*map_data)->h)
	{
		i = 0;
		while (i != (*map_data)->w)
		{
			c = (*map_data)->map[j][i];
			if (c == 'E')
			{
				(*map_data)->pos_e[0] = j;
				(*map_data)->pos_e[1] = i;
			}
			i++;
		}
		j++;
	}
}
