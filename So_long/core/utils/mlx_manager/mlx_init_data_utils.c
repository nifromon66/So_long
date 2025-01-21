/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_data_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:06:27 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/21 04:17:08 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void  calculate_scale_x(t_mlx **mlx, t_map **map_data)
{
    if ((*map_data)->w <= 13)
        (*mlx)->win_x = 192 * (*map_data)->w;
    else
        (*mlx)->win_x = 2496;
}

void  calculate_scale_y(t_mlx **mlx, t_map **map_data)
{
    if ((*map_data)->h <= 7)
        (*mlx)->win_y = 192 * (*map_data)->h;
    else
        (*mlx)->win_y = 1344;
}