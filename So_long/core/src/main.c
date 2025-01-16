/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:52:03 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/16 14:54:11 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (printf("ERROR : Incorrect Number of Arguments %d / 1\n", (argc - 1)), 1);
	if (map_manager(argv[1]) == -1)
		return (printf("ERROR : Incorrect Map [%s]\n", argv[1]), 1);
	return (0);
}
