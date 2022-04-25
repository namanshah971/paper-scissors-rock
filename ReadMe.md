# Paper-Scissors-Rock

A naive simulation for the game where player plays the classic game of rock paper and scissors against the computer.

### Environment:
1. Cpp 20
2. CMake 3.22
3. Clang 13
4. MacOS

### What's included:

IGame: an interface for all games, has declaration of enums for GameResult and GameScore which can be used by all the games. 

Referee: given rules, it judges the outcome of a game. I chose to make the class templated so that this class can be used in any game.

PaperRockScissorsGame: concrete implementation of IGame, and it uses referee with the rules of rock paper scissors. 

test/test.cpp: this has unit tests for the referee class that declares the result of the game


## Next Steps:
Use random library instead of srand and rand to get better random moves for computer

Using a more robust library such as gTest to write more robust and extensive tests for the application. 

Add more elements to the game by extending to IGame and using Referee.
