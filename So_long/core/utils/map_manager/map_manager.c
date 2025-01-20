/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:44:35 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/19 16:28:09 by nifromon         ###   ########.fr       */
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
	(*map_data)->map[0] = NULL;
	(*map_data)->h = 0;
	(*map_data)->w = 0;
	(*map_data)->file_len = 0;
	(*map_data)->fd = -1;
	(*map_data)->count_zero = 0;
	(*map_data)->count_p = 0;
	(*map_data)->pos_p[0] = 0;
	(*map_data)->pos_p[1] = 0;
	(*map_data)->count_c = 0;
	(*map_data)->count_e = 0;
	(*map_data)->pos_e[0] = 0;
	(*map_data)->pos_e[1] = 0;
}

void	map_init_directions(t_map **map_data)
{
	int	i;
	int	j;

	(*map_data)->visited = (int **)malloc((*map_data)->h * sizeof(int *));
	if (!(*map_data)->visited)
		error_manager("Memory allocation error", -1, map_data);
	j = -1;
	while (++j != (*map_data)->h)
	{
		(*map_data)->visited[j] = (int *)malloc((*map_data)->w * sizeof(int));
		if (!(*map_data)->visited[j])
			error_manager("Memory allocation error", -1, map_data);
		i = -1;
		while (++i != (*map_data)->w)
			(*map_data)->visited[j][i] = 0;
	}
	(*map_data)->dx[0] = 1;
	(*map_data)->dx[1] = -1;
	(*map_data)->dx[2] = 0;
	(*map_data)->dx[3] = 0;
	(*map_data)->dy[0] = 0;
	(*map_data)->dy[1] = 0;
	(*map_data)->dy[2] = 1;
	(*map_data)->dy[3] = -1;
}

void	map_manager(t_map **map_data)
{
	int	start_x;
	int	start_y;

	map_valid_ext(map_data);
	(*map_data)->fd = open((*map_data)->file, O_RDONLY);
	if ((*map_data)->fd == -1)
		error_manager("Couldn't open map file", -1, map_data);
	map_read(map_data);
	map_init_directions(map_data);
	map_check_rectangle(map_data);
	map_check_enclosement(map_data);
	map_check_characters(map_data);
	map_check_elements(map_data);
	map_find_spawn(map_data);
	map_find_exit(map_data);
	start_x = (*map_data)->pos_p[0];
	start_y = (*map_data)->pos_p[1];
	if (map_check_way(start_x, start_y, map_data) == 0)
		error_manager("No valid way to the exit", -1, map_data);
}

void	map_valid_ext(t_map **map_data)
{
	char	format[4];
	int		i;
	int		dot;

	i = 0;
	dot = (*map_data)->file_len - 4;
	while (i != 4)
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
	(*map_data)->h = i;
	while (1)
	{
		old_size = ((*map_data)->h * sizeof(char *));
		new_size = (((*map_data)->h + 1) * sizeof(char *));
		if (my_realloc((void **)&(*map_data)->map, old_size, new_size) == -1)
			error_manager("Memory allocation error", -1, map_data);
		(*map_data)->map[i] = get_next_line((*map_data)->fd);
		if ((*map_data)->map[i] == NULL)
			break ;
		i++;
		(*map_data)->h++;
	}
	(*map_data)->w = (int) ft_strlen((*map_data)->map[0]) - 1;
}
