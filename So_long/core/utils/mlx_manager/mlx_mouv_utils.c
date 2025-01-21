/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouv_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:32:27 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/21 02:08:56 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void    update_tile(char *move, int x, int y, t_mlx **mlx, t_map **map_data)
{
    if (ft_strncmp("up", move, 2) == 0)
        y = y + 1;
    else if (ft_strncmp("down", move, 4) == 0)
        y = y - 1;
    else if (ft_strncmp("left", move, 4) == 0)
        x = x + 1;
    else if (ft_strncmp("right", move, 5) == 0)
        x = x - 1;
    if (x == (*map_data)->pos_e[0] && y == (*map_data)->pos_e[1])
    {
        swap_player_image(0, mlx, map_data);
        (*map_data)->map[y][x] = 'E';
    }
    else
        (*map_data)->map[y][x] = '0';
}

void    swap_player_image(int form, t_mlx **mlx, t_map **map_data)
{
    void    *mlx_p;
    int     tx;
    int     ty;
    
    mlx_p = (*mlx)->mlx_p;
    tx = 192;
    ty = 192; 
    if (form == 0)
    {
        mlx_destroy_image(mlx_p, (*mlx)->player_img);
        (*mlx)->player_img = mlx_xpm_file_to_image(mlx_p, PLAYER, &tx, &ty);
	    if (!(*mlx)->player_img)
		    error_manager("Failed "PLAYER" to image", -1, mlx, map_data);
    }
    tx = 192;
    ty = 192; 
    if (form == 1)
    {
        mlx_destroy_image((*mlx)->mlx_p, (*mlx)->player_img);
        (*mlx)->player_img = mlx_xpm_file_to_image(mlx_p, P_E, &tx, &ty);
	    if (!(*mlx)->player_img)
		    error_manager("Failed "P_E" to image", -1, mlx, map_data);
    }
}
