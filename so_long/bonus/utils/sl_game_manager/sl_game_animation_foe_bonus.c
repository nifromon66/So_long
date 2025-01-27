/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_animation_foe_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:57:59 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/27 05:30:16 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long_bonus.h"

void	sl_game_animation_foe(t_sl_game **game, int move, t_sl_pos *foe)
{
	if (move == 1)
		sl_game_animation_fo(game, (*game)->img, foe->x, foe->y);
	else if (move == 2)
		sl_game_animation_fc(game, (*game)->img, foe->x, foe->y);
	else if (move == 3)
		sl_game_animation_fb(game, (*game)->img, foe->x, foe->y);
	else if (move == 4)
		sl_game_animation_boom(game, (*game)->img, foe->x, foe->y);
}

void	sl_game_animation_fo(t_sl_game **game, t_sl_img **img, int x, int y)
{
	sl_game_images_swap(game, &(*img)->foe, FOE_OPEN);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, FOE_OPEN1);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, FOE_OPEN2);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, FOE_OPEN3);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, FOE_OPEN4);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, FOE_OPEN5);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, FOE_OPEN6);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
}

void	sl_game_animation_fc(t_sl_game **game, t_sl_img **img, int x, int y)
{
	sl_game_images_swap(game, &(*img)->foe, FOE_CLOSE);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, FOE_CLOSE1);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, FOE_CLOSE2);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, FOE_CLOSE3);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, FOE_CLOSE4);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, FOE_CLOSE5);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
}

void	sl_game_animation_fb(t_sl_game **game, t_sl_img **img, int x, int y)
{
	sl_game_images_swap(game, &(*img)->foe, FOE_BOOM);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, FOE_BOOM1);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, FOE_BOOM2);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, EXPLOSION);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
}

void	sl_game_animation_boom(t_sl_game **game, t_sl_img **img, int x, int y)
{
	sl_game_images_swap(game, &(*img)->foe, EXPLOSION1);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, EXPLOSION2);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, EXPLOSION3);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, EXPLOSION4);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, EXPLOSION5);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, EXPLOSION6);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, EXPLOSION7);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
	sl_game_images_swap(game, &(*img)->foe, EXPLOSION8);
	my_img_to_win(game, (*img)->foe, x, y);
	usleep(FRAMES_FOE);
}
