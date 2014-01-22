#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;


#include "Pawn.hpp"
Pawn::Pawn(bool _white): Piece(_white){
    name = "Pawn";
}

void Pawn::validMoves(Location loc, vector<Location> &possibleMoves, map<Location, Piece *> board){
    Location possLoc = loc;
    //if pawn is white//
    if (white){
        //check if it's on the starting position, if so, it can move up to two spaces//
        if (loc.row == 2){
            possLoc.row++;
            //if something is there, nothing can be done//
            if (board[possLoc] != NULL){}
            else {
                //if nothing is there, add it to the list, and check the next space on too//
                possibleMoves.push_back(possLoc);
                possLoc.row++;
                if (board[possLoc] == NULL)
                    possibleMoves.push_back(possLoc);
                
            }
        }
        possLoc = loc;
        //now check other possible pawn locations. they can only move one space on
        if (loc.row != 2){
            possLoc.row++;
            //if the location is null, add it to the list of possible moves//
            if (board[possLoc] == NULL)
                possibleMoves.push_back(possLoc);
        }
        //now check the forward diaganols//
        possLoc = loc;
        possLoc.row++;
        possLoc.column++;
        //if there is something there, and it is a different colour, add it to the list f possible moves//
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
            
        }
        //again check the other side//
        possLoc.column--;
        possLoc.column--;
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() != this->white)
                possibleMoves.push_back(possLoc);
        }
    }
    //if it is a black piece, do the same, but instead of increasing the row, decrease it//
    else{
        if (loc.row == 7){
            possLoc.row--;
            if (board[possLoc] != NULL){}
            else {
                possibleMoves.push_back(possLoc);
                possLoc.row--;
                if (board[possLoc] != NULL){}
                else{
                    possibleMoves.push_back(possLoc);
                }
            }
        }
        possLoc = loc;
        if (loc.row != 7){
            possLoc.row--;
            if (board[possLoc] != NULL){}
            else {
                possibleMoves.push_back(possLoc);
            }
        }
        possLoc = loc;
        possLoc.row--;
        possLoc.column++;
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() == this->white){}
            else {
                possibleMoves.push_back(possLoc);
            }
        }
        possLoc.column--;
        possLoc.column--;
        if (board[possLoc] != NULL){
            if (board[possLoc]->whatColour() == this->white){}
            else {
                possibleMoves.push_back(possLoc);
            }
        }
    }
}