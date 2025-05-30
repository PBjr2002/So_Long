# So_Long

## Project Overview

**So_Long** was a 2D tile-based game developed as part of the 42 programming school curriculum. The goal of the project extended beyond simply making a game — it involved building a **custom game engine** from scratch using **MiniLibX**, a lightweight graphical library. This required handling input, graphics, map parsing, and game logic, all at a low level in C.

The game concept was inspired by **classic snake mechanics**: the player character **grows longer each time it collects an item**, and the game ends if the player collides with its own body or touches an enemy. This added a strategic layer to the gameplay, requiring careful navigation of the map.

The project focused on:
- Designing a minimal game engine using low-level system functions
- Integrating graphics with MiniLibX
- Parsing map files and validating gameplay rules
- Managing user input, game events, and memory
- Displaying **animated sprites** to enhance visual feedback
- Showing the **movement counter on screen**
- Adding **enemy patrols** that ended the game on contact

---

## Gameplay

- The player moves using **W, A, S, D**
- All **collectibles (`C`)** have to be gathered before exiting the level
- The player has to reach the **exit (`E`)** to win
- Movement into **walls (`1`)** is not allowed
- Contact with **enemies** results in game over
- The starting position is marked by **`P`**
- The number of moves is updated and displayed **on screen**
- Pressing the **ESC** key exits the game cleanly

---

## Demonstration

![Gameplay Demo](https://media4.giphy.com/media/v1.Y2lkPTc5MGI3NjExYTFrMXBwN3V6aXBta3R0dmM2bnNvZ3FvZHY2d3NwMmt5NnZqZTd4MiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/leBjDLop60leRCDMlp/giphy.gif)

<!-- 
🎥 Add a gameplay GIF or video preview here later. 
You can use a screen recording tool (like OBS or Peek), convert it to GIF or upload the video directly.
Example:
![Gameplay Demo](./assets/demo.gif)
-->
