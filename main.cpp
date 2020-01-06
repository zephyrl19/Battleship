//THIS IS THE MAIN FILE FOR THE BATTLESHIP GAME!
//THIS FILE WILL CONTAIN THE MAIN SCRIPT THAT WILL RUN AND EXECUTE ALL OTHER FACETS OF THE GAME!

#include "sharedHeader.hpp"
#include "gamePlay.hpp"






int main() {
	srand(time(NULL));
	gamePlay game1;

	
	game1.playGame();

	return 0;
}
