/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:06:27 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/20 00:08:46 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int  calculate_scale(t_mlx **mlx, t_map **map_data)
{
    int a;
    int b;

    a = ((*mlx)->win_x / (*map_data)->w);
    b = ((*mlx)->win_y / (*map_data)->h);
    if (a < b)
        return (a);
    return (b);
}