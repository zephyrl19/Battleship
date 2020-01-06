#ifndef BOARDHEADER_HPP
#define BOARDHEADER_HPP

#include "sharedHeader.hpp"
#include "pieceHeader.hpp"


class Board
{
public:
	Board(std::string name);
	~Board();
	void initBoard();
	void printBoard();
	int hitCheck(int x, int y, Board* opponent);
	int willShipFit(int x, int y, int ship, int* returnArray);
	void placeShip(int x, int y, int direction, int ship);

private:
	char** boardPointer;
	char* firstRow;
	char* secondRow;
	std::string boardName;
	
};



#endif // !BOARDHEADER_HPP
