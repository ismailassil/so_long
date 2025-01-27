# So Long

Welcome to the **So Long Project**! This project is part of the 42 School curriculum and involves creating a 2D game using the **MiniLibX** library, a simple graphics library provided by 42. The goal of this project is to develop a small game where the player navigates a map, collects items, and reaches an exit while avoiding obstacles.

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Game Rules](#game-rules)
6. [Map Format](#map-format)
7. [License](#license)
8. [Acknowledgments](#acknowledgments)

---

## Introduction

The **So Long Project** is a 2D game where the player must navigate through a map, collect all collectibles, and reach the exit to win. The game is rendered using the **MiniLibX** library, which provides basic graphical functionalities such as window management, image rendering, and keyboard/mouse input handling.

This project is an excellent opportunity to learn about game development, graphics programming, and working with external libraries. It also reinforces concepts like memory management, file parsing, and event-driven programming.

---

## Features

- **2D Gameplay**: Simple top-down 2D game with movement, collectibles, and an exit.
- **MiniLibX Integration**: Uses the MiniLibX library for rendering graphics and handling input.
- **Custom Maps**: Load and play custom maps defined in `.ber` files.
- **Player Movement**: Move the player using the arrow keys or `WASD`.
- **Collectibles**: Collect all items on the map to unlock the exit.
- **Win/Lose Conditions**: Win by reaching the exit after collecting all items; lose if you hit an enemy (if implemented).
- **Dynamic Rendering**: The game window dynamically adjusts to the size of the map.

---

## Installation

To get started with the **So Long Project**, follow these steps:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/ismailassil/so_long.git
   cd so_long
   ```

2. **Build the project**:
   ```bash
   make
   ```

3. **Run the game**:
   ```bash
   ./so_long maps/map.ber
   ```
   Replace `maps/map.ber` with the path to your map file.

---

## Usage

Once the game is running, you can control the player using the following keys:

- **Arrow Keys** or **WASD**: Move the player.
- **ESC**: Close the game window.

The objective is to collect all items (represented by `C`) on the map and then reach the exit (represented by `E`). The game will display the number of moves taken and will notify you when you win or lose.

---

## Game Rules

- The player (`P`) must collect all collectibles (`C`) on the map.
- After collecting all items, the player can exit through the exit (`E`).
- The game ends when the player reaches the exit after collecting all items.
- If enemies are implemented, touching an enemy results in a loss.
- The game window will close if the player presses `ESC` or clicks the close button.

---

## Map Format

The game uses `.ber` files to define maps. The map must adhere to the following rules:

- The map must be rectangular.
- The map must be surrounded by walls (`1`).
- The map must contain exactly one player (`P`), one exit (`E`), and at least one collectible (`C`).
- The map can contain empty spaces (`0`) and walls (`1`).

### Example Map (`map1.ber`):
```
111111111
1P00000E1
110C01111
1000000C1
111111111
```

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

## Acknowledgments

- **42 School**: For providing the opportunity and resources to work on this project.
- **MiniLibX**: The graphics library used for rendering the game.
- **Contributors**: Everyone who has contributed to the development of this project.

---

Thank you for checking out the **So Long Project**! We hope you enjoy playing and developing this game. If you have any questions or feedback, please feel free to open an issue or reach out to the maintainers.

Happy gaming! 🎮
