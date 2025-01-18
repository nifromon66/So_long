/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:05:06 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/18 00:31:14 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int my_realloc(void **ptr, int old_size, int new_size)
{
	void *new_ptr;
	int min_size;

	if (!ptr)
		return (-1);
	if (new_size == 0)
	{
		free(*ptr);
		*ptr = NULL;
		return (0);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (-1);
	if (*ptr != NULL)
	{
		if (old_size < new_size)
			min_size = old_size;
		else
			min_size = new_size;
		ft_memcpy(new_ptr, *ptr, min_size);
		free(*ptr);
	}
	*ptr = new_ptr;
	return (0);
}


