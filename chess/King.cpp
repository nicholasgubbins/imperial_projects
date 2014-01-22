#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

#include "King.hpp"

King::King(bool _white): Piece(_white){
    name = "King";
}

//check each adjacent space making sure that the destination is on the map, and if there is something there, it is of another colour//
void King::validMoves(Location loc, vector<Location> &possibleMoves,map<Location, Piece *> board){
    Location possLoc = loc;
    possLoc.row++;
    if (possLoc.row < 9){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
    
    possLoc = loc;
    possLoc.row++;
    possLoc.column++;
    
    if((possLoc.row < 9) && (possLoc.column < 'I')){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
    possLoc = loc;
    possLoc.column++;
    
    if(possLoc.column < 'I'){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
    possLoc = loc;
    possLoc.column++;
    possLoc.row--;
    
    if((possLoc.row > 0) && (possLoc.column < 'I')){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
    possLoc = loc;
    possLoc.row--;
    if(possLoc.row > 0){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
    possLoc = loc;
    possLoc.row--;
    possLoc.column--;
    if((possLoc.row > 0) && (possLoc.column >= 'A')){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
    possLoc = loc;
    possLoc.column--;
    if(possLoc.column >= 'A'){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
    possLoc = loc;
    possLoc.column--;
    possLoc.row++;
    if((possLoc.column >= 'A') && (possLoc.row < 9)){
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
        else{
            possibleMoves.push_back(possLoc);
        }
    }
}