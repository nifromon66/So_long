/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animation_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:50:40 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/22 14:49:53 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	mlx_animation_player(t_mlx **mlx, t_img **img, int move, int pos[])
{
	if (move == 1)
		mlx_animation_player_right(mlx, img, pos[1], pos[0]);
	if (move == 2)
		mlx_animation_player_left(mlx, img, pos[1], pos[0]);
	if (move == 3)
		mlx_animation_player_right_exit(mlx, img, pos[1], pos[0]);
	if (move == 4)
		mlx_animation_player_left_exit(mlx, img, pos[1], pos[0]);
}

void	mlx_animation_player_right(t_mlx **mlx, t_img **img, int x, int y)
{
	mlx_animation_swap(mlx, &(*img)->player, PLAYERR);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYERR1);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYERR2);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYERR3);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYERR4);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYERR5);
	my_img_to_win(mlx, (*img)->player, x, y);
}
void	mlx_animation_player_left(t_mlx **mlx, t_img **img, int x, int y)
{
	mlx_animation_swap(mlx, &(*img)->player, PLAYERL);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYERL1);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYERL2);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYERL3);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYERL4);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYERL5);
	my_img_to_win(mlx, (*img)->player, x, y);
}
void	mlx_animation_player_right_exit(t_mlx **mlx, t_img **img, int x, int y)
{
	mlx_animation_swap(mlx, &(*img)->player, PLAYER_RE);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYER_RE1);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYER_RE2);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYER_RE3);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYER_RE4);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYER_RE5);
	my_img_to_win(mlx, (*img)->player, x, y);
}
void	mlx_animation_player_left_exit(t_mlx **mlx, t_img **img, int x, int y)
{
	mlx_animation_swap(mlx, &(*img)->player, PLAYER_LE);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYER_LE1);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYER_LE2);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYER_LE3);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYER_LE4);
	my_img_to_win(mlx, (*img)->player, x, y);
	usleep(35000);
	mlx_animation_swap(mlx, &(*img)->player, PLAYER_LE5);
	my_img_to_win(mlx, (*img)->player, x, y);
}
