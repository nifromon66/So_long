/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:44:35 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/18 02:57:49 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	map_init(t_map **map_data)
{
	*map_data = (t_map *)malloc(sizeof(t_map));
	if (!*map_data)
		error_manager("Memory allocation error", -1, map_data);
	(*map_data)->map = (char **)malloc(sizeof(char *));
	if (!(*map_data)->map)
		error_manager("Memory allocation error", -1, map_data);
	(*map_data)->file = NULL;
	(*map_data)->height = 0;
	(*map_data)->width = 0;
	(*map_data)->file_len = 0;
	(*map_data)->fd = -1;
	(*map_data)->count_p = 0;
	(*map_data)->count_c = 0;
	(*map_data)->count_e = 0;
}
void	map_manager(t_map **map_data)
{
	map_valid_ext(map_data);
	(*map_data)->fd = open((*map_data)->file, O_RDONLY);
	if ((*map_data)->fd == -1)
		error_manager("Couldn't open map file", -1, map_data);
	map_read(map_data);
	map_check_rectangle(map_data);
	map_check_enclosement(map_data);
	map_check_characters(map_data);
	map_check_elements(map_data);
	close((*map_data)->fd);
	(*map_data)->fd = -1;
}

void	map_valid_ext(t_map **map_data)
{
	char	format[4];
	int		i;
	int		dot;

	i = 0;
	dot = (*map_data)->file_len - 4;
	while(i != 4)
	{
		format[i] = (*map_data)->file[dot];
		dot++;
		i++;
	}
	format[4] = '\0';
	if (ft_strncmp(format, ".ber", 4) != 0)
		error_manager("Map has invalid file extension", -1, map_data);
}

void	map_read(t_map **map_data)
{
	int	i;
	int	old_size;
	int	new_size;
	
	i = 0;
	(*map_data)->map[i] = get_next_line((*map_data)->fd);
	if ((*map_data)->map[i] == NULL)
		error_manager("Map is empty", -1, map_data);
	i++;
	(*map_data)->height = i;
	while (1)
	{
		old_size = ((*map_data)->height * sizeof(char *));
		new_size = (((*map_data)->height + 1) * sizeof(char *));
		if (my_realloc((void **)&(*map_data)->map, old_size, new_size) == -1)
			error_manager("Memory allocation error", -1, map_data);
		(*map_data)->map[i] = get_next_line((*map_data)->fd);
		if ((*map_data)->map[i] == NULL)
			break ;
		i++;
		(*map_data)->height++;
	}
}
