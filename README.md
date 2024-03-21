## So_long (a School 42 project)

This repository contains the source code for the So_long project, completed as part of the curriculum at 42. So_long is a simple 2D game where the player has to find their way through a maze to an exit and collect all the collectibles. 

While the game itself is very straightforward, the interesting part about this project is that the program allows users to design their own map for the game. 

The program receives a map file (in a .ber format) as a command line argument. 
A map is a text file, where ‘1’s stand for walls, ‘0’s stand for empty space that can be traversed by the player, an ‘E’ stands for Exit and a ‘P’ stands for the player’s starting position. 

The program then validates the map making sure that it adheres to the following criteria: 
* The map is rectangular and is surrounded by walls.
* The map has exactly 1 exit, 1 player, and at least 1 collectible.
* The map does have a path that allows the player to collect all the collectibles and get to the exit.

The existence of a valid path is checked with the help of a flood-fill algorithm that recursively checks all the available moves.  

All of the functions that perform various operations on strings are custom implementations that I wrote as part of the curriculum at 42. 

This project has been created for education purposes only. 

## Program compilation

Clone the code and run make (for now, the program can only be compiled on a MacOS): 

```bash
make
```

## Launching the game

Launch the executable file so_long with a valid map file as the only command line argument. 
You can use the provided map.ber file or design a map on your own. 

```bash
./so_long map.ber
```
Upon successful validation of the map file, a window containing the game opens.  


## How to play the game

Use arrows to move the character around the map. You must collect all the collectibles and reach the exit. Upon reaching the goal the program will terminate. The amount of moves made by the player is available in the terminal after the game ends as well as in the game window during the game. 
