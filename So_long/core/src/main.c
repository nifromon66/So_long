/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:52:03 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/19 01:25:05 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char *argv[])
{
	t_map	*map_data;
	t_mlx	*mlx;

	if (argc != 2)
		error_manager("Incorrect number of arguments", -1);
	map_init(&map_data);
	map_data->file_len = ft_strlen(argv[1]);
	map_data->file = argv[1];
	map_manager(&map_data);
	mlx_manager(&mlx, &map_data);
	free_manager("all", &map_data, &mlx);
	return (0);
}
