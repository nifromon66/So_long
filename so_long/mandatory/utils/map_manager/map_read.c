/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:25:42 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/23 22:37:46 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	map_check_format(char *file)
{
	char	format[4];
	int		i;
	int		dot;

	i = 0;
	dot = (ft_strlen(file) - 4);
	while (i != 4)
	{
		format[i] = file[dot];
		dot++;
		i++;
	}
	format[4] = '\0';
	if (ft_strncmp(format, ".ber", 4) != 0)
		return (-1);
	return (0);
}

void	map_read(t_map **map)
{
	int	y;
	int	old_size;
	int	new_size;

	y = 0;
	(*map)->map[y] = get_next_line((*map)->fd);
	if ((*map)->map[y] == NULL)
		error_map("Error\nMap is empty", map);
	y++;
	while ((*map)->map[y - 1] != NULL)
	{
		old_size = (y * sizeof(char *));
		new_size = ((y + 1) * sizeof(char *));
		if (my_realloc((void **)&(*map)->map, old_size, new_size) == -1)
			error_map("Error\nMemory allocation error", map);
		(*map)->map[y] = get_next_line((*map)->fd);
		y++;
	}
	(*map)->height = y - 1;
	(*map)->width = (int) ft_strlen((*map)->map[0]) - 1;
}
