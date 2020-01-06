#include "pieceHeader.hpp"



Pieces::Pieces()
{
	pieceVector = std::vector<std::vector<int>>(5);

	for (int i = 0; i < 5; i++)
	{
		pieceVector[i] = std::vector<int>(10);
		for (int j = 0; j < 10; j++)
		{
			pieceVector[i][j] = 0;
		}
	}
	//stupid initialize
	//Every [5] slot is the size of the ship
	//Every slot [0-4] represent ship health
	//1 means a full slot, as game progresses 1's will be replaced with 0's.
	//Every 9'th slot will be a 1 (ship is alive) or a 0 (ship is dead) depending on ship health
	pieceVector[0][0] = 1;
	pieceVector[0][1] = 1;
	pieceVector[0][2] = 1;
	pieceVector[0][3] = 1;
	pieceVector[0][4] = 1;
	pieceVector[0][5] = 5;
	pieceVector[1][0] = 1;
	pieceVector[1][1] = 1;
	pieceVector[1][2] = 1;
	pieceVector[1][3] = 1;
	pieceVector[1][5] = 4;
	pieceVector[2][0] = 1;
	pieceVector[2][1] = 1;
	pieceVector[2][2] = 1;
	pieceVector[2][5] = 3;
	pieceVector[3][0] = 1;
	pieceVector[3][1] = 1;
	pieceVector[3][2] = 1;
	pieceVector[3][5] = 3;
	pieceVector[4][0] = 1;
	pieceVector[4][1] = 1;
	pieceVector[4][5] = 2;
}

Pieces::~Pieces()
{

}


void Pieces::displayPieces()
{
	for (int i = 0; i < pieceVector.size(); i++) {
		for (int j = 0; j < pieceVector[i].size(); j++)
			std::cout << pieceVector[i][j] << " ";
		std::cout << std::endl;
	}
}

void Pieces::displayShips()
{
	for (int i = 0; i < 5; i++)
	{
		int x = 0;
		//Set x to ship length for each row
		x = pieceVector[i][5];
		std::cout << "SHIP " << i << ": ";
		//For x iterations print out the values
		for (int j = 0; j < x; j++)
		{
			std::cout << pieceVector[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


void Pieces::setHit(int x, int y)
{
	int i = 0;
	int shipId = 0;

	while (i < 5)
	{
		switch (pieceVector[i][8])
		{
			//UP
		case 1:
			if (y <= pieceVector[i][7] && y > pieceVector[i][7]-pieceVector[i][5])
			{
				if (x == pieceVector[i][6])
				{
					shipId = i;
					addHit(shipId);
				}

			}
			break;
			//RIGHT
		case 2:
			if (x >= pieceVector[i][6] && x <= pieceVector[i][6] + pieceVector[i][5])
			{
				if (y == pieceVector[i][7])
				{
					shipId = i;
					addHit(shipId);
				}

			}
			break;
			//DOWN
		case 3:
			if (y >= pieceVector[i][7] && y < pieceVector[i][7] + pieceVector[i][5])
			{
				if (x == pieceVector[i][6])
				{
					shipId = i;
					addHit(shipId);
				}

			}
			break;
			//LEFT
		case 4:
			if (x <= pieceVector[i][6] && x > pieceVector[i][6] - pieceVector[i][5])
			{
				if (y == pieceVector[i][7])
				{
					shipId = i;
					addHit(shipId);
				}

			}
			break;


		default:
			break;
		}
		i++;
	}

	shipSunk(shipId);
}

void Pieces::addHit(int shipId)
{
	int i = 0;

	while (i <pieceVector[shipId][5])
	{
		if (pieceVector[shipId][i] == 1)
		{
			pieceVector[shipId][i] = 0;
			break;
		}
		i++;
	}
}


void Pieces::placePiece(int piece, int x, int y, int direction)
{
	pieceVector[piece][6] = x;
	pieceVector[piece][7] = y;
	pieceVector[piece][8] = direction;
	pieceVector[piece][9] = 1;
}

int Pieces::checkShips()
{
	int i = 0;

	while (pieceVector[i][9] == 0)
	{
		i++;
		if (i == 5)
		{
			break;
		}
	}

	if (i!=5)
	{
		return -1;
	}
	if(i==5)
	{
		std::cout << "GAME OVER" << std::endl;
		return 1;
	}
}

int Pieces::shipSunk(int ship)
{
	int holder = 0;
	for (int i = 0; i < pieceVector[ship][5]; i++)
	{
		if (pieceVector[ship][i] == 0)
		{
			holder++;
		}
	}

	if (holder == pieceVector[ship][5])
	{
		pieceVector[ship][9] = 0;

		std::cout << "YOU SUNK THE SIZE " << pieceVector[ship][5] << " SHIP!" << std::endl;

		return 1;
	}
	else
	{
		return -1;
	}

}

