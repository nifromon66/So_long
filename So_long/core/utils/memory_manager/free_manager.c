/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:04:42 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/19 13:50:15 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	free_manager(char *label, ...)
{
	va_list	arg;
	int		all;

	all = 0;
	va_start(arg, label);
	if (ft_strncmp("all", label, 3) == 0)
		all = 1;
	if ((ft_strncmp("map", label, 3) == 0) || all == 1)
		free_map_data(arg);
	if ((ft_strncmp("mlx", label, 3) == 0) || all == 1)
		free_mlx_data(arg);
	va_end(arg);
}
