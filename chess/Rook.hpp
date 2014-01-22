
#ifndef ROOK_H
#define ROOK_H

#include "Piece.hpp"


class Rook: public Piece{
public:
    Rook(bool _white);
    virtual void validMoves(Location loc, std::vector<Location> &possibleMoves, std::map<Location, Piece *> board);
    virtual ~Rook();
};

#endif