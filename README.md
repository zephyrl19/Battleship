# Battleship
This repository contains my personal project for an interactive 1 player Battleship game with a rudimentary GUI

Language: C++
Author: Austin Crow
Date: 1/6/2020


Contents: Player.cpp, Player.hpp, boardHeader.hpp, boardSource.cpp, gamePlay.hpp, gamePlay.cpp, pieceHeader.hpp, pieceSource.cpp, sharedHeader.hpp, main.cpp


In order to play please use the main.cpp file to start the game.



This game will allow a user to play 1 or more games vs a computer of differing levels of difficulty. The game will initialize with a main
menu allowing the user to select whether to play or not, and then what difficulty of computer to play against.
The game allows the user to manually set the board, or automatically generate the user board for them. The computer will always
randomly generate a board and there is no difference between difficulties for the computer board generation.

On harder difficulties the computer has a smarter algorithm for determining where to place its shots. On easy difficulty the computer
simply randomly selects spaces to target.

The GUI allows the user to see their board and their shots. The game will not allow a duplicate selection, or a selection off of the board.




1/6/2020: At this moment only the easy mode is determined to function correctly. Medium and Hard difficulties are still being implemented.


