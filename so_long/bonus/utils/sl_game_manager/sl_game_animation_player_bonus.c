/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_animation_player_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:03:41 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/25 23:42:52 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long_bonus.h"

void	sl_game_animation_player(t_sl_game **game, int move, int pos[])
{
	if (move == 1)
		sl_game_animation_pr(game, (*game)->img, pos[1], pos[0]);
	else if (move == 2)
		sl_game_animation_pl(game, (*game)->img, pos[1], pos[0]);
	else if (move == 3)
		sl_game_animation_pre(game, (*game)->img, pos[1], pos[0]);
	else if (move == 4)
		sl_game_animation_ple(game, (*game)->img, pos[1], pos[0]);
}

void	sl_game_animation_pr(t_sl_game **game, t_sl_img **img, int x, int y)
{
	sl_game_images_swap(game, &(*img)->player, PLAYERR);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYERR1);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYERR2);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYERR3);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYERR4);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYERR5);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
}

void	sl_game_animation_pl(t_sl_game **game, t_sl_img **img, int x, int y)
{
	sl_game_images_swap(game, &(*img)->player, PLAYERL);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYERL1);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYERL2);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYERL3);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYERL4);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYERL5);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
}

void	sl_game_animation_pre(t_sl_game **game, t_sl_img **img, int x, int y)
{
	sl_game_images_swap(game, &(*img)->player, PLAYER_RE);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYER_RE1);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYER_RE2);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYER_RE3);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYER_RE4);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYER_RE5);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
}

void	sl_game_animation_ple(t_sl_game **game, t_sl_img **img, int x, int y)
{
	sl_game_images_swap(game, &(*img)->player, PLAYER_LE);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYER_LE1);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYER_LE2);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYER_LE3);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYER_LE4);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
	sl_game_images_swap(game, &(*img)->player, PLAYER_LE5);
	my_img_to_win(game, (*img)->player, x, y);
	usleep(FRAMES);
}
