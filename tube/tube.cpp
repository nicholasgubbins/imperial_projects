#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <string>
//#include <string.h>


using namespace std;

#include "tube.h"

const int MAX = 50;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* internal helper function which allocates a dynamic 2D array */
char **allocate_2D_array(int rows, int columns) {
  char **m = new char *[rows];
  assert(m);
  for (int r=0; r<rows; r++) {
    m[r] = new char[columns];
    assert(m[r]);
  }
  return m;
}

/* internal helper function which deallocates a dynamic 2D array */
void deallocate_2D_array(char **m, int rows) {
  for (int r=0; r<rows; r++)
    delete [] m[r];
  delete [] m;
}

/* internal helper function which gets the dimensions of a map */
bool get_map_dimensions(const char *filename, int &height, int &width) {
  char line[512];
  
  ifstream input(filename);

  height = width = 0;

  input.getline(line,512);  
  while (input) {
    if ( (int) strlen(line) > width)
      width = strlen(line);
    height++;
    input.getline(line,512);  
  }

  if (height > 0)
    return true;
  return false;
}

/* pre-supplied function to load a tube map from a file*/
char **load_map(const char *filename, int &height, int &width) {

  bool success = get_map_dimensions(filename, height, width);
  
  if (!success)
    return NULL;

  char **m = allocate_2D_array(height, width);
  
  ifstream input(filename);

  char line[512];
  char space[] = " ";

  for (int r = 0; r<height; r++) {
    input.getline(line, 512);
    strcpy(m[r], line);
    while ( (int) strlen(m[r]) < width )
      strcat(m[r], space);
  }
  
  return m;
}

/* pre-supplied function to print the tube map */
void print_map(char **m, int height, int width) {
  cout << setw(2) << " " << " ";
  for (int c=0; c<width; c++)
    if (c && (c % 10) == 0) 
      cout << c/10;
    else
      cout << " ";
  cout << endl;

  cout << setw(2) << " " << " ";
  for (int c=0; c<width; c++)
    cout << (c % 10);
  cout << endl;

  for (int r=0; r<height; r++) {
    cout << setw(2) << r << " ";    
    for (int c=0; c<width; c++) 
      cout << m[r][c];
    cout << endl;
  }
}

/* pre-supplied helper function to report the errors encountered in Question 3 */
const char *error_description(int code) {
  switch(code) {
  case ERROR_START_STATION_INVALID: 
    return "Start station invalid";
  case ERROR_ROUTE_ENDPOINT_IS_NOT_STATION:
    return "Route endpoint is not a station";
  case ERROR_LINE_HOPPING_BETWEEN_STATIONS:
    return "Line hopping between stations not possible";
  case ERROR_BACKTRACKING_BETWEEN_STATIONS:
    return "Backtracking along line between stations not possible";
  case ERROR_INVALID_DIRECTION:
    return "Invalid direction";
  case ERROR_OFF_TRACK:
    return "Route goes off track";
  case ERROR_OUT_OF_BOUNDS:
    return "Route goes off map";
  }
  return "Unknown error";
}

/* presupplied helper function for converting string to direction enum */
Direction string_to_direction(const char *token) {
  const char *strings[] = {"N", "S", "W", "E", "NE", "NW", "SE", "SW"};
  for (int n=0; n<8; n++) {
    if (!strcmp(token, strings[n])) 
      return (Direction) n;
  }
  return INVALID_DIRECTION;
}

/* first function:
 
 set up two loops, one through each row, and then for each row, one loop through each column, comparing the target against the coordinate's associated symbol. if there is a successful comparison, return true. otherwise false, and set r and c to -1 */

bool get_symbol_position(char **map,int height,int width,char target,int& r, int& c){
    int columncount = 0, rowcount = 0;
    for (rowcount = 0;rowcount < height; rowcount++){
        for (columncount = 0; columncount < width; columncount++){
            //cout << map[rowcount][columncount] << endl;
            if (map[rowcount][columncount]==target){
                r = rowcount;
                c = columncount;
                return true;
            }}}
        r = -1;
        c = -1;
    return false;
}

/* second function:
 
 open up a file, and compare the given name with the 3rd to the last character of each line of the file (the format of each file is standard with the first character being a symbol, the second a space, and then third to the end of the line being the associated name. if there is a correct comparison, return the associated symbol (the first character of the same line). Compare both against lines and stations, and if nothing appears, return a blank space.
 */
