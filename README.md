# So_long

## Project Overview

**So_long** is a small 2D game project from the 42 curriculum that challenges you to build a simple yet functional interactive game using C and the MiniLibX graphics library. The game places the player on a grid-based map alongside collectibles, walls, an exit, and optionally enemies (in the bonus). The player’s goal is to collect all the collectibles and then reach the exit to win.

This project deepens understanding of file parsing, event-driven programming, game loops, graphics rendering, and managing user input.

## Features

- **Map reading and validation** from `.ber` files with strict constraints:
    - Rectangular map.
    - Surrounded by walls on all edges.
    - Exactly one player start position (`P`).
    - At least one collectible (`C`).
    - Exactly one exit (`E`).
    - Optional enemies (`X`) in bonus.
- **Player movement** using keyboard (WASD or arrow keys).
- **Collectible pick-up** with real-time updates.
- **Move counter display** (bonus feature).
- **Basic enemy patrol AI** (bonus feature).
- **Graphical representation** using MiniLibX:
    - Window creation.
    - Sprites for walls, floor, player, exit, collectibles, and enemies.
- **Graceful exit** on window close or keyboard event.
- **Event handling** optimized to update and redraw the game state smoothly.


## Requirements

- Language: C
- Uses the MiniLibX graphics library (X11 or macOS depending on environment)
- Allowed external functions: `open`, `read`, `close`, `malloc`, `free`, `exit`, and MiniLibX functions (`mlx_*`).
- Complies with 42 Norm coding style.
- No memory leaks or crashes.
- Maps must strictly conform to the specified format.


## Map Rules and Validation

- **File extension:** `.ber`
- **Map layout:**
A text file where each character represents:


| Symbol | Description |
| :-- | :-- |
| `1` | Wall |
| `0` | Empty floor space |
| `C` | Collectible item |
| `E` | Exit |
| `P` | Player start position |
| `X` | Enemy (bonus only) |

- **Constraints:**
    - At least 3x3 in size (pragmatically more to be playable).
    - Map is rectangular (all rows have the same length).
    - Surrounded by walls (`1`) on edges; no gaps or holes.
    - Exactly one player start (`P`).
    - At least one collectible (`C`).
    - Exactly one exit (`E`).
    - Enemies optional (bonus).
- **Path validation:**
You implement a flood fill or BFS algorithm to ensure all collectibles and the exit are reachable from the player’s initial position.


## Gameplay Mechanics

- The player moves orthogonally (up, down, left, right) one tile per key press.
- The player can move only through empty floor or collectible spaces, never through walls or enemies.
- When the player reaches a collectible tile, it is picked up (removed from the map), increasing collectible count.
- The exit remains blocked until all collectibles are gathered.
- Upon collecting all collectibles, the player can move onto the exit tile to win, ending the game.
- Bonus: Enemies patrol predefined paths and cause game over if colliding with the player.
- Moves are counted and optionally displayed continuously on screen (bonus).


## Controls

| Key | Action |
| :-- | :-- |
| W or Up Arrow | Move player up |
| S or Down Arrow | Move player down |
| A or Left Arrow | Move player left |
| D or Right Arrow | Move player right |
| ESC or Close Window | Exit the game |

## Architecture \& Program Flow

### Main Modules and Responsibilities

- **Map Parser:**
    - Reads `.ber` map file line by line.
    - Validates map format errors (size, invalid chars, required symbols).
    - Stores map data in a 2D array for rendering and logic.
- **Game State Management:**
    - Struct holding the map, player position, collectibles count, move count, enemy positions (bonus), and pointers to MiniLibX graphical contexts.
- **Rendering Engine:**
    - Loads sprites for map tiles, player, collectibles, enemies, and exit.
    - Draws the full game map on the window every frame or after state changes.
    - Updates move counter (bonus).
- **Input Handler:**
    - Captures key events to move player if possible.
    - Checks for collisions and updates game state accordingly.
    - Triggers game exit on ESC or window close.
- **Game Loop:**
    - Waits for input events and redraws frame when needed.
    - Checks win/lose conditions (completion or collision with enemy in bonus).
    - On victory or exit, cleanly frees resources and closes window.
- **Bonus Enhancements:**
    - Enemy movement logic runs per turn or timer, following preset patrol paths.
    - Animations and move counter display for improved player feedback.


### Data Structures

- Map stored as `char **` (array of strings).
- Coordinates tracked with `int` variables for player and enemies.
- Game state encapsulated in structs to pass between functions.


### Flow Example

```
program start
      ↓
parse and validate map file
      ↓
initialize game state and graphical window
      ↓
render initial map and sprites
      ↓
event loop:
   wait for player input → update position if valid
   update collectibles count if collected
   update enemy positions (bonus)
   redraw map and move counter
   check for win/loss → exit if triggered
      ↓
cleanup and exit
```


## Compilation

Use the provided Makefile:

```bash
make         # builds the mandatory executable (so_long)
make bonus   # builds executable including bonus features
make clean   # removes object files
make fclean  # removes executables and object files
make re      # recompiles everything
```


## Usage

```bash
./so_long <path_to_map.ber>
```

**Example:**

```bash
./so_long maps/map1.ber
```

- Program opens a window and loads the level described by the map.
- Use keyboard to move player, collect all `C`s, and reach `E`.
- Moves are displayed in the window (bonus).
- Exiting closes the window gracefully.


## Error Handling

- Invalid or missing map file: program prints an error message and exits.
- Map format violations produce descriptive errors:
    - Non-rectangular map
    - Missing walls in boundary
    - Missing or multiple required elements (`P`, `E`, `C`)
    - Invalid characters in the map
    - Unreachable collectibles or exit
- Memory allocation or MiniLibX failures are caught and reported.
- Program exits cleanly on errors with relevant messages.


## Bonus Features

- **Enemy Patrols:** Enemies move along fixed or predefined paths; collision with player ends the game.
- **Move Counter Display:** An overlay shows the current number of moves the player has made.
- **Animations:** Animated sprites for player/enemies and collectible effects.
- **Graceful Exit Handling:** Closes window correctly on ESC or window close events.


## Credits

Author: [Nicolas Fromont, alias nifromon]
Project completed as part of the 42 School curriculum.
