/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:16:23 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/21 04:49:17 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	error_manager(char *error, int level, ...)
{
	va_list	arg;
	t_map	**map_data;
	t_mlx	**mlx;

	va_start(arg, level);
	map_data = va_arg(arg, t_map **);
	mlx = va_arg(arg, t_mlx **);
	if (level == -1)
	{
		ft_printf("\n%sx⸑x [%s%s%s] x⸑x%s\n\n", RED, RESET, error, RED, RESET);
		free_manager("all", map_data, mlx);
		va_end(arg);
		exit(0);
	}
	if (level == -2)
	{
		ft_printf("\n%sx⸑x [%s%s%s] x⸑x%s\n\n", RED, RESET, error, RED, RESET);
		free_manager("map", map_data);
		va_end(arg);
		exit(0);
	}
	va_end(arg);
}
