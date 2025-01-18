/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:16:23 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/18 20:16:36 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	error_manager(char *error, int level, ...)
{
	va_list	arg;
	t_map	**map_data;

	va_start(arg, level);
	map_data = va_arg(arg, t_map **);
	if (level == -1)
	{
		ft_printf("\n%sx⸑x [%s%s%s] x⸑x%s\n\n", RED, RESET, error, RED, RESET);
		if ((*map_data)->fd != -1)
			close((*map_data)->fd);
		free_manager("all", map_data);
		va_end(arg);
		exit(0);
	}
	va_end(arg);
}
