/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:40:57 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/20 04:09:06 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	mlx_manager(t_mlx **mlx, t_map **map_data)
{
	mlx_init_data(mlx, map_data);
	render_map(mlx, map_data);
	mlx_key_hook((*mlx)->win_p, (int (*)())mlx_deal_key, mlx);
    mlx_loop((*mlx)->mlx_p);
}

int	mlx_deal_key(int key, t_mlx **mlx)
{
	if (key == 65307)
    {
        free_manager("all",(*mlx)->map_data, mlx);
        exit(0);
    }
	return (0);
}

void	render_map(t_mlx **mlx, t_map **map_data)
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
				my_img_to_win(mlx, (*mlx)->space_img, i, j);
			else if ((*map_data)->map[j][i] == 'C')
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
	x = x * (*mlx)->scale;
	y = y * (*mlx)->scale;
	mlx_put_image_to_window((*mlx)->mlx_p, (*mlx)->win_p, img, x, y);
}

