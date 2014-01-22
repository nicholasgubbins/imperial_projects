#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;


#include "Queen.hpp"

Queen::Queen(bool _white): Piece(_white){
    name = "Queen";
}
//see the notes for Bishop's validMoves to understand what is happening here//
void Queen::validMoves(Location loc, vector<Location> &possibleMoves,map<Location, Piece *> board){
    Location possLoc = loc;
    //going N//
    for (possLoc.column = loc.column+1; possLoc.column < 'I'; possLoc.column++){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
            break;
        }
        possibleMoves.push_back(possLoc);
    }
    //going S//
    possLoc = loc;
    for (possLoc.column = loc.column-1; possLoc.column >= 'A'; possLoc.column--){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
            break;
        }
        possibleMoves.push_back(possLoc);
    }
    //going W //
    possLoc = loc;
    for (possLoc.row = loc.row-1; possLoc.row > 0; possLoc.row--){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
            break;
        }
        possibleMoves.push_back(possLoc);
    }
    //going E//
    possLoc = loc;
    for (possLoc.row = loc.row+1; possLoc.row < 9; possLoc.row++){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
            break;
        }
        possibleMoves.push_back(possLoc);
    }
    possLoc = loc;
    possLoc.row++;
    //going NE//
    for (possLoc.column = possLoc.column+1 ; possLoc.column < 'I' && possLoc.row < 9; possLoc.column++){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
            break;
        }
        possibleMoves.push_back(possLoc);
        possLoc.row++;
        
    }
    //going SE//
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
    //going SW//
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
    //going NW//
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