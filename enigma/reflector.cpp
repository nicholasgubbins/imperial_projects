#include <iostream>
#include <fstream>

using namespace std;

#include "enigma.h"
#include "reflector.hpp"

Reflector::Reflector(char file[]){
    cablearraylen = 0;
    ifstream instream;
    instream.open(file);
    int num;
    instream >> ws >> num;
    while (!instream.fail()) {
        //input the numbers into the letter array in the order in which they come from the file//
        for (int i = 0; !instream.fail() ;i++){
            cablearray[i] = num;
            cablearraylen++;
            instream >> ws >> num;
        }
    }
    instream.close();
}

void Reflector::convertLetter(Letter &input){
    //loop through the numbers in the cablearray. if the current letter matches a number in the cablearray, check if it is the first or second member in a pair, and then return either the next or previous number. note that letter is passed by reference.//
    for (int i = 0; i <= cablearraylen ; i++){
        if (cablearray[i] == (Letter)input){
            if (i%2 == 0){
                input = (Letter)cablearray[i+1];
                return;
            }
            else {
                input = (Letter)cablearray[i-1];
                return;
            }
        }
    }
}
