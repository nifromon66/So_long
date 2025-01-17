/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:16:23 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/17 18:13:20 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	error_manager(char *error, int level)
{
	if (level == -1)
	{
		ft_printf("%sERROR:[%s%s%s]%s\n", RED, RESET, error, RED, RESET);
		free_manager("all");
		exit(0);
	}
}

