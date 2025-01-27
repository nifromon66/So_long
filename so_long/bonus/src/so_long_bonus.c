/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:18:08 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/27 01:28:32 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_sl_pos	*spawn;
	t_sl_pos	*exit;
	t_sl_map	*map;
	t_sl_img	*img;
	t_sl_game	*game;

	if (argc != 2)
		sl_error_game("Error\nIncorrect number of arguments", -3, &map, &game);
	sl_map_init_manager(&map, &spawn, &exit);
	map->file = argv[1];
	sl_map_manager(&map);
	sl_game_init_manager(&game, &map, &img);
	sl_game_manager(&game);
	sl_error_game("Game session ended succesfully", 0, &map, &game);
	return (0);
}

void	sl_game_manager(t_sl_game **game)
{
	sl_game_place_foe((*game)->map, (*(*game)->map)->foe);
	sl_game_render(game, (*game)->img, (*game)->map);
	mlx_loop_hook((*game)->mlx_p, &sl_game_render_manager, game);
	sl_game_interact_manager(game, (*game)->win_p);
	mlx_loop((*game)->mlx_p);
}

void	sl_map_manager(t_sl_map **map)
{
	int			i;
	
	i = -1;
	if (sl_map_check_format((*map)->file) == -1)
		sl_error_map("Error\nMap file has invalid format", map);
	(*map)->fd = open((*map)->file, O_RDONLY);
	if ((*map)->fd == -1)
		sl_error_map("Error\nCouldn't open file", map);
	sl_map_read(map);
	sl_map_check_manager(map);
	(*map)->foe = (t_sl_pos **)malloc(((*map)->count_c + 1) * sizeof(t_sl_pos *));
	if (!(*map)->foe)
		sl_error_map("Error\nMemory allocation error", map);
	while (++i != (*map)->count_c)
	{
		(*map)->foe[i] = (t_sl_pos *)malloc(sizeof(t_sl_pos));
		if (!(*map)->foe[i])
			sl_error_map("Error\nMemory allocation error", map);
		(*map)->foe[i]->x = 0;
		(*map)->foe[i]->y = 0;
	}
	(*map)->foe[i] = NULL;
	sl_map_path_manager(map);
}

void	sl_error_map(char *error, t_sl_map **map)
{
	ft_printf("%s%s%s\n\n", RED, error, RESET);
	sl_free_map_data(map);
	perror(error);
	exit(1);
}

void	sl_error_game(char *error, int level, t_sl_map **map, t_sl_game **game)
{
	if (level == 0)
	{
		sl_free_map_data(map);
		sl_free_game_data(game);
		ft_printf("\n%s[%s]%s\n\n", GREEN, error, RESET);
		exit(0);
	}
	if (level == -1)
	{
		ft_printf("%s%s%s\n\n", RED, error, RESET);
		sl_free_map_data(map);
	}
	if (level == -2)
	{
		ft_printf("%s%s%s\n\n", RED, error, RESET);
		sl_free_map_data(map);
		sl_free_game_data(game);
	}
	if (level == -3)
		ft_printf("%s%s%s\n\n", RED, error, RESET);
	perror(error);
	exit(1);
}
