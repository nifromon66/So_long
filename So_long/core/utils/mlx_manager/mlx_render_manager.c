/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:02:40 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/21 02:01:09 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	render_manager(t_mlx **mlx)
{
	render_back(mlx, (*mlx)->map_data);
	render_front(mlx, (*mlx)->map_data);
	return (0);
}
void	render_back(t_mlx **mlx, t_map **map_data)
{
	int	i;
	int	j;

	if (!mlx || !*mlx || !map_data || !*map_data)
		return ;
	j = -1;
	while (++j < (*map_data)->h)
	{
		i = -1;
		while (++i < (*map_data)->w)
		{
			if ((*map_data)->map[j][i] == '1')
				my_img_to_win(mlx, (*mlx)->wall_img, i, j);
			else if ((*map_data)->map[j][i] == '0')
				my_img_to_win(mlx, (*mlx)->floor_img, i, j);
		}
	}
}

void	render_front(t_mlx **mlx, t_map **map_data)
{
	int	i;
	int	j;

	if (!mlx || !*mlx || !map_data || !*map_data)
		return ;
	j = -1;
	while (++j < (*map_data)->h)
	{
		i = -1;
		while (++i < (*map_data)->w)
		{
			if ((*map_data)->map[j][i] == 'C')
				my_img_to_win(mlx, (*mlx)->collect_img, i, j);
			else if ((*map_data)->map[j][i] == 'P')
				my_img_to_win(mlx, (*mlx)->player_img, i, j);
			else if ((*map_data)->map[j][i] == 'E')
				my_img_to_win(mlx, (*mlx)->exit_img, i, j);
		}
	}
}

void	my_img_to_win(t_mlx **mlx, void *img, int x, int y)
{
	x = x * 192;
	y = y * 192;
	mlx_put_image_to_window((*mlx)->mlx_p, (*mlx)->win_p, img, x, y);
}