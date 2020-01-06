#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP
#include "sharedHeader.hpp"
#include "Player.hpp"

class gamePlay
{
public:
	gamePlay();
	~gamePlay();
	void playGame();
	Player* getPlayer(int num);
	void printWelcome();
	int menu();
	void easyGame();
	//void mediumGame();
	//void hardGame();
	bool winCheck(Pieces player);
	void chooseShot(int* x, int* y);
private:
	Player* player1;
	Player* player2;
	int option;
	int difficulty;
};


#endif // !GAMEPLAY_HPP
