#ifndef PLAYER_HPP
#define PLAYER_HPP


#include "sharedHeader.hpp"
#include "boardHeader.hpp"


class Player
{
public:
	Player(std::string num);
	~Player();
	Board* getPieceBoard();
	Board* getMarkerBoard();
	Board* createBoard(std::string name);
	Pieces* getPieces();
	void displayShipsRemaining(std::vector<int> ships, int shipsLeft);
	void setBoard();
	void compSet();
	bool winCheck(Player* opponent);


private:
	Pieces * playerPieces;
	Board * pieceBoard;
	Board * markerBoard;
	int playerNum;
};




#endif // !PLAYER_HPP


