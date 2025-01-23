/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:18:08 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/23 22:45:46 by nifromon         ###   ########.fr       */
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
		error_mlx("Error\nIncorrect number of arguments", -3, &map, &mlx);
	map_init_manager(&map, &spawn, &exit);
	map->file = argv[1];
	map_manager(&map);
	mlx_init_manager(&mlx, &map, &img);
	mlx_manager(&mlx);
	error_mlx("Game session ended succesfully", 0, &map, &mlx);
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
		error_map("Error\nMap file has invalid format", map);
	(*map)->fd = open((*map)->file, O_RDONLY);
	if ((*map)->fd == -1)
		error_map("Error\nCouldn't open file", map);
	map_read(map);
	map_check_manager(map);
	map_path_manager(map);
}

void	error_map(char *error, t_map **map)
{
	ft_printf("%s%s%s\n\n", RED, error, RESET);
	free_map_data(map);
	perror(error);
	exit(1);
}

void	error_mlx(char *error, int level, t_map **map, t_mlx **mlx)
{
	if (level == 0)
	{
		free_map_data(map);
		free_mlx_data(mlx);
		ft_printf("\n%s[%s]%s\n\n", GREEN, error, RESET);
		exit(0);
	}
	if (level == -1)
	{
		ft_printf("%s%s%s\n\n", RED, error, RESET);
		free_map_data(map);
	}
	if (level == -2)
	{
		ft_printf("%s%s%s\n\n", RED, error, RESET);
		free_map_data(map);
		free_mlx_data(mlx);
	}
	if (level == -3)
		ft_printf("%s%s%s\n\n", RED, error, RESET);
	perror(error);
	exit(1);
}
