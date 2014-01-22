#include <iostream>
#include <fstream>

#include "errors.h"
#include "enigma.h"

using namespace std;

/*-------CHECK OF PLUGBOARD FILES-------- */
int checkfile_pb(char filename[]){
    int file_ok = 0;
    ifstream instream;
    int current_num;
    int lst_of_nums[ALPHA_LENGTH];
    //open file, immediately check if it has failed, if so the file name is not available and return the appropriate error code ERROR_OPENING_CONFIGURATION_FILE //
    instream.open(filename);
    if (instream.fail()){
        cerr << "Error Opening Configuration File" << endl;
        return ERROR_OPENING_CONFIGURATION_FILE;}
    int i = 0;
    instream >> ws;
    instream >> current_num;
    while (!instream.fail()){
        for (i = 0;!instream.fail();i++){
            //loop through the list of numbers already passed through the loop, and if the current number has already occurred, return IMPOSSIBLE_PLUGBOARD_CONFIGURATION //
            for(int w = 0; w < i; w++){
                
                if (current_num == lst_of_nums[w]) {
                    instream.close();
                    
                    cerr << "Impossible Plugboard Configuration" << endl;
                    return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
                }
            }
            //if the number is original, add it to list of numbers//
            lst_of_nums[i] = current_num;
            
            //check that the current_num is within the correct range, else return INVALID_INDEX //
            if (current_num > 25 || current_num < 0){
                instream.close();
                cerr << "Invalid Index" << endl;
                return INVALID_INDEX;
            }
            //remove any unwanted whitespace and get the next digit //
            instream >> ws;
            instream >> current_num;
        }
    }
    
    //check that the end of the file has prompted the fail, else, there is an input error and return NON_NUMERIC_CHARACTER//
    if (!instream.eof()){
        cerr << "Non Numeric Character" << endl;
        return NON_NUMERIC_CHARACTER;
    }
    
    //check that the overall number of inputs are even, else return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS
    if (i%2 != 0){
        instream.close();
        cerr << "Incorrect Number of Plugboard Parameters" << endl;
        return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
    }
    
    //close the file and return 0, the file is appropriate //
    instream.close();
    return file_ok;
   
}


/*-------CHECK OF REFLECTOR FILES-------- */
int checkfile_rf(char filename[]){
    int file_ok = 0;
    ifstream instream;
    int current_num = 3;
    int lst_of_nums[ALPHA_LENGTH];
    instream.open(filename);
    if (instream.fail()){
        cerr << "Error opening configuration file" << endl;
        return ERROR_OPENING_CONFIGURATION_FILE;}
    int i = 0;
    instream >> ws;
    instream >> current_num;
    while (!instream.fail()) {
        for (i = 0;!instream.fail(); i++){
            for(int w = 0; w < i; w++){
                //check in the lst_of_nums to see if the current number has already been added, else return INVALID_REFLECTOR_MAPPING//
                if (current_num == lst_of_nums[w]) {
                    instream.close();
                    cerr << "Invalid Reflector Mapping" << endl;
                    return INVALID_REFLECTOR_MAPPING;
                }
            }
            //check the current number is in the correct range//
            if (current_num > 26 || current_num < 0){
                instream.close();
                cerr << "Invalid Index" << endl;
                return INVALID_INDEX;
            }
            lst_of_nums[i] = current_num;
            instream >> ws;
            instream >> current_num;
        }
    }
    //if the stream has failed and it is not because of the end of the file, there is a non int in the file //
    if (!instream.eof()){
        cerr << "Non Numeric Character" << endl;
        return NON_NUMERIC_CHARACTER;
    }
    //there must be 26 entries into the mapping of a reflector file //
    if (i != 26){
        instream.close();
        cerr << "Incorrect Number of Reflector Parameters" << endl;
        return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
    }
    
    instream.close();
    return file_ok;
}



/*-------CHECK OF ROTOR FILES-------- */
//follows the same checks as the reflector and plugboard checks//
int checkfile_rot(char filename[]){
    int file_ok = 0;
    ifstream instream;
    int current_num;
    int lst_of_nums[ALPHA_LENGTH];
    instream.open(filename);
    if (instream.fail()){
        cerr << "Error opening configuration file" << endl;
        return ERROR_OPENING_CONFIGURATION_FILE;}
    int i = 0;
    instream >> ws;
    instream >> current_num;
    while (!instream.fail()) {
        for (i = 0;!instream.fail(); i++){
            if (i <26){
                for(int w = 0; w < i; w++){
                    if (current_num == lst_of_nums[w]) {
                        instream.close();
                        cerr << "Invalid Rotor Mapping" << endl;
                        return INVALID_ROTOR_MAPPING;
                    }
                }
                if (current_num > 26 || current_num < 0){
                    instream.close();
                    cerr << "Invalid Index" << endl;
                    return INVALID_INDEX;
                }
                lst_of_nums[i] = current_num;
                instream >> ws;
                instream >> current_num;
            }
            else {
                instream >> ws;
                instream >> current_num;
            }
        }
    }
    if (!instream.eof()){
        instream.close();
        cerr << "Non Numeric Character" << endl;
        return NON_NUMERIC_CHARACTER;
    }
    if (i < 26){
        instream.close();
        cerr << "Invalid Rotor Mapping" << endl;
        return INVALID_ROTOR_MAPPING;
    }
    instream.close();
    return file_ok;
}


/*-------CHECK OF CONFIGURATION FILES-------- */
//we need to check that there aren't any non numeric character's in configuaration file, so loop through and check that the instream fail is due to the EOF. also check that input numbers are between 0 and 25 //
int checkfile_pos(char filename[]){
    int file_ok = 0;
    ifstream instream;
    int current_num;
    instream.open(filename);
    if (instream.fail()){
        cerr << "Error Opening Configuration File" << endl;
        return ERROR_OPENING_CONFIGURATION_FILE;}
    int i = 0;
    instream >> ws;
    instream >> current_num;
    while (!instream.fail()){
        for (i = 0; !instream.fail() ;i++){
            if (current_num > 26 || current_num < 0){
                instream.close();
                cerr << "Invalid Index" << endl;
                return INVALID_INDEX;}
            instream >> ws;
            instream >> current_num;
        }
    }
    if (!instream.eof()){
        instream.close();
        cerr << "Non Numeric Character" << endl;
        return NON_NUMERIC_CHARACTER;
    }
    instream.close();
    return file_ok;
}

