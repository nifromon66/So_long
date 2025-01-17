/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:16:23 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/16 23:41:54 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void    error_manager(char *error, int level)
{
	if (level == -1)
	{
		ft_printf("%sERROR:[%s%s%s]%s\n", RED, RESET, error, RED, RESET);
		free_so_long();
		exit(0);
	}
}

void	free_so_long(void)
{
	map_free();
}

