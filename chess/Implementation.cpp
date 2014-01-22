#include<iostream>
using namespace std;
#include "Implementation.h"

bool operator<(const Location &loc1, const Location &loc2){
        if (loc1.column < loc2.column)
            return true;
        else if ((loc1.column == loc2.column) && (loc1.row < loc2.row))
            return true;
        else
            return false;
}

bool operator==(const Location &loc1, const Location &loc2){
    if ((loc1.column == loc2.column) && (loc1.row == loc2.row))
        return true;
    else
        return false;
}
