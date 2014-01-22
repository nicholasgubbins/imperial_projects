/* this is the main file in which the files from the command line are individually passed to the appropriate checkfiles, and then passed into the Machine superclass constructor. then, the machine is run, and finally the machine cleared of anything built on the heap. */


#include <iostream>

using namespace std;

#include "errors.h"
#include "enigma.h"
#include "machine.hpp"

class Machine;

int main(int argc, char **argv){
    int check = 0;
    if (argc < 3){
        cerr << "Insufficient Number of Parameters" << endl;
        return INSUFFICIENT_NUMBER_OF_PARAMETERS;
    }
    //loop through the files from the command line backwards, if it is in index 1, it is a plugboard, if it is 2, it is a reflector, if it is the last file, it is a configuration file, else it is a rotor. pass to the appropriate checkfile function. if check ends up being greater than it's initial zero, there is an error. //
    for (int i = 1; i <argc; i++){
    char name[40];
    strcpy(name, argv[i]);
    if (i == 1){
        check = checkfile_pb(name);}
    else if (i == 2){
        check = checkfile_rf(name);}
    else if (i == argc-1){
        check = checkfile_pos(name);}
    else{
        check = checkfile_rot(name);}
    if (check > 0){
        return check;}
    }
    //initiate the machine//
    Machine enigma = Machine(argv, argc);
    if (enigma.checkConfiguration() > 0){
        return NO_ROTOR_STARTING_POSITION;
    }
    //run the machine and store any potential error codes in check again.
    check = enigma.runMachine();
    
    if (check != 0){
        return INVALID_INPUT_CHARACTER;
    }
    
    enigma.clear();
    
    return check;
}
