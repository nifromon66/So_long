/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:44:35 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/17 18:41:07 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	map_init(void)
{
	g_map = (t_map *)malloc(sizeof(t_map));
	if (!g_map)
		error_manager("Memory allocation error", -1);
	g_map->map = (char **)malloc(sizeof(char *));
	if (!g_map->map)
		error_manager("Memory allocation error", -1);
	g_map->map[0] = NULL;
	g_map->file = NULL;
	g_map->height = 0;
	g_map->width = 0;
	g_map->file_len = 0;
	g_map->fd = -1;
}
void	map_manager(void)
{
	map_check_format();
	g_map->fd = open(g_map->file, O_RDONLY);
	if (g_map->fd == -1)
		error_manager("Couldn't open file", -1);
	close(g_map->fd);
}

void	map_check_format(void)
{
	char	format[4];
	int		i;
	int		dot;

	i = 0;
	dot = g_map->file_len - 4;
	while(i != 4)
	{
		format[i] = g_map->file[dot];
		dot++;
		i++;
	}
	format[4] = '\0';
	if (ft_strncmp(format, ".ber", 4) != 0)
		error_manager("Map format incorrect", -1);
}
