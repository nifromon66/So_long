/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_define.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 05:42:41 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/24 08:31:51 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEFINE_H
# define SO_LONG_DEFINE_H

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

// Keycodes
# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

// Tile size
# define TILE		192

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

# ifdef UNDEFINE_SO_LONG_MACROS
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
# endif

#endif