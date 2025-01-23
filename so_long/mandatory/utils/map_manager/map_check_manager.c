/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:03:36 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/23 22:37:46 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	map_check_manager(t_map **map)
{
	if (map_check_rectangle((*map)->map, (*map)->width, (*map)->height) == -1)
		error_map("Error\nMap is not rectangular : irregular width", map);
	if (map_check_closed((*map)->map, (*map)->width, (*map)->height) == -1)
		error_map("Error\nMap isn't enclosed by walls", map);
	if (map_check_char((*map)->map, (*map)->width, (*map)->height,
			&((*map)->count_c)) == -1)
		error_map("Error\nMap has an invalid character", map);
	(*map)->count_c_mlx = (*map)->count_c;
}

int	map_check_rectangle(char **map, int x, int y)
{
	int	j;

	j = -1;
	while (++j != y)
	{
		if ((ft_strlen(map[j]) - 1) != (size_t)x)
			return (-1);
	}
	return (0);
}

int	map_check_closed(char **map, int x, int y)
{
	int	i;
	int	j;

	j = -1;
	while (++j != y)
	{
		i = -1;
		while (++i != x)
		{
			if ((j == 0 || j == y) && map[j][i] != '1')
				return (-1);
			if ((i == 0 || i == x) && map[j][i] != '1')
				return (-1);
		}
	}
	return (0);
}

int	map_check_char(char **map, int x, int y, int *count_c)
{
	int	count[2];
	int	i;
	int	j;

	count[0] = 0;
	count[1] = 0;
	j = -1;
	while (++j != y)
	{
		i = -1;
		while (++i != x)
		{
			if (map[j][i] == 'P')
				count[0]++;
			else if (map[j][i] == 'E')
				count[1]++;
			else if (map[j][i] == 'C')
				(*count_c)++;
			else if (map[j][i] != '0' && map[j][i] != '1')
				return (-1);
		}
	}
	if (count[0] != 1 || count[1] != 1 || *count_c < 1)
		return (-1);
	return (0);
}
