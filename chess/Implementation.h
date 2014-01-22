#ifndef IMP_H
#define IMP_H

#include<map>
#include<vector>
#include<string>

struct Location{
    char column;
    int row;
    friend bool operator<(const Location &loc1, const Location &loc2);
    friend bool operator==(const Location &loc1, const Location &loc2);

};

#endif