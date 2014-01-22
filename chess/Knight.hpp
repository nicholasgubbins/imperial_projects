#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.hpp"

class Knight: public Piece{
public:
    Knight(bool _white);
    void validMoves(Location loc, std::vector<Location> &possibleMoves, std::map<Location, Piece *> board);
};

#endif