char get_symbol_for_station_or_line(const char name[]) {
    ifstream input;
    input.open("lines.txt");
    char str[MAX];
    while (!input.fail()){
        input.getline(str, 30);
        if (strcmp(&str[2], name) == 0){
            input.close();
            return static_cast<char>(str[0]);
        }
    }
    input.close();
    input.open("stations.txt");
    while (!input.fail()){
        input.getline(str, 30);
        if (strcmp(&str[2], name) == 0){
            input.close();
            return static_cast<char>(str[0]);
        
        }}
    input.close();
    return ' ';
}


//a simple boolean function that checks whether or not the current coordinate is a station. the character passed in associated with the current coordinates will be compared against the first character of each line of the stations.txt file, and if the comparison comes out as successful, then you know you are at a station. this will be useful to check the start point and end point. //
bool is_symbol_station(char sym){
    ifstream input;
    input.open("stations.txt");
    char str[MAX];
    while (!input.fail()){
        input.getline(str,30);
        if (str[0] == sym){
            input.close();
            return true;
        }
    }
    input.close();
    return false;
}


// similar to the get_symbol_from_station() func, a void function that searches through the document of stations with their associated symbols. it compares the symbol that you are currently at with the first character of each line, and if they are the same, then it copies the name on the same line into the string destination[] //
void get_station_from_symbol(char destination[], char ch){
    ifstream input;
    input.open("stations.txt");
    char str[MAX];
    while (!input.fail()){
        input.getline(str, MAX);
        if (str[0] == ch){
            strcpy(destination, &str[2]);
            input.close();
        }}
    input.close();
    
}
 


// a boolean function that checks whether or not the given coordinates are outside of the range of the map by checking if either coordinate is less than 0, or if r is greater than the height of the map, or c greater than the width of the map //

bool not_out_of_bounds(char **map, int r, int c, int height, int width){
    if ((r < 0) || (c < 0) || (r >= height) || (c >= width)){
        return false;
    }
    return true;
}


// a boolean function that checks whether or not the given coordinates are in blank space, in other words, not on a track or station //
bool not_off_track( char **map, int r, int c){
    if (map[r][c] != ' ') {
        return true;
    }
    return false;
}


//a void function that checks if the line change is happening at a station. if the previous coordinates was a station AND the current coordinates character is not the same as the character of the twice previous coordinate, then there has been an appropriate line change, and as such the reference of the linechange coutner is incremented //
void line_change_at_station(char ** map, int r, int c, int previous_r, int previous_c, int twice_previous_r, int twice_previous_c, int& linechange){
    char sym = map[previous_r][previous_c];
    if ((is_symbol_station(sym)) && (map[r][c] != map[twice_previous_r][twice_previous_c])){
            linechange++;
        }
}



// a function that will update references of the three present coordinates r and c, as well as the previous and twice previous coordinates using references. It does this by working out what the direction token is and incrementing/decrementing the value of r and/or c as necessary //
void update_coordinates(int& r, int& c, int& previous_r, int& previous_c, int& twice_previous_r, int& twice_previous_c, Direction d_token){
    twice_previous_r = previous_r;
    twice_previous_c = previous_c;
    previous_r = r;
    previous_c = c;
    if ((Direction)d_token == N){
        r--;}
    else if ((Direction)d_token == S){
        r++;}
    else if ((Direction)d_token == W){
        c--;}
    else if ((Direction)d_token == E){
        c++;}
    else if ((Direction)d_token == NE){
        r--;
        c++;}
    else if ((Direction)d_token == SE){
        r++;
        c++;}
    else if ((Direction)d_token == SW){
        r++;
        c--;}
    else if ((Direction)d_token == NW){
        c--;
        r--;}
    
}


/* Function 3 
 this function has to take in a string of directions as well as the string name of the start station, and return the number of line changes over the course of the journey if it's valid, else return a negative integer associated with a specific error code. All details of the process are commented throughout the function.
 */

