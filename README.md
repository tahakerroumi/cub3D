# cub3D Project

## Overview
This project is inspired by the classic Wolfenstein 3D. It focuses on implementing raycasting, a rendering technique used to create a pseudo-3D perspective in a 2D game environment. The goal is to build a basic game engine that demonstrates raycasting and allows the player to navigate a simple map. This project was developed using the MiniLibX library and the C programming language.

![Design sans titre (1)](https://github.com/user-attachments/assets/3c948421-bbbd-4e26-b22b-6af35c86cd57)


## Features
- **Raycasting Engine:** Implements the fundamental mechanics of raycasting to simulate a 3D perspective using 2D grid-based maps.
- **Player Navigation:** The player can move and rotate their viewpoint within the map.
- **Collision Detection:** Ensures the player cannot walk through walls.
- **Basic Graphics:** Visual representation of walls and floor/ceiling differentiation.

## Challenges
- Implementing accurate collision detection.
- Optimizing raycasting calculations for performance.
- Creating a visually appealing environment within the constraints of the project.
- Add textures to walls for a more immersive experience.
- 
## What I Have Learned
Working on this raycasting project has been an enriching experience. Here are the key takeaways:

1. **Understanding Raycasting:**
   - Learned the mathematical principles behind raycasting and how it simulates 3D effects in a 2D game environment.
   - Gained insight into the importance of optimizing calculations for performance.

2. **Improved C Programming Skills:**
   - Enhanced my ability to work with pointers, arrays, and complex data structures in C.
   - Learned to use the MiniLibX library for graphical rendering and event handling.

3. **Game Development Concepts:**
   - Developed a better understanding of player controls, collision detection, and rendering techniques.
   - Built foundational knowledge in creating interactive and dynamic game environments.

4. **Debugging and Problem-Solving:**
   - Overcame challenges related to collision detection, accurate raycasting, and rendering performance.
   - Improved my debugging skills by identifying and fixing logical errors in the implementation.

5. **Project Organization:**
   - Learned how to structure a project effectively, dividing it into manageable modules and components.
   - Gained experience in writing clean and maintainable code.

## Usage

1. Clone the repository:
   ```bash
   git clone git@github.com:tahakerroumi/cub3D.git
   cd cub3D
2. Compile the program using make
   ```bash
   make
3. Run the program
   ```bash
   ./cub3D map.cub

