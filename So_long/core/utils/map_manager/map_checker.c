/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 00:29:26 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/18 03:08:15 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	map_check_rectangle(t_map **map_data)
{
	int	i;

	i = 0;
    (*map_data)->width = (int) ft_strlen((*map_data)->map[0]) - 1;
	if ((*map_data)->width == (*map_data)->height)
		error_manager("Map is a square", -1, map_data);
	while (i != (*map_data)->height)
	{
		if ((ft_strlen((*map_data)->map[i]) - 1) != (size_t) (*map_data)->width)
			error_manager("Map has irregular width", -1, map_data);
		i++;
	}
}

void	map_check_enclosement(t_map **map_data)
{
	int	h;
	int	w;
	int	i;
	int	j;
	
	j = 0;
	h = (*map_data)->height;
	w = (*map_data)->width;
	while (j != (*map_data)->height)
	{
		i = 0;
		while (i != w)
		{
			if ((j == 0 || j == h) && (*map_data)->map[j][i] != '1')
				error_manager("Map isn't enclosed by walls", -1, map_data);
			else if ((i == 0 || i == w) && (*map_data)->map[j][i] != '1')
				error_manager("Map isn't enclosed by walls", -1, map_data);
			i++;
		}
		j++;
	}
}

void	map_check_characters(t_map **map_data)
{
	char		c;
	int			i;
	int			j;

	j = 0;
	c = 0;
	while (j != (*map_data)->height)
	{
		i = 0;
		while (i != (*map_data)->width)
		{
			c = (*map_data)->map[j][i];
			if (c == 'P')
				(*map_data)->count_p++;
			else if (c == 'C')
				(*map_data)->count_c++;
			else if (c == 'E')
				(*map_data)->count_e++;
			else if (c != '1' && c != '0')
				error_manager("Map has an invalid character", -1, map_data);
			i++;
		}
		j++;
	}
}

void	map_check_elements(t_map **map_data)
{
	if ((*map_data)->count_p != 1)
		error_manager("Map has invalid number of spawn", -1, map_data);
	if (!((*map_data)->count_c >= 1))
		error_manager("Map has invalid number of collectibles", -1, map_data);
	if ((*map_data)->count_e != 1)
		error_manager("Map has invalid number of exit", -1, map_data);
}
