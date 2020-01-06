#ifndef PIECEHEADER_HPP
#define PIECEHEADER_HPP

#include "sharedHeader.hpp"
#include "boardHeader.hpp"

class Pieces
{
public:
	Pieces();
	~Pieces();
	void displayPieces();
	void placePiece(int piece, int x, int y, int direction);
	void setHit(int x, int y);
	void displayShips();
	int checkShips();
	int shipSunk(int ship);
	void addHit(int shipId);


private:
	std::vector<std::vector<int>> pieceVector;
};



#endif // !PIECEHEADER_HPP