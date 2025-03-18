# Rally Car Game

This project is a rally car game developed in C++ using the WinBGIm graphics library. It combines graphical programming, mouse event handling, and game logic to create an interactive two-player experience.

---

## Features

- **Graphical Interface:**  
  The game utilizes various drawing functions (lines, circles, ellipses, etc.) to render the game board, routes, and other visual elements.

- **Flood Fill Algorithm:**  
  An implementation of the flood fill algorithm is used to fill specific regions with designated colors, enhancing the visual effects during gameplay.

- **Route Drawing:**  
  Player routes are generated by functions that interpret vectors of direction values (ranging from 1 to 8), allowing dynamic movement and path creation on the game board.

- **Multiple Difficulty Levels:**  
  Three game modes are available – **Easy**, **Medium**, and **Hard** – each with its own set of routes and challenges.

- **Mouse Interaction:**  
  The game captures mouse click events to let players select movement points and update their routes accordingly.

- **Main Menu:**  
  The main menu provides options to adjust settings, view game rules, and choose the difficulty level, using specific images to guide the user through the selections.

---

## How to Run

1. **Clone/Download:**  
   Clone or download this repository to your local machine.

2. **Setup:**  
   Ensure that the WinBGIm library is installed and correctly configured in your development environment (e.g. Code Blocks ).

---

## Project Structure

- **Drawing Functions:**  
  - `deseneazaTabla`: Draws the game board using a grid.
  - `phill` and `phill2`: Functions for filling and drawing graphical elements.
  - `deseneazatraseu` and `deseneazatraseu2`: Functions that draw the routes based on direction vectors.

- **Interaction Handling:**  
  Functions that detect mouse events, interpret clicks, and update the routes and positions of the players.

- **Difficulty Modes:**  
  The functions `usor` (easy), `mediu` (medium), and `dificil` (hard) implement the game logic for the three modes, each providing a unique experience.


