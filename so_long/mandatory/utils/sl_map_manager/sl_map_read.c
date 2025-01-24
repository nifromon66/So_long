/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:40:02 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/24 08:40:06 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	sl_map_check_format(char *file)
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

void	sl_map_read(t_sl_map **map)
{
	int	y;
	int	old_size;
	int	new_size;

	y = 0;
	(*map)->map[y] = get_next_line((*map)->fd);
	if ((*map)->map[y] == NULL)
		sl_error_map("Error\nMap is empty", map);
	y++;
	while ((*map)->map[y - 1] != NULL)
	{
		old_size = (y * sizeof(char *));
		new_size = ((y + 1) * sizeof(char *));
		if (my_realloc((void **)&(*map)->map, old_size, new_size) == -1)
			sl_error_map("Error\nMemory allocation error", map);
		(*map)->map[y] = get_next_line((*map)->fd);
		y++;
	}
	(*map)->height = y - 1;
	(*map)->width = (int) ft_strlen((*map)->map[0]) - 1;
}
