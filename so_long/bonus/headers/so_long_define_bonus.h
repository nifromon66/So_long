/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_define_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 05:42:41 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/27 09:53:09 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEFINE_BONUS_H
# define SO_LONG_DEFINE_BONUS_H

// Colors
# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"
# define RESET		"\033[0;0m"

// Pixel colors
# define PIX		0xFF0000

// Keycodes
# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

// Tile size
# define TILE		192

// Delay between animation frames
# define FRAMES		30000
# define FRAMES_FOE	35000

// Assets
	// Background
# define WALL		"./assets/wall/wall.xpm"
# define FLOOR		"./assets/floor/floor.xpm"
# define EXIT_OFF	"./assets/exit/exit_off.xpm"
# define EXIT_ON	"./assets/exit/exit_on.xpm"
	// Collectibles
# define COLLECT	"./assets/collect/collect.xpm"
	// Player Basic
# define PLAYERR	"./assets/player/player_right/player_right.xpm"
# define PLAYERL	"./assets/player/player_left/player_left.xpm"
	// Player on exit off
# define PLAYER_RE	"./assets/player/on_exit_right/player_on_exit_right.xpm"
# define PLAYER_LE	"./assets/player/on_exit_left/player_on_exit_left.xpm"
	// Player animation right
# define PLAYERR1	"./assets/player/player_right/player_right1.xpm"
# define PLAYERR2	"./assets/player/player_right/player_right2.xpm"
# define PLAYERR3	"./assets/player/player_right/player_right3.xpm"
# define PLAYERR4	"./assets/player/player_right/player_right4.xpm"
# define PLAYERR5	"./assets/player/player_right/player_right5.xpm"
	// Player animation left
# define PLAYERL1	"./assets/player/player_left/player_left1.xpm"
# define PLAYERL2	"./assets/player/player_left/player_left2.xpm"
# define PLAYERL3	"./assets/player/player_left/player_left3.xpm"
# define PLAYERL4	"./assets/player/player_left/player_left4.xpm"
# define PLAYERL5	"./assets/player/player_left/player_left5.xpm"
	// Player animation on exit off right
# define PLAYER_RE1	"./assets/player/on_exit_right/player_on_exit_right1.xpm"
# define PLAYER_RE2	"./assets/player/on_exit_right/player_on_exit_right2.xpm"
# define PLAYER_RE3	"./assets/player/on_exit_right/player_on_exit_right3.xpm"
# define PLAYER_RE4	"./assets/player/on_exit_right/player_on_exit_right4.xpm"
# define PLAYER_RE5	"./assets/player/on_exit_right/player_on_exit_right5.xpm"
	// Player animation on exit off left
# define PLAYER_LE1	"./assets/player/on_exit_left/player_on_exit_left1.xpm"
# define PLAYER_LE2	"./assets/player/on_exit_left/player_on_exit_left2.xpm"
# define PLAYER_LE3	"./assets/player/on_exit_left/player_on_exit_left3.xpm"
# define PLAYER_LE4	"./assets/player/on_exit_left/player_on_exit_left4.xpm"
# define PLAYER_LE5	"./assets/player/on_exit_left/player_on_exit_left5.xpm"
// Foe animation
	// Foe_open
# define FOE_OPEN	"./assets/foe/foe_open/foe_open.xpm"
# define FOE_OPEN1	"./assets/foe/foe_open/foe_open1.xpm"
# define FOE_OPEN2	"./assets/foe/foe_open/foe_open2.xpm"
# define FOE_OPEN3	"./assets/foe/foe_open/foe_open3.xpm"
# define FOE_OPEN4	"./assets/foe/foe_open/foe_open4.xpm"
# define FOE_OPEN5	"./assets/foe/foe_open/foe_open5.xpm"
# define FOE_OPEN6	"./assets/foe/foe_open/foe_open6.xpm"
	// Foe_close
# define FOE_CLOSE	"./assets/foe/foe_close/foe_close.xpm"
# define FOE_CLOSE1	"./assets/foe/foe_close/foe_close1.xpm"
# define FOE_CLOSE2	"./assets/foe/foe_close/foe_close2.xpm"
# define FOE_CLOSE3	"./assets/foe/foe_close/foe_close3.xpm"
# define FOE_CLOSE4	"./assets/foe/foe_close/foe_close4.xpm"
# define FOE_CLOSE5	"./assets/foe/foe_close/foe_close5.xpm"
	// Foe_boom
# define FOE_BOOM	"./assets/foe/foe_boom/foe_boom.xpm"
# define FOE_BOOM1	"./assets/foe/foe_boom/foe_boom1.xpm"
# define FOE_BOOM2	"./assets/foe/foe_boom/foe_boom2.xpm"
	// Explosion effect
# define EXPLOSION	"./assets/effects/explosion/explosion.xpm"
# define EXPLOSION1	"./assets/effects/explosion/explosion1.xpm"
# define EXPLOSION2	"./assets/effects/explosion/explosion2.xpm"
# define EXPLOSION3	"./assets/effects/explosion/explosion3.xpm"
# define EXPLOSION4	"./assets/effects/explosion/explosion4.xpm"
# define EXPLOSION5	"./assets/effects/explosion/explosion5.xpm"
# define EXPLOSION6	"./assets/effects/explosion/explosion6.xpm"
# define EXPLOSION7	"./assets/effects/explosion/explosion7.xpm"
# define EXPLOSION8	"./assets/effects/explosion/explosion8.xpm"

# ifdef UNDEFINE_SO_LONG_BONUS_MACROS
#  undef BLACK
#  undef RED
#  undef GREEN
#  undef YELLOW
#  undef BLUE
#  undef PURPLE
#  undef CYAN
#  undef WHITE
#  undef RESET
#  undef KEY_ESC
#  undef KEY_W
#  undef KEY_A
#  undef KEY_S
#  undef KEY_D
#  undef TILE
#  undef WALL
#  undef FLOOR
#  undef EXIT_OFF
#  undef EXIT_ON
#  undef COLLECT
#  undef PLAYERR
#  undef PLAYERL
#  undef PLAYER_RE
#  undef PLAYER_LE
#  undef PLAYERR1
#  undef PLAYERR2
#  undef PLAYERR3
#  undef PLAYERR4
#  undef PLAYERR5
#  undef PLAYERL1
#  undef PLAYERL2
#  undef PLAYERL3
#  undef PLAYERL4
#  undef PLAYERL5
#  undef PLAYER_RE1
#  undef PLAYER_RE2
#  undef PLAYER_RE3
#  undef PLAYER_RE4
#  undef PLAYER_RE5
#  undef PLAYER_LE1
#  undef PLAYER_LE2
#  undef PLAYER_LE3
#  undef PLAYER_LE4
#  undef PLAYER_LE5
#  undef PIX
#  undef FOE_OPEN
#  undef FOE_OPEN1
#  undef FOE_OPEN2
#  undef FOE_OPEN3
#  undef FOE_OPEN4
#  undef FOE_OPEN5
#  undef FOE_CLOSE
#  undef FOE_CLOSE1
#  undef FOE_CLOSE2
#  undef FOE_CLOSE3
#  undef FOE_CLOSE4
#  undef FOE_CLOSE5
#  undef FOE_BOOM
#  undef FOE_BOOM1
#  undef FOE_BOOM2
#  undef EXPLOSION
#  undef EXPLOSION1
#  undef EXPLOSION2
#  undef EXPLOSION3
#  undef EXPLOSION4
#  undef EXPLOSION5
#  undef EXPLOSION6
#  undef EXPLOSION7
#  undef EXPLOSION8
# endif

#endif
