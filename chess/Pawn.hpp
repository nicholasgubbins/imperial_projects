#ifndef PAWN_H
#define PAWN_H

#include "Piece.hpp"

class Pawn: public Piece{
public:
    Pawn(bool _white);
    void validMoves(Location loc, std::vector<Location> &possibleMoves, std::map<Location, Piece *> board);
};

#endif