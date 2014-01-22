#include<iostream>
#include "ChessBoard.hpp"
#include "Piece.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "Implementation.h"
#include<map>
#include<vector>
#include<string>

using namespace std;

//construct all locations of the map A1 - H8 //
ChessBoard::ChessBoard(){
    whitesTurn = false;
    Location loc;
    for (char ch = 'A'; ch < 'I'; ch++){
        for (int i = 1; i < 9; i ++){
            loc.column = ch;
            loc.row = i;
            board[loc] = NULL;}
    }
    resetBoard();
}

//go through every place on the map and if there is piece, delete the piece and set the value to null//
void ChessBoard::clearBoard(){
    Location loc;
    for (loc.row = 1; loc.row < 9; loc.row++){
        for (loc.column = 'A'; loc.column < 'I'; loc.column++){
            if (board[loc] != NULL){
                delete board[loc];
                board[loc] = NULL;}
        }
    }
}

//initalise the board with the standard chess set up//
void ChessBoard::resetBoard(){
    clearBoard();
    whitesTurn = false;
    cout << "A new chess game is started!" << endl;
    bool white = true;
    Location loc;
    loc.row = 1;
    for (char ch = 'A'; ch < 'I'; ch++){
        loc.column = ch;
        switch (ch){
            case 'A':
            case 'H':
                board[loc] = new Rook(white);
                break;
            case 'B':
            case 'G':
                board[loc] = new Knight(white);
                break;
            case 'C':
            case 'F':
                board[loc] = new Bishop(white);
                break;
            case 'D':
                board[loc] = new Queen(white);
                break;
            case 'E':
                board[loc] = new King(white);
                whiteKing = loc;
                break;
        }
    }
    loc.row = 2;
    for (char ch = 'A'; ch < 'I'; ch++){
        loc.column = ch;
        board[loc] = new Pawn(white);
    }
    //now set white to false to make the black pieces//
    white = false;
    
    loc.row = 7;
    for (char ch = 'A'; ch < 'I'; ch++){
        loc.column = ch;
        board[loc] = new Pawn(white);
    }
    
    loc.row = 8;
    for (char ch = 'A'; ch < 'I'; ch++){
        loc.column = ch;
        switch (ch){
            case 'A':
            case 'H':
                board[loc] = new Rook(white);
                break;
            case 'B':
            case 'G':
                board[loc] = new Knight(white);
                break;
            case 'C':
            case 'F':
                board[loc] = new Bishop(white);
                break;
            case 'D':
                board[loc] = new Queen(white);
                break;
            case 'E':
                board[loc] = new King(white);
                blackKing = loc;
                break;
        }
    }
}

//convert a string into a location by turning the 0 index into a letter and the first index into an int//
Location ChessBoard::convertMove(string move){
    Location loc;
    loc.column = move[0];
    loc.row = static_cast<int>(move[1]) - 48;
    return loc;
}


//check every piece of your colour's possible valid moves, and if that resulting move doesn't lead to check, then you are not in stalemate//
bool ChessBoard::checkforStalemate(Location king, map<Location, Piece *> board){
    Location loc;
    Piece *previousFrom;
    Piece *previousTo;
    Location thisKing = king;
    loc.row = 1;
    loc.column = 'A';
    //for some reason, if i tried to look at the king's possible moves in the body of this function, it gave me a seg fault, so as such I check the king's possible moves first with a sepearate vector king test//
    vector<Location> kingtest;
    //set kingtest to all of the king's possible moves, then loop through it, moving the king to those places, and checking whether that results in check, if not, there is a possible move and return false//
    board[thisKing]->validMoves(thisKing, kingtest, board);
    for (int i=0; i < kingtest.size(); i++){
        previousFrom = board[thisKing];
        Location to = kingtest[i];
        previousTo = board[to];
        board[to] = board[thisKing];
        board[thisKing] = NULL;
        thisKing = to;
        bool kingincheck = checkForCheck(thisKing, board);
        if (!kingincheck)
            return false;
        else{
            thisKing = king;
            board[to] = previousTo;
            board[thisKing] = previousFrom;
        }
    }
    //reset the variables to try the rest of the piece//
    previousFrom = NULL;
    previousTo = NULL;
    thisKing = king;
    
    //loop through every single location on the board//
    for (loc.row = 1; loc.row < 9; loc.row++){
        for (loc.column = 'A'; loc.column < 'I'; loc.column++){
            vector<Location> checkallmoves;
            //find the location where the pointer is not NULL i.e there is a piece there, and it is the same colour as the king we are checking, also, we will deal with the king's possible moves seperately//
            if (board[loc] !=NULL){
                if ((board[loc]->whatColour() == board[thisKing]->whatColour()) && !(loc == thisKing)){
                    //set up a safety pointer to the original piece we are testing for moves//
                    previousFrom = board[loc];
                    // find all of this pieces possible moves//
                    board[loc]->validMoves(loc, checkallmoves, board);
                    //loop through all the possible moves//
                    for (int i = 0; i < checkallmoves.size(); i++){
                        Location to = checkallmoves[i];
                        previousTo = board[to];
                        //if the possible move is valid, check if the result will put you in check//
                        board[to] = board[loc];
                        board[loc] = NULL;
                        //if there is a move that doesn't result in your being in check, you are not in stalemate//
                        bool causedcheck = checkForCheck(thisKing, board);
                        if (!causedcheck){
                            return false;
                        }
                        else{
                            //otherwise, reset the board to how it was before this move, and move onto the next possible move
                            board[to] = previousTo;
                            board[loc] = previousFrom;
                            previousTo = NULL;
                            previousFrom = NULL;
                        }
                    }
                }
            }
        }
    }
    //we've been through every piece of the same colour, and test all of their moves, and there isn't one that is valid, so return true, we are in stalemate //
    return true;
}

