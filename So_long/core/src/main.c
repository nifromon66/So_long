/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:52:03 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/16 23:44:02 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_map	*g_map;

int	main(int argc, char *argv[])
{
	if (argc != 2)
		error_manager("Incorrect number of arguments", -1);
	map_init();
	g_map->file_len = ft_strlen(argv[1]);
	g_map->file = argv[1];
	map_manager();
	map_free();
	return (0);
}
