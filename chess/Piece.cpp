#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

#include "Piece.hpp"

//the constructor for piece will set the white value to the paramater _white and will set the name to piece//
Piece::Piece(bool _white){
        white = _white;
        name = "piece";
}

Piece::~Piece(){}

//the validMoves doesn't do anything for the superclass and is virtual//
void Piece::validMoves(Location loc, vector<Location> &possibleMoves, map<Location, Piece *> board){};

//simply returns the name which is private//
string Piece::whatName(){
    return name;
}
//returns the colour which is private//
bool Piece::whatColour(){
        return white;
}
//prints the pieces colour //
void Piece::printColour(){
    if (white){
        cout << "White";
    }
    else
        cout << "Black";
}