//check if a king is in check//
bool ChessBoard::checkForCheck(Location king, map<Location, Piece *> board) {
    bool kingsColour = board[king]->whatColour();
        Location loc;
        //loop through all the pieces on the board//
        for (loc.row = 1; loc.row < 9; loc.row++){
            for (loc.column = 'A'; loc.column < 'I' ; loc.column++){
                //find a square that contains a piece of the opposite colour
                if (board[loc] != NULL){
                    vector<Location> possibleMoves;
                    if (board[loc]->whatColour() != kingsColour){
                    //find the piece's possible moves, and if the location of the king is in the list, then return true for check//
                        board[loc]->validMoves(loc, possibleMoves, board);
                        for (int i = 0; i < possibleMoves.size(); i++){
                            if (king == possibleMoves.at(i))
                                return true;
                        }
                    }
                }
            }
        }
    //if there was no piece who had the kings location as a valid move, return false, we are not in check//
    return false;
}

//the main submit function//
void ChessBoard::submitMove(const char from[], const char to[]){
    whitesTurn = (whitesTurn == true ? false : true);
    Location locFrom = convertMove(from);
    Location locTo = convertMove(to);
    vector<Location> possibleMoves;

    //check for checkmate and stalemate on both sides //
    bool whiteInCheck = checkForCheck(whiteKing, board);
    bool blackInCheck = checkForCheck(blackKing, board);
    
    bool blackStalemate = checkforStalemate(blackKing, board);
    bool whiteStalemate = checkforStalemate(whiteKing, board);
    
    if (whiteInCheck && whiteStalemate){
        cout << "White is in checkmate" << endl;
        return;
    }
    else if (blackInCheck && blackStalemate){
        cout << "Black is in checkmate" << endl;
        return;
    }
    if (whiteStalemate){
        cout << "White is in stalemate!" << endl;
        return;
    }
    if (blackStalemate){
        cout << "Black is in stalemate!" << endl;
        return;
    }
    
    //check that to and from are located on the board//
    if ((locFrom.column < 'A') || (locFrom.column > 'H') || (locFrom.row > 8)||(locFrom.row < 1)){
        cout << "Sorry, you have entered an invalid start position" << endl;
        whitesTurn = (whitesTurn == true ? false : true);
        return;}
    if ((locTo.column < 'A') || (locTo.column > 'H') || (locTo.row > 8)||(locTo.row < 1)){
        cout << "Sorry, you have entered an invalid end position" << endl;
        whitesTurn = (whitesTurn == true ? false : true);
        return;}
    
    //check that there is actually a piece at the desired starting square//
    if (board[locFrom] == NULL){
        cout << "There is no piece at poistion " << from << "!" << endl;
        whitesTurn = (whitesTurn == true ? false : true);
        return;
    }
    //check that the colour of the selected piece corresponds to the person who's turn it is//
    if (board[locFrom]->whatColour() != whitesTurn){
        cout << "It is not ";
        board[locFrom]->printColour();
        cout << "'s turn to move!" <<endl;
        whitesTurn = (whitesTurn == true ? false : true);
        return;
    }

    //using the vector possibleMoves, pass it through the pieces validMoves function to return a list of all possible moves that piece can make//
    board[locFrom]->validMoves(locFrom, possibleMoves, board);
    //check that the move that we want to make is in the list of possible moves for the piece by looping through all possible moves and setting validMove as true if they match//
    bool validMove = false;
    for (int i = 0; i < possibleMoves.size(); i++){
        if (locTo == possibleMoves.at(i)){
            validMove = true;
            break;
        }
    }
    // if the desired destination is not in the piece's list of possible destiations, it is not a valid move//
    if (validMove == false){
        board[locFrom]->printColour();
        cout << "'s " << board[locFrom]->whatName() << " cannot move to " << to << "!" << endl;
        whitesTurn = (whitesTurn == true ? false : true);
        return;
    }
    //set up new pointers to the pieces so that if the move leads to check and is invalid, we still have pointers to the original layout and can recreate it//
    Piece *previousFrom = board[locFrom];
    Piece *previousTo = board[locTo];
    
    //if the destinaation is not null, move the from piece to the to location, thus removing the previous piece
    if (board[locTo] != NULL){
        board[locTo] = board[locFrom];
        board[locFrom] = NULL;
        //if the piece moved was the king, update its location marker//
        blackKing = (!whitesTurn && (board[locTo]->whatName() == "King")) ? locTo : blackKing;
        whiteKing = (whitesTurn && (board[locTo]->whatName() == "King")) ? locTo : whiteKing;
    }

    //if there was no piece at the destination, move the piece//
    else{
        board[locTo] = board[locFrom];
        board[locFrom] = NULL;
        //again check to see if the king's location has changed //
        blackKing = (!whitesTurn && (board[locTo]->whatName() == "King")) ? locTo : blackKing;
        whiteKing = (whitesTurn && (board[locTo]->whatName() == "King")) ? locTo : whiteKing;
    }
    //recheck for check//
    whiteInCheck = checkForCheck(whiteKing, board);
    blackInCheck = checkForCheck(blackKing, board);
    //if the player who has just moved moves themselves into check, flag the error and reset the board to how it was before the move//
    if (whiteInCheck && whitesTurn){
        board[locFrom]->printColour();
        cout << "'s " << board[locFrom]->whatName() << " cannot move to " << to << "!" << endl;
        board[locFrom] = previousFrom;
        board[locTo] = previousTo;
        whitesTurn = (whitesTurn == true ? false : true);
        return;
    }
    else if (blackInCheck && !whitesTurn){
        board[locFrom]->printColour();
        cout << "'s " << board[locFrom]->whatName() << " cannot move to " << to << "!" << endl;
        board[locFrom] = previousFrom;
        board[locTo] = previousTo;
        whitesTurn = (whitesTurn == true ? false : true);
        return;
    }
    
    //we now know that it is a valid move, and as such the move should take place, we can also delete the piece that was taken//
    if (previousTo == NULL){
        previousFrom->printColour();
        cout << "'s " << previousFrom->whatName() << " moves from " << locFrom.column << locFrom.row << " to " << locTo.column << locTo.row << endl;
    }
    if (previousTo != NULL){
        previousFrom->printColour();
        cout << "'s " << previousFrom->whatName() << " moves from " << locFrom.column << locFrom.row << " to " << locTo.column << locTo.row << " taking ";
        previousTo->printColour();
        cout << "'s " << previousTo->whatName() << endl;
        delete previousTo;
    }
    
    //check for Stalemate//
    blackStalemate = checkforStalemate(blackKing, board);
    whiteStalemate = checkforStalemate(whiteKing, board);
    //if the either player is in check and there are no possible moves that they can play, they are in checkmate//
    if (blackInCheck && blackStalemate){
        cout << "Black is in checkmate" << endl;
        return;
    }
    else if(whiteInCheck && whiteStalemate){
        cout << "White is in checkmate" << endl;
        return;
    }
    //else if they are only in check, delete the piece that has been taken and end the turn//
    else if (whiteInCheck){
        cout << "White is in check" << endl;
        return;
    }
    else if (blackInCheck){
        cout << "Black is in check" << endl;
        return;
    }
    //else if the opposite player is not in check but has no more possible valid moves, they are in stalemate //
    else if (blackStalemate){
        cout << "Black is in stalemate!" << endl;
        return;
    }
    else if(whiteStalemate){
        cout << "White is in stalemate!" << endl;
        return;
    }
}

ChessBoard::~ChessBoard(){
    clearBoard();
}
