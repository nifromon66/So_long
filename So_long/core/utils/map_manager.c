/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:44:35 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/17 01:02:20 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	map_init(void)
{
	g_map = (t_map *)malloc(sizeof(t_map));
	if (!g_map)
		error_manager("Memory allocation error", -1);
	g_map->file = NULL;
	g_map->map = NULL;
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
	map_read();
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

void	map_read(void)
{
	char	**backup;
    char    *row;
	int		i;

	i = 0;
	row = get_next_line(g_map->fd);
	if (row == NULL)
		error_manager("Map is empty", -1);
	g_map->width = (int) ft_strlen(row);
    while (row != NULL)
    {
		row = get_next_line(g_map->fd);
        backup = g_map->map; // Sauvegarde temporaire
        g_map->map = (char **)malloc((g_map->height + 2) * sizeof(char *));
        if (!g_map->map)
            error_manager("Memory allocation error", -1);
        while (++i < g_map->height)
            g_map->map[i] = backup[i]; // Copie les anciennes lignes
        g_map->map[g_map->height] = row; // Ajoute la nouvelle ligne
        g_map->map[g_map->height + 1] = NULL; // Terminateur
		if (backup)
        	free(backup);
        g_map->height++;
		if (ft_strlen(row) != (size_t) g_map->width)
			error_manager("Map is not rectangular (- irregular width -)", -1);	
    }
}

void	map_free(void)
{
	int	i;

	if (g_map)
	{
		if (g_map->map)
		{
			i = 0;
			while (g_map->map[i] != NULL)
			{
				free(g_map->map[i]);
				g_map->map[i] = NULL;
				i++;
			}
			free(g_map->map);
			g_map->map = NULL;
		}
		free(g_map);
		g_map = NULL;
	}
}