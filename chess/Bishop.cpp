#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

#include "Piece.hpp"
#include "Bishop.hpp"

Bishop::Bishop(bool _white): Piece(_white){
    name = "Bishop";
}

void Bishop::validMoves(const Location loc, vector<Location> &possibleMoves, map<Location, Piece *> board){
    Location possLoc = loc;
    possLoc.row++;
    //first going NE, loop diagonally up from the current position until you hit another piece or the edge of the board//
    for (possLoc.column = possLoc.column+1 ; possLoc.column < 'I' && possLoc.row < 9; possLoc.column++){
        if (board[possLoc] != NULL){
            //if there is a piece and it is a different colour, add it to the list of possible moves//
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
            break;
        }
        possibleMoves.push_back(possLoc);
        possLoc.row++;
        
    }
    //now going SE//
    possLoc = loc;
    possLoc.row--;
    for (possLoc.column = possLoc.column+1; possLoc.column < 'I' && possLoc.row > 0; possLoc.column++){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
            break;
        }
        possibleMoves.push_back(possLoc);
        possLoc.row--;
    }
    //now going SW//
    possLoc = loc;
    possLoc.row--;
    for (possLoc.column = possLoc.column -1; possLoc.column >= 'A' && possLoc.row > 0; possLoc.column--){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
            break;
        }
        possibleMoves.push_back(possLoc);
        possLoc.row--;
    }
    //now going NW//
    possLoc = loc;
    possLoc.row++;
    for (possLoc.column = possLoc.column -1; possLoc.column >= 'A' && possLoc.row < 9; possLoc.column--){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
            break;
        }
        possibleMoves.push_back(possLoc);
        possLoc.row++;
    }
}