#include <iostream>

using namespace std;

#include "enigma.h"


/*-------CONVERT CHARACTER TO LETTER------- */
//convert a char to an enumerated letter type by looping through an alphabet array and returning the matching value. This will correspond with the enumeration of the alphabet in enigma.h//
Letter chartoletter(char let){
    char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for (int n=0; n<26; n++){
        if (let == alphabet[n]){
            return (Letter) n;
        }
    }
    return (Letter)0;
}


/*-------CONVERT LETTER TO CHARACTER-------- */
char lettertochar(Letter let){
    char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    return alphabet[let];
}

/*-------CHECK AN INPUT LETTER-------- */
int lettercheck(char let){
    char uppercasealpha[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for (int n=0; n<26; n++){
        if (let == uppercasealpha[n]){
            return 0;
        }
    }
    return 1;
}

