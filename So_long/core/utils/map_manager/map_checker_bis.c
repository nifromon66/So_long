/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:26:01 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/21 04:55:01 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	map_check_way_exit(int x, int y, t_map **map_data)
{
	int	i;
	int	nx;
	int	ny;

	if ((*map_data)->map[y][x] == 'E')
		return (1);
	(*map_data)->visited[y][x] = 1;
	i = -1;
	while (++i != 4)
	{
		nx = x + (*map_data)->dx[i];
		ny = y + (*map_data)->dy[i];
		if ((map_is_valid_pos(nx, ny, map_data) == 1)
			&& !((*map_data)->visited[ny][nx])
			&& ((*map_data)->map[ny][nx] == '0'
			|| (*map_data)->map[ny][nx] == 'C'
			|| (*map_data)->map[ny][nx] == 'E'))
		{
			if (map_check_way_exit(nx, ny, map_data) == 1)
				return (1);
		}
	}
	return (0);
}

int	map_check_way_collect(int x, int y, t_map **map_data)
{
	int	i;
	int	nx;
	int	ny;

	if ((*map_data)->map[y][x] == 'C')
		(*map_data)->count_c--;
	if ((*map_data)->count_c == 0)
		return (1);
	(*map_data)->visited[y][x] = 1;
	i = -1;
	while (++i != 4)
	{
		nx = x + (*map_data)->dx[i];
		ny = y + (*map_data)->dy[i];
		if ((map_is_valid_pos(nx, ny, map_data) == 1)
			&& !((*map_data)->visited[ny][nx])
			&& ((*map_data)->map[ny][nx] == '0'
			|| (*map_data)->map[ny][nx] == 'C'
			|| (*map_data)->map[ny][nx] == 'E'))
		{
			if (map_check_way_collect(nx, ny, map_data) == 1)
				return (1);
		}
	}
	return (0);
}

int	map_is_valid_pos(int x, int y, t_map **map_data)
{
	int	valid;
	int	w;
	int	h;

	w = (*map_data)->w;
	h = (*map_data)->h;
	valid = 0;
	if ((x >= 0 && x < w) && (y >= 0 && y < h))
		valid = 1;
	return (valid);
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
				(*map_data)->pos_p[0] = i;
				(*map_data)->pos_p[1] = j;
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
				(*map_data)->pos_e[0] = i;
				(*map_data)->pos_e[1] = j;
			}
			i++;
		}
		j++;
	}
}
