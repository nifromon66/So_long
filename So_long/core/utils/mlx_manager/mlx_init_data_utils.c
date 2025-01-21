/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:06:27 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/20 18:29:36 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void  calculate_scale_x(t_mlx **mlx, t_map **map_data)
{
    (*mlx)->win_x = 192 * (*map_data)->w;
}

void  calculate_scale_y(t_mlx **mlx, t_map **map_data)
{
    (*mlx)->win_y = 192 * (*map_data)->h;
}