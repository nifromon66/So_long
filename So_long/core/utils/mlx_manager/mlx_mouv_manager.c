/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouv_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:01:13 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/21 02:35:04 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void    move_up(t_mlx **mlx, t_map **map_data)
{
    int 	pos_x;
    int 	pos_y;

    pos_x = (*map_data)->pos_p[0];
    pos_y = (*map_data)->pos_p[1] - 1;
    if ((*map_data)->map[pos_y][pos_x] != '1')
    {
        if ((*map_data)->map[pos_y][pos_x] == 'E' && (*map_data)->cnt_c != 0)
			swap_player_image(1, mlx, map_data);
		else if ((*map_data)->map[pos_y][pos_x] == 'E')
			return (free_manager("all", map_data, mlx), exit(0));
		else if ((*map_data)->map[pos_y][pos_x] == 'C')
			(*map_data)->cnt_c--;
		(*map_data)->map[pos_y][pos_x] = 'P';
		update_tile("up", pos_x, pos_y, mlx, map_data);
		(*map_data)->pos_p[1] = pos_y;
    }
}
void    move_down(t_mlx **mlx, t_map **map_data)
{
    int 	pos_x;
    int 	pos_y;

    pos_x = (*map_data)->pos_p[0];
    pos_y = (*map_data)->pos_p[1] + 1;
    if ((*map_data)->map[pos_y][pos_x] != '1')
    {
        if ((*map_data)->map[pos_y][pos_x] == 'E' && (*map_data)->cnt_c != 0)
			swap_player_image(1, mlx, map_data);
		else if ((*map_data)->map[pos_y][pos_x] == 'E')
			return (free_manager("all", map_data, mlx), exit(0));
		else if ((*map_data)->map[pos_y][pos_x] == 'C')
			(*map_data)->cnt_c--;
		(*map_data)->map[pos_y][pos_x] = 'P';
		update_tile("down", pos_x, pos_y, mlx, map_data);
		(*map_data)->pos_p[1] = pos_y;
    }
}
void    move_left(t_mlx **mlx, t_map **map_data)
{
    int 	pos_x;
    int 	pos_y;

    pos_x = (*map_data)->pos_p[0] - 1;
    pos_y = (*map_data)->pos_p[1];
    if ((*map_data)->map[pos_y][pos_x] != '1')
    {
        if ((*map_data)->map[pos_y][pos_x] == 'E' && (*map_data)->cnt_c != 0)
			swap_player_image(1, mlx, map_data);
		else if ((*map_data)->map[pos_y][pos_x] == 'E')
			return (free_manager("all", map_data, mlx), exit(0));
		else if ((*map_data)->map[pos_y][pos_x] == 'C')
			(*map_data)->cnt_c--;
		(*map_data)->map[pos_y][pos_x] = 'P';
		update_tile("left", pos_x, pos_y, mlx, map_data);
		(*map_data)->pos_p[0] = pos_x;
    }
}
void    move_right(t_mlx **mlx, t_map **map_data)
{
    int 	pos_x;
    int 	pos_y;

    pos_x = (*map_data)->pos_p[0] + 1;
    pos_y = (*map_data)->pos_p[1];
    if ((*map_data)->map[pos_y][pos_x] != '1')
    {
        if ((*map_data)->map[pos_y][pos_x] == 'E' && (*map_data)->cnt_c != 0)
			swap_player_image(1, mlx, map_data);
		else if ((*map_data)->map[pos_y][pos_x] == 'E')
			return (free_manager("all", map_data, mlx), exit(0));
		else if ((*map_data)->map[pos_y][pos_x] == 'C')
			(*map_data)->cnt_c--;
		(*map_data)->map[pos_y][pos_x] = 'P';
		update_tile("right", pos_x, pos_y, mlx, map_data);
		(*map_data)->pos_p[0] = pos_x;
    }
}