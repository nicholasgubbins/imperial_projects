#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;


#include "Rook.hpp"

Rook::Rook(bool _white): Piece(_white){
    name = "Rook";
}

Rook::~Rook(){}

//see the notes for Bishop's validMoves to understand what's going on here//
void Rook::validMoves(Location loc, vector<Location> &possibleMoves, map<Location, Piece *> board){
    Location possLoc = loc;
    for (possLoc.column = loc.column+1; possLoc.column < 'I'; possLoc.column++){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
            break;
        }
        possibleMoves.push_back(possLoc);
    }
    possLoc = loc;
    for (possLoc.column = loc.column-1; possLoc.column >= 'A'; possLoc.column--){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
            break;
        }
        possibleMoves.push_back(possLoc);
    }
    possLoc = loc;
    for (possLoc.row = loc.row-1; possLoc.row > 0; possLoc.row--){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
            break;
        }
        possibleMoves.push_back(possLoc);
    }
    possLoc = loc;
    for (possLoc.row = loc.row+1; possLoc.row < 9; possLoc.row++){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
            break;
        }
        possibleMoves.push_back(possLoc);
    }
    
}