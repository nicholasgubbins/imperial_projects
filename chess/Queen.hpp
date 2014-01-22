#ifndef QUEEN_H
#define QUEEN_H


#include "Piece.hpp"

class Queen: public Piece{
public:
    Queen(bool _white);
    void validMoves(Location loc, std::vector<Location> &possibleMoves, std::map<Location, Piece *> board);
};

#endif