#ifndef PIECE_H
#define PIECE_H

#include "Implementation.h"

class Piece{
protected:
    std::string name;
    bool white;
    
public:
    Piece(bool _white);
    virtual void validMoves(Location loc, std::vector<Location> &possibleMoves, std::map<Location, Piece *> board);
    std::string whatName();
    bool whatColour();
    void printColour();
    virtual ~Piece();
};

#endif