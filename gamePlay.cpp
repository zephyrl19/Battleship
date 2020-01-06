#include "gamePlay.hpp"


gamePlay::gamePlay()
{
	printWelcome();

	player1 = new Player("1");
	player2 = new Player("2");
	option = menu();
}

void gamePlay::printWelcome()
{
	std::cout << "\t\t     WELCOME TO BATTLESHIP!\n\tTHIS GAME WAS CREATED AND CODED BY AUSTIN CROW\n\t\tIT WAS CREATED IN AUGUST 2019!" << std::endl;
	std::cout << "\t\tI HOPE YOU ENJOY YOUR GAME!\n\n\n" << std::endl;

}
gamePlay::~gamePlay()
{
	delete player1;
	delete player2;
}

void gamePlay::playGame() 
{
	if (option == 1)
	{
		std::cout << "YOU HAVE SELECTED SINGLE PLAYER!\nSELECT THE DIFFICULTY YOU WANT!\n" << std::endl;
		std::cout << "1.\tEASY\n2.\tMEDIUM\n3.\tHARD" << std::endl;
		std::cin >> difficulty;
		while (difficulty != 1 && difficulty != 2 && difficulty != 3)
		{
			std::cout << "Please Select Option 1, 2, Or 3" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> difficulty;
		}
		switch (difficulty)
		{
		case 1:
			easyGame();
			break;
		case 2:
			//mediumGame();
			break;
		case 3:
			//hardGame();
			break;
		default:
			break;
		}
	}

};

Player* gamePlay::getPlayer(int num)
{
	if (num == 1)
	{
		return player1;
	}
	else
	{
		return player2;
	}

}

void gamePlay::chooseShot(int* x, int* y)
{
	std::cout << "Select X Coordinate For Shot (0-9)" << std::endl;
	std::cin >> *x;
	while (*x > 9 || *x < 0)
	{
		std::cout << "Please Select A Target Between (0-9)" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> *x;
	}

	std::cout << "Select Y Coordinate For Shot (0-9)" << std::endl;
	std::cin >> *y;
	while (*y > 9 || *y < 0)
	{
		std::cout << "Please Select A Target Between (0-9)" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> *y;
	}

}


int gamePlay::menu()
{

	//Give menu options, return int with selected option. Perform input validation


	int option = 0;

	std::cout << "PLEASE SELECT AN OPTION FROM THE LIST BELOW\n1.\tSTART 1 PLAYER GAME\n2.\tSTART 2 PLAYER GAME\n3.\tEXIT GAME" << std::endl;
	std::cin >> option;

	while (option != 1 && option != 2 && option != 3)
	{
		std::cout << "Please Select Option 1, 2, Or 3" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> option;
	}


	return option;
}

//TEST BED FOR GAMEPLAY MECHANICS

void gamePlay::easyGame()
{

	//set up boards

	std::cout << "Please select 1 to set your own board" << std::endl;
	std::cout << "Please select 2 to auto set your board" << std::endl;
	int selector = 0;
	std::cin >> selector;
	while (selector!= 1 && selector != 2)
	{
		std::cout << "That is not a valid input" << std::endl;
		std::cout << "Please select 1 to set your own board" << std::endl;
		std::cout << "Please select 2 to auto set your board" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> selector;
	}
	switch (selector)
	{
	case 1:
		player1->setBoard();
		break;
	case 2:
		player1->compSet();
	default:
		break;
	}
	
	player2->compSet();




	int holder = 0;

	int x = 0;
	int y = 0;

	while (player1->winCheck(player2) != 1 && player2->winCheck(player1) != 1)
	{


		//player 1 shot
		chooseShot(&x, &y);

		//-1 if miss
		//1 if hit
		//-2 if already chosen that space and a miss
		//2 if already chosen that space and a hit
		holder = player1->getMarkerBoard()->hitCheck(y, x, player2->getPieceBoard());


		player1->getMarkerBoard()->printBoard();
		switch (holder)
		{
			//Shot is a hit!
		case 1:
			player2->getPieces()->setHit(x, y);
			break;
			//Shot has already been selected and is a hit!
		case 2:
			break;
			//Shot is a miss!
		case -1:
			break;
			//SHot has already been selected and is a miss!
		case -2:
			break;

		default:
			break;
		}

		x = rand() % 10;
		y = rand() % 10;
		holder = player2->getMarkerBoard()->hitCheck(y, x, player1->getPieceBoard());
		player2->getMarkerBoard()->printBoard();
		switch (holder)
		{
			//Shot is a hit!
		case 1:
			player1->getPieces()->setHit(x, y);
			break;
			//Shot has already been selected and is a hit!
		case 2:
			break;
			//Shot is a miss!
		case -1:
			break;
			//SHot has already been selected and is a miss!
		case -2:
			break;

		default:
			break;
		}

	}

	




}



