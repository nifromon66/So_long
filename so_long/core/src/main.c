/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:18:08 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/22 11:16:24 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char *argv[])
{
	t_pos	*spawn;
	t_pos	*exit;
	t_map	*map;
	t_img	*img;
	t_mlx	*mlx;

	if (argc != 2)
		error_manager("Incorrect number of arguments", -1);
	map_init_manager(&map, &spawn, &exit);
	map->file = argv[1];
	map_manager(&map);
	mlx_init_manager(&mlx, &map, &img);
	mlx_manager(&mlx);
	free_manager("all", &map, &mlx);
	return (0);
}

void	mlx_manager(t_mlx **mlx)
{
	mlx_render_manager(mlx);
	mlx_interact_manager(mlx, (*mlx)->win_p);
	mlx_loop((*mlx)->mlx_p);
}

void	map_manager(t_map **map)
{
	if (map_check_format((*map)->file) == -1)
		error_manager("Map file has invalid format", -1, map);
	(*map)->fd = open((*map)->file, O_RDONLY);
	if ((*map)->fd == -1)
		error_manager("Couldn't open file", -1, map);
	map_read(map);
	map_check_manager(map);
	map_path_manager(map);
}

void	error_manager(char *error, int level, ...)
{
	va_list	arg;
	t_map	**map;
	t_mlx	**mlx;

	va_start(arg, level);
	map = va_arg(arg, t_map **);
	mlx = va_arg(arg, t_mlx **);
	if (level == 0)
	{
		free_manager("all", map, mlx);
		va_end(arg);
		exit(0);
	}
	if (level == -1)
	{
		ft_printf("\n%sx⸑x [%s%s%s] x⸑x%s\n\n", RED, RESET, error, RED, RESET);
		free_manager("map", map);
	}
	if (level == -2)
	{
		ft_printf("\n%sx⸑x [%s%s%s] x⸑x%s\n\n", RED, RESET, error, RED, RESET);
		free_manager("all", map, mlx);
	}
	va_end(arg);
	exit(1);
}

void	free_manager(char *label, ...)
{
	va_list	arg;
	int		all;

	all = 0;
	va_start(arg, label);
	if (ft_strncmp("all", label, 3) == 0)
		all = 1;
	if ((ft_strncmp("map", label, 3) == 0) || all == 1)
		free_map_data(arg);
	if ((ft_strncmp("mlx", label, 3) == 0) || all == 1)
		free_mlx_data(arg);
	va_end(arg);
}
