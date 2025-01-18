/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:04:42 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/18 00:31:21 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	free_manager(char *label, ...)
{
	va_list	arg;
	int		all;

	all = 0;
	va_start(arg, label);
	if (ft_strncmp("all", label, ft_strlen("all")) == 0)
		all = 1;
	if ((ft_strncmp("map", label, ft_strlen("map")) == 0) || all == 1)
		free_map(arg);
	va_end(arg);
}

void free_map(va_list arg)
{
	int i;
	t_map **map_data;

	map_data = va_arg(arg, t_map **);
	if (*map_data)
	{
		if ((*map_data)->map)
		{
			i = 0;
			while (i != (*map_data)->height + 1)
			{
				if ((*map_data)->map[i] != NULL)
				{
					free((*map_data)->map[i]);
					(*map_data)->map[i] = NULL;
				}
				i++;
			}
			free((*map_data)->map);
			(*map_data)->map = NULL;
		}
		free(*map_data);
		*map_data = NULL;
	}
}

