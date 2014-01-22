#ifndef CBOARD_H
#define CBOARD_H

#include "Implementation.h"
class Piece;
class Queen;
class King;
class Pawn;
class Rook;
class Bishop;
class Knight;

class ChessBoard{
private:
    std::map <Location, Piece*> board;
    bool whitesTurn;
    Location whiteKing;
    Location blackKing;
    //convert a move from a string to a location struct//
    Location convertMove(std::string move);
    void clearBoard();
    //check if a king is in check//
    bool checkForCheck(Location king, std::map<Location, Piece *> board);
    //check if a certain team based on a king has any valid moves that don't lead to check, if not, then stalemate//
    bool checkforStalemate(Location king, std::map<Location, Piece *> board);
public:
    ChessBoard();
    void resetBoard();
    void submitMove(const char from[], const char to[]);
    ~ChessBoard();
};

#endif