#include "boardHeader.hpp"


Board::Board(std::string name) {

	boardPointer = new char*[10];
	for (int i = 0; i < 10; i++) {
		boardPointer[i] = new char[10];
	}
	initBoard();
	boardName = name;
}

Board::~Board() {

	for (int i = 0; i < 10; i++)
	{
		delete[] boardPointer[i];
	}
	delete[] boardPointer;
}

void Board::initBoard() {

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			boardPointer[i][j] = '-';
		}
	}
}

void Board::printBoard() {
	std::cout << boardName << std::endl;
	std::cout << "  ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << i << " ";
		for (int j = 0; j < 10; j++)
		{
			std::cout << boardPointer[i][j]<< " ";
		}
		std::cout << std::endl;
	}
}


int Board::hitCheck(int y, int x, Board* opponent)
{
	int hitTest = -99;
	//If it is a miss return -1, and set space to 'O', and set shotCounter to 1;
	if (opponent->boardPointer[y][x] == '-')
		{
		hitTest = -1;
		boardPointer[y][x] = 'M';
	}

	//If it is a hit return 1
	else if (opponent->boardPointer[y][x] == 'S')
	{
		hitTest = 1;
		boardPointer[y][x] = 'H';
	}
	
	//If it has already been selected, if a Hit, return 2, if a Miss return -2;
	else if (opponent->boardPointer[y][x] == 'H' || opponent->boardPointer[y][x] == 'M')
	{
		if (opponent->boardPointer[y][x] == 'H')
		{
			hitTest = 2;
		}
		else {
			hitTest = -2;
		}
	}
	
	return hitTest;
}

int Board::willShipFit(int x, int y, int ship, int* returnArray)
{
	
	for (int i = 0; i < 4; i++)
	{
		*(returnArray + i) = 1;
		for (int j = 0; j < ship; j++)
		{
			if (i == 0)
			{
				if ((y - j) <0 || boardPointer[y - j][x] != '-')
				{
					*(returnArray+i) = -1;
				}

			}
			else if (i == 1)
			{
				if ((x + j) >9 || boardPointer[y][x + j] != '-')
				{
					*(returnArray + i) = -1;
				}
			}
			else if (i == 2)
			{
				if ((y + j) >9 || boardPointer[y + j][x] != '-')
				{
					*(returnArray + i) = -1;
				}
			}
			else if (i == 3)
			{
				if ((x - j) <0|| boardPointer[y][x - j] != '-')
				{
					*(returnArray + i) = -1;
				}
			}

		}

	}
	
	if (*(returnArray) == -1 && *(returnArray + 1) == -1 && *(returnArray + 2) == -1 && *(returnArray + 3) == -1 )
	{
		return -1;
	}
	return 1;
	
}



void Board::placeShip(int x, int y, int direction, int ship)
{
		switch (direction)
		{
			//UP
		case 1:
			for (int i = 0; i < ship; i++)
			{
				boardPointer[y-i][x] = 'S';
			}
			break;
			//RIGHT
		case 2:
			for (int i = 0; i < ship; i++)
			{
				boardPointer[y][x+i] = 'S';
			}
			break;
			//DOWN
		case 3:
			for (int i = 0; i < ship; i++)
			{
				boardPointer[y + i][x] = 'S';
			}
			break;
			//LEFT
		case 4:
			for (int i = 0; i < ship; i++)
			{
				boardPointer[y][x-i] = 'S';
			}
			break;
		default:
			break;
		}

}