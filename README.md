![So_long](https://github.com/user-attachments/assets/a7bd9a51-84bc-4a29-8ab2-5998cc174d46)

## Project Description

**So Long** is a 2D game where the player controls a character that must navigate through a map, collect items, and reach the exit. The game is built using the MiniLibX library and follows specific map creation rules to ensure a valid and playable game environment. This project is realized within the framework of the 42 common core and it implies the 42 norm and other details.

## Features

- 2D top-down view
- Smooth player movement in four directions (W, A, S, D keys)
- Heal (H)
- Sprint (Shift)
- Real Pause Menu (Esc)
- Minimap and hud
- Player animations and actions
- Collectible items
- Enemies that chase the player
- Exit door that opens when all items are collected
- Map validation to ensure a valid game environment

## Installation Instructions

### Dependencies

- MiniLibX library
- Libft library
- ft_printf library

### Build Steps

1. Clone the repository:
   ```sh
   git clone https://github.com/LolelsayFR/42.so_long.git
   cd 42.so_long
   ```

2. Build the project using the provided Makefile:
   ```sh
   make
   ```

3. To build the project with the `DEBUG` macro set to 1:
   ```sh
   make debug
   ```

## Usage Instructions

### Running the Game

To run the game, use the following command:
```sh
./so_long path/to/map.ber
```

### Controls

- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right
- **ESC**: Pause menu
- **Space**: Primary action
- **H**: Heal

## Map Creation Rules

### Map Elements and Their Meanings

- **W**: Wall - must surround all elements.
- **:**: Objective Chest Close
- **;**: Objective Chest Open - Only 4 required.
- **-**: Weapon Chest Open.
- **~**: Weapon Chest Closed.
- **.**: Empty space.
- **E**: Exit door - only one allowed.
- **F**: Finish Point
- **@**: Player - only one allowed.
- **$**: Enemy - A ghost.
- **&**: Enemy - Spike

### Map Structure and Requirements

- **Rectangular shape**: The map must be a perfect rectangle.
- **Enclosure**: The map must be entirely enclosed by walls or the exit (the exit is considered a closing element).
- **Room requirement (optional but good)**: A "room" is defined as a 5x5 square enclosed by walls or doors.
- **Door placement (optional)**: Doors must be placed in the middle of walls.
- **Map traversability**: The player must be able to traverse the entire map, collect all 4 objectives, and reach the finish point without any obstacles.
- **Map validation**: All maps will be subjected to a validation function at the start of the game. Any errors will result in an error message.
- **Corners**: The map should only have floor or wall in the corners of the room (x % 4 == 0 || y % 4 == 0).

### Basic Map Example

```
WWWWWWWWWWWWW
W-..W.:.W...W
W.@.D...W...W
W...W..:W...W
WWWWWWDWWWDWW
W:..W...W...W
W...D...E.F.W
W...W:..W...W
WWWWWWWWWWWWW
```

### Bad Map Examples

#### Example 1: Not Rectangular
```
WWWWWWWWWWWWW
W-..W.:.W...W
W.@.D...W...W
W...W..:W...W
WWWWWWDWWWDWW
W:..W...W...W
W...D...E.F.W
W...W:..W...W
WWWWWWWWWWWW
```

#### Example 2: Not Enclosed
```
WWWWWWWWWWWWW
W-..W.:.W...W
W.@.D...W...W
W...W..:W...W
WWWWWWDWWWDWW
W:..W...W...W
W...D...E.F.W
W...W:..W...W
W.WWWWWWWWWWW
```

#### Example 3: Invalid Characters
```
WWWWWWWWWWWWW
W-..W.:.W...W
W.@.D...W...W
W...W..:W...W
WWWWWPTDRWDWW
W:..W...W...W
W...D...E.F.W
W...W:..W...W
WWWWWWWWWWWWW
```

#### Example 4: Bad Spawn count AND Finish point
```
WWWWWWWWWWWWW
W-..W.:.W...W
W.@.D...W...W
W...W.@:W...W
WWWWWWWWWWDWW
W:..W...W.F.W
W...D...E.F.W
W...W:..W...W
WWWWWWWWWWWWW
```

#### Example 5: No path
```
WWWWWWWWWWWWW
W-..W.:.W...W
W.@.W...W...W
W...W.@:W...W
WWWWWWWWWWDWW
W:..W...W.F.W
W...D...E.F.W
W...W:..W...W
WWWWWWWWWWWWW
```

## Lot of example are in maps/test/*.ber
