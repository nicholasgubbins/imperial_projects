#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;


#include "Knight.hpp"

Knight::Knight(bool _white): Piece(_white){
    name = "Knight";
}

//check all 8 L shaped moves from the current location, making sure that the destination is on the map, and if there is something there, it is of another colour//
void Knight::validMoves(Location loc, vector<Location> &possibleMoves, map<Location, Piece *> board){
    Location possLoc = loc;
    possLoc.row = possLoc.row + 2;
    possLoc.column--;
    if (possLoc.row < 9 && possLoc.column >= 'A'){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
    possLoc.column = possLoc.column +2;
    if (possLoc.row < 9 && possLoc.column < 'I'){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
    possLoc = loc;
    possLoc.row = possLoc.row - 2;
    possLoc.column--;
    if (possLoc.row > 0 && possLoc.column >= 'A'){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
    possLoc.column = possLoc.column +2;
    if (possLoc.row > 0 && possLoc.column < 'I'){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
    possLoc = loc;
    possLoc.column = possLoc.column - 2;
    possLoc.row--;
    if (possLoc.row > 0 && possLoc.column >= 'A'){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
    possLoc.row = possLoc.row +2;
    if (possLoc.row < 9 && possLoc.column >= 'A'){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
    possLoc = loc;
    possLoc.column = possLoc.column + 2;
    possLoc.row--;
    if (possLoc.row > 0 && possLoc.column < 'I'){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
    possLoc.row = possLoc.row +2;
    if (possLoc.row < 9 && possLoc.column < 'I'){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
}