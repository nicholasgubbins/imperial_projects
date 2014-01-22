#include <iostream>
#include <fstream>


using namespace std;

#include "enigma.h"
#include "rotors.hpp"

//the constructor for all rotors other than the first which take in the filename, it's rotor number as well as a pointer to the previous rotor which will be used for the notch rotations//
Rotor::Rotor(char file[], int _rotornum, Rotor *r){
    rotation = 0;
    rotornum = _rotornum;
    next_to_rotate = true;
    last = r;
    //first initialise the notch_location array to having all false values //
    for (int i = 0; i <26; i++){
        notch_location[i] = 0;
    }
    //now we want to extract the mapping of cables into rotor_map by looping through all the values in the rotor file//
    ifstream instream;
    instream.open(file);
    int num;
    instream >> ws >> num;
    while (!instream.fail()){
        for (int i = 0; !instream.fail() ; i++){
            //for the first 26 numbers, add them to the rotor map array//
            if (i < 26){
                rotor_map[i] = num;
                instream >> ws >> num;
            }
            //for the final numbers in the file, we need to assign these to the locations of notches on the notch_location array.//
            if (i > 25){
                notch_location[num%26] = 1;
                instream >> ws >> num;
            }
        }
    }
    instream.close();
}
//the constructor for the first rotor which doesn't have a pointer to a previous rotor//
Rotor::Rotor(char file[], int _rotornum){
    rotation = 0;
    rotornum = _rotornum;
    next_to_rotate = true;
    for (int i = 0; i <26; i++){
        notch_location[i] = 0;
    }
    ifstream instream;
    instream.open(file);
    int num;
    instream >> ws >> num;
    while (!instream.fail()){
        for (int i = 0;!instream.fail(); i++){
            if (i < 26){
                rotor_map[i] = num;
                instream >> ws >> num;
            }
            if (i > 25){
                notch_location[num%26] = 1;
                instream >> ws >> num;
            }
        }
    }
    instream.close();
}

void Rotor::rotate(){
    rotation++;
    //if a notch is reached, this boolean 'next_to_rotate' will be true thus allowing the next rotor to rotate. once it has rotated from the notch, the boolean is set to false to stop it rotating more than once from the same notch location//
    next_to_rotate = true;
    //once there has been a full revolution, the rotation restarts itself//
    if (rotation > 25){
        rotation = 0;
    }
}

//check whether or not the previous rotor has reached a notch location based on it's rotation and array of notch locations. if it's rotation as an index of the notch_location array = 1, and next_to_rotate is set true, rotate, then set next_to_rotate to false so that it doesn't rotate again when the next letter comes around//
void Rotor::rotation_check(){
    if (last->notch_location[last->rotation] == 1 && last->next_to_rotate){
        last->next_to_rotate = false;
        this->rotate();
    }
}

void Rotor::convertLetter(Letter &input, bool goingleft){
    //if the first rotor and the current direction is left, rotate//
    if ((rotornum == 0) && goingleft){
        this->rotate();
    }
    //if not the first rotor and goingleft, check that the previous rotor has his a notch//
    if ((rotornum > 0) && goingleft){
        this->rotation_check();
    }
    if (goingleft){
        //for going left, check the find the index in the cable array with the rotation factored in//
        for (int i = 0; i <26 ; i++){
            if (i == ((input+rotation)%26)){
                //return the sum of the original letter plus the difference between the value of the location and the index. also increasing the value by 26 and modulising 26 to avoid any negative integers//
                input = (Letter)((26 +(input + (rotor_map[i]-i)))%26);
                return;
            }
        }
    }
    
    else{
        //if going left, find the value in the cable array with the rotation factored in//
        for (int i = 0; i<26 ;i++){
            if (rotor_map[i] == ((input+rotation)%26)){
                //return the sum of input with the difference between the index and the value of the location//
                input = (Letter)((26+ (input + (i - rotor_map[i])))%26);
                return;
            }
        }
    }
}

