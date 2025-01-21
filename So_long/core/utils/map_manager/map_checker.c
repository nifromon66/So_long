/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 00:29:26 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/21 05:29:51 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	map_check_rectangle(t_map **map_data)
{
	int	i;

	i = 0;
	while (i != (*map_data)->h)
	{
		if ((ft_strlen((*map_data)->map[i]) - 1) != (size_t)(*map_data)->w)
			error_manager("Map has irregular width", -2, map_data);
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
	h = (*map_data)->h;
	w = (*map_data)->w;
	while (j != h)
	{
		i = 0;
		while (i != w)
		{
			if ((j == 0 || j == h) && (*map_data)->map[j][i] != '1')
				error_manager("Map isn't enclosed by walls", -2, map_data);
			else if ((i == 0 || i == w) && (*map_data)->map[j][i] != '1')
				error_manager("Map isn't enclosed by walls", -2, map_data);
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

	j = -1;
	c = 0;
	while (++j != (*map_data)->h)
	{
		i = -1;
		while (++i != (*map_data)->w)
		{
			c = (*map_data)->map[j][i];
			if (c == 'P')
				(*map_data)->count_p++;
			else if (c == 'C')
				(*map_data)->cnt_c++;
			else if (c == 'E')
				(*map_data)->count_e++;
			else if (c == '0')
				(*map_data)->count_zero++;
			else if (c != '1')
				error_manager("Map has an invalid character", -2, map_data);
		}
	}
}

void	map_check_elements(t_map **map_data)
{
	if ((*map_data)->count_p != 1)
		error_manager("Map has invalid number of spawn", -2, map_data);
	if (!((*map_data)->cnt_c >= 1))
		error_manager("Map has invalid number of collectibles", -2, map_data);
	if ((*map_data)->count_e != 1)
		error_manager("Map has invalid number of exit", -2, map_data);
}
