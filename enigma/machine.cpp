#include <iostream>
#include <fstream>

using namespace std;

#include "errors.h"
#include "enigma.h"

#include "plugboard.hpp"
#include "rotors.hpp"
#include "reflector.hpp"
#include "machine.hpp"

//construct the machine//
Machine::Machine(char **argv, int argc){
    goingleft = true;
    configurationcount = 0;
    num_of_rotors = 0;
    //loop through the array of input parameters//
    for (int i = argc-1; i >0 ; i--){
        char name[50];
        strcpy(name, argv[i]);
        //if it is the in index 1, it is the plugboard, call the constructor with the name of the file//
        if (i == 1){
            plugboard = new Plugboard(name);
        }
        //if it is in index 2, it is the reflector, call the constructor with the name of the file//
        else if (i == 2){
            reflector = new Reflector(name);
        }
        //if it is the final file, it is the config file, add the values to the configuration_array//
        else if (i == argc-1){
            ifstream instream;
            instream.open(name);
            int currentnum;
            while (!instream.fail()){
                instream >> ws >> currentnum;
                for (int w = 0; !instream.fail();w++){
                    configuration_array[w] = (currentnum);
                    configurationcount++;
                    instream >> ws >> currentnum;
                }
            }
        }
        else{
            //if it is the penultimate file, this is the first rotor which rotates with every letter and doesn't point to another.//
            if (i == argc-2){
                rotorlist[num_of_rotors] = new Rotor(name, num_of_rotors);
                num_of_rotors++;
            }
            //else all other files are rotors and the file name is passed to the constructor, along with the current rotor count (it's rotor index), and a pointer to the previous rotor//
            else {
                rotorlist[num_of_rotors] = new Rotor(name, num_of_rotors, rotorlist[num_of_rotors - 1]);
                num_of_rotors++;
            }
        }
        
    }
}

//set up the starting positions of the rotors from the configuration file//
int Machine::checkConfiguration(){
    //check there are as many starting positions as rotors//
    if (configurationcount < num_of_rotors){
        cerr << "No Rotor Starting Position" << endl;
        return NO_ROTOR_STARTING_POSITION;
    }
    int w = 0;
    //going backwards through the rotor list, change the rotation of the rotor to the corresponding configuration. ignore any other extra configuration numbers//
    for (int i = num_of_rotors-1; i >= 0; i--){
        Rotor *r = rotorlist[i];
        r->rotation = configuration_array[w];
        w++;
    }
    return 0;
}

int Machine::runMachine(){
    //strip whitespace and get the first input letter//
    char currentletter;
    cin >> ws;
    cin >> currentletter;
    while (cin){
        if (lettercheck(currentletter) != 0){
            cerr << "Invalid Input Character" << endl;
            return INVALID_INPUT_CHARACTER;}
        
        currentLet = chartoletter(currentletter);
        //convert the letter using each components convertLetter method in the correct order (pluboard, rotors and reflector with goingleft as true, then back through the array of rotors backwards and back to the plugboard //
        plugboard->convertLetter(currentLet);
        for (int i = 0; i < num_of_rotors; i++){
            rotorlist[i]->convertLetter(currentLet, goingleft);
        }
        reflector->convertLetter(currentLet);
        goingleft = false;
        for (int i = num_of_rotors-1; i >=0; i--){
            rotorlist[i]->convertLetter(currentLet, goingleft);
        }
        plugboard->convertLetter(currentLet);
        //reset going left as true for the next letter, convert the Letter type to a char and print the letter. then get the next letter//
        goingleft = true;
        char char_print = lettertochar(currentLet);
        cout << char_print;
        cin >> ws;
        cin >> currentletter;
    }
    return 0;
}

//delete the items on the stack //
void Machine::clear(){
    for (int i = 0; i > num_of_rotors; i++){
        delete rotorlist[i];
    }
    delete plugboard;
    delete reflector;
}
