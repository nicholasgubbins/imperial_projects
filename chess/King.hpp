#ifndef KING_H
#define KING_H

#include "Piece.hpp"

class King: public Piece{
public:
    King(bool _white);
    void validMoves(Location loc, std::vector<Location> &possibleMoves, std::map<Location, Piece *> board);
};

#endif