int validate_route(char **map, int height, int width, const char start_station[], const char route[], char destination[]) {
    
    //introduce three sets of coordinates to keep track of the current location and the previous two locations, also introduce a counter for the main loop through each direction //
    int r = 0, c = 0, previous_c = 0, previous_r =0, twice_previous_c= 0, twice_previous_r= 0;
    int count = 0;
    
    
    //introduce the linechange counter //
    int linechange = 0;
    
    // get the starting station symbol using get_symbol_for_station_or_line() //
    char target = get_symbol_for_station_or_line(start_station);
    
    //if it is the case that the symbol is a valid starting station, we can continue, else return the error code for ERROR_START_STATION_INVALID//
    if (get_symbol_position(map, height, width, target, r, c)){
        
        // set up a new pointer dir_tok, a token that is taken from the routelist. the token each time will be taken up until the next comma in the route string. Note that str_tok will actually allow for strings that have multiple commas to be read normally, but it is not clear whether or not we should treat this as incorrect or not. eg "N,,E,SE" would still be read as N, E and SE //
        char *dir_tok = NULL;
        
        // make sure a direction string has actually been provided, else return invalid direction //
        if (strcmp(route,"") == 0){
            return -5;
        }
        
        // set up a new copy of the route which we can perform strtok on as strtok actually alters the array and we cannot use route[] as it is a const char //
        char route_copy[MAX];
        strcpy(route_copy, route);
        dir_tok = strtok(route_copy, ",");
        
        // now set up a while loop that only continues while the current direction token exists //
        while (dir_tok != NULL){
            
            // using the dir_tok, convert that to the type Direction using the pre-supplied helper function string_to_direction() //
            Direction d_token = string_to_direction(dir_tok);
            
            // check that the token equivalent of the current direction string is not INVALID_DIRECTION, otherwise return the associated error code //
            if (d_token != INVALID_DIRECTION){
    
                // update all of the coordinates (incl current, previous and twice previous) using the update_coordinates helper function //
                update_coordinates(r, c, previous_r, previous_c, twice_previous_r, twice_previous_c, d_token);
                dir_tok = strtok(NULL, ",");
            
                // now we have the new coordinate, we need to check them against certain criteria, the first of which is checking that the current coordinate is not out of bounds, using the helper function defined below. if it is, return the code for ERROR_OUT_OF_BOUNDS //
                if (!not_out_of_bounds(map, r, c, height, width)) {
                    return -7;
                }
                
                // now check that the current coordinates aren't off the track, otherwise returning the code for ERROR_OFF_TRACK //
                if (!not_off_track(map, r, c)){
                    return -6;
                }
                
                // first making sure that there is a correct value for previous and twice previous coordinates using the counter catch, we know that the coordinates aren't out of bounds/off the track. we now check that it is not the case that we are currently at a station AND the r and c coordinates are the same as the twice previous r and c coordinates. This would mean that we have moved on a step, and then moved back to the same space, without being at a station and would have backtracked. If this is the case, then return the code for ERROR_BACKTRACKING_BETWEEN_STATIONS //
                if (count >1) {
                    if (!(is_symbol_station(map[previous_r][previous_c])) && (r == twice_previous_r) && (c == twice_previous_c)) {
                        return -4;
                    }
                }
                
                // again using the counter catch to check that there are values for the previous coordinates, we also want to check that we haven't jumped between lines. If the previous station is not a station, and the character associated with our current coordinate is not the same as the character associated with our previous coordinate, then we have jumped between lines, and the error code for ERROR_LINE_HOPPING is returned //
                if (count > 0) {
                    if (!(is_symbol_station(map[r][c])) && !(is_symbol_station(map[previous_r][previous_c])) && (map[r][c] != map[previous_r][previous_c])){
                        return -3;
                    }
                    
                    // another of backtracking instance when a train goes out one step and straight back which isn't caught by the catch above //
                    if ((is_symbol_station(map[twice_previous_r][twice_previous_c])) && (r == twice_previous_r) && (c == twice_previous_c)) {
                        return -4;
                    }
                }
                
                // finally, to check for line changes, which cannot occure until the train has moved at least two stops on so that there are meaningful values for previous and twice previous coordinates, we use the helper function line_change_at_station(), the linechange counter is augmented if a linechange has occured by reference //
                
                if (count > 1) {
                    line_change_at_station(map, r, c, previous_r, previous_c, twice_previous_r, twice_previous_c, linechange);
                }
                
                // augment the counter per loop //
                count++;
                    
                }
            
            // code for ERROR_INVALID_DIRECTION //
            else {
                return -5;
            }
        }
    }
    
    // code for ERROR_START_STATION_INVALID //
    else {
        return -1;
    }
    
    
    // now we have exited the loop of all the directions, we have the final coordinate. we now check that this symbol is associated with a station //
    if (is_symbol_station(map[r][c])) {
        // if it is a station, we now get the station name from the symbol using the helper function and assign it to the string destination. we also return the number of linechanges that have occurred //
        get_station_from_symbol(destination, map[r][c]);
        return linechange;
    }
    //if we haven't ended up at a station, we return the error code for ERROR_ROUTE_ENDPOINT_IS_NOT_STATION //
    else {
        return -2;
    }
}
    
    
