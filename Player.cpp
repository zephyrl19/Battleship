#include "Player.hpp"



Player::Player(std::string num)
{
	std::string boardname;
	boardname = "Player " + num;
	pieceBoard = createBoard(boardname + " PIECES");
	markerBoard = createBoard(boardname + " MARKERS");
	playerPieces = new Pieces;
}


Player::~Player()
{
	delete pieceBoard;
	delete markerBoard;

}
Pieces* Player::getPieces()
{
	return playerPieces;
}
Board* Player::getPieceBoard() {
	return pieceBoard;
}

Board* Player::getMarkerBoard() {
	return markerBoard;
}

Board* Player::createBoard(std::string name) {

	 return new Board(name);
}

void Player::displayShipsRemaining(std::vector<int> ships, int shipsLeft)
{
	for (int i = 0; i < shipsLeft; i++)
	{
		std::cout << i+1 << ". Size = " << ships[i] << std::endl;
	}
}
void Player::setBoard()
{
	//Prompt user for input and place piece
	int holder = 0;
	int ship = 99;
	std::vector<int> shipSize;
	int shipsLeft = 0;
	int x = 99;
	int y = 99;
	int direction = 99;
	int directionArray[4] = { 0, 0, 0, 0 };


	shipSize.push_back(2);
	shipSize.push_back(3);
	shipSize.push_back(3);
	shipSize.push_back(4);
	shipSize.push_back(5);

	shipsLeft = shipSize.size();

	while (shipsLeft > 0)
	{



		//displayShipsRemaining(shipSize, shipsLeft);
		std::cout << "PICK WHERE TO PLACE THE NEXT SHIP!" << std::endl;
		std::cout << "SHIP LENGTH: " << shipSize[shipSize.size() - 1] << std::endl;
		ship = shipSize.size() - 1;
		while ((ship > shipsLeft) || (ship < 0))
		{
			std::cout << "PICK A VALID OPTION!" << std::endl;
			displayShipsRemaining(shipSize, shipsLeft);
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> ship;
		}
		
		std::cout << "ENTER THE X,Y COORDINATES OF THE HEAD OF YOUR SHIP!\nIF THAT IS A VALID POSITION, THEN SELECT THE DIRECTION YOU WANT\nTHE REST OF THE SHIP TO BE PLACED IN\nTHE PROGRAM WILL NOT LET YOU SELECT A BAD DIRECTION!" << std::endl;
		std::cout << "X COORD: ";
		std::cin >> x;
		if ((x > 9) || (x < 0))
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "ENTER A VALUE 0-9" << std::endl;
			std::cout << "X Coord: ";
			std::cin >> x;

		}

		std::cout << "Y COORD: ";
		std::cin >> y;
		if ((y > 9) || (y < 0))
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "ENTER A VALUE 0-9" << std::endl;
			std::cout << "Y Coord: ";
			std::cin >> y;

		}


		holder = pieceBoard->willShipFit(x, y, shipSize[ship], directionArray);


		if (holder == 1)
		{
			std::cout << "it fits!" << std::endl;
		}
		if (holder == -1)
		{
			std::cout << "it doesnt fits!" << std::endl;
			continue;
		}

		if (directionArray[0] == 1)
		{
			std::cout << "YOU MAY PLAY IT NORTH (1)" << std::endl;
		}
		if (directionArray[1] == 1)
		{
			std::cout << "YOU MAY PLAY IT EAST (2)" << std::endl;
		}
		if (directionArray[2] == 1)
		{
			std::cout << "YOU MAY PLAY IT SOUTH (3)" << std::endl;
		}
		if (directionArray[3] == 1)
		{
			std::cout << "YOU MAY PLAY IT WEST (4)" << std::endl;
		}


		std::cout << "SELECT THE DIRECTION YOU WANT TO PLACE IT IN!" << std::endl;
		std::cout << "DIRECTION: ";
		std::cin >> direction;
		while (directionArray[direction - 1] != 1)
		{
			std::cout << "THAT IS NOT A VALID DIRECTION" << std::endl;
			std::cout << "Direction: ";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> direction;
		}


		pieceBoard->placeShip(x, y, direction, shipSize[ship]);
		playerPieces->placePiece(ship, x, y, direction);
		ship--;
		shipSize.pop_back();
		shipsLeft = shipSize.size();
	}
}

void Player::compSet()
{
	int holder = 0;
	int ship = 99;
	std::vector<int> shipSize;
	int shipsLeft = 0;
	int x = 99;
	int y = 99;
	int direction = 99;
	int directionArray[4] = { 0, 0, 0, 0 };
	std::vector<int> possibleDirections;


	shipSize.push_back(2);
	shipSize.push_back(3);
	shipSize.push_back(3);
	shipSize.push_back(4);
	shipSize.push_back(5);

	shipsLeft = shipSize.size();
	int j = 0;
	while (shipsLeft !=0)
	{
		
		x = rand() % 10;
		y = rand() % 10;
		holder = pieceBoard->willShipFit(x, y, shipSize[shipSize.size()-1], directionArray);
		for (int i = 0; i < 4; i++)
		{
			if (directionArray[i] == 1)
			{
				possibleDirections.push_back(i+1);
			}
		}
		if (holder == 1)
		{
			int helper = 0;
			helper = (rand() % (possibleDirections.size()));
			pieceBoard->placeShip(x, y, possibleDirections[helper], shipSize.back());
			playerPieces->placePiece(j, x, y, possibleDirections[helper]);
			possibleDirections.clear();
			shipSize.pop_back();
			shipsLeft = shipSize.size();
			j++;
		}



		
	}
	pieceBoard->printBoard();

}



bool Player::winCheck(Player* opponent)
{
	if (opponent->getPieces()->checkShips() == -1)
	{
		return false;
	}
	else
	{
		std::cout << "Player " << (this->playerNum)+1 << " Is The Winner!" << std::endl;
		return true;
	}
}
