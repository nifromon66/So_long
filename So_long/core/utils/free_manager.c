/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:04:42 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/17 18:23:56 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_manager(char *label)
{
	int	all;

	all = 0;
	if (ft_strncmp("all", label, ft_strlen("all")) == 0)
		all = 1;
	if ((ft_strncmp("map", label, ft_strlen("map")) == 0) || all == 1)
		free_map();
}

void	free_map(void)
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
