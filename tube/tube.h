enum Direction {N, S, W, E, NE, NW, SE, SW, INVALID_DIRECTION};

/* error codes for Question 3 */
#define ERROR_START_STATION_INVALID -1 
#define ERROR_ROUTE_ENDPOINT_IS_NOT_STATION -2
#define ERROR_LINE_HOPPING_BETWEEN_STATIONS -3
#define ERROR_BACKTRACKING_BETWEEN_STATIONS -4
#define ERROR_INVALID_DIRECTION -5
#define ERROR_OFF_TRACK -6
#define ERROR_OUT_OF_BOUNDS -7

/* pre-supplied function to load a tube map from a file*/
char **load_map(const char *filename, int &height, int &width);

/* pre-supplied function to print the tube map */
void print_map(char **m, int height, int width);

/* pre-supplied helper function to describe errors for Question 3 */
const char *error_description(int code);

/* presupplied helper function for converting string to Direction enum */
Direction string_to_direction(const char *token);

/* function to get the symbol position of target within the map. returns a truth value based on whether or not the target does exist within the map and alters the values of r and c */

bool get_symbol_position(char **map, int height, int width, char target, int&r, int& c);

// function that gets a symbol from the name of either a station or a line, cross-checking it with the provided .txt files //
char get_symbol_for_station_or_line(const char name[]);

//function that checks whether or not a given route is valid (ie free of the errors seen above) and if so, returns the number of line changes that occur in the route, and assigns the final station name to the destination string //
int validate_route(char **map, int height, int width, const char start_station[], const char route[], char destination[]);

// returns a truth value based on whether or not a character is used for a station on the map //
bool is_symbol_station(char sym);


//a helper function that updates the destination string with the name of the final station //
void get_station_from_symbol(char destination[], char ch);


// a boolean helper function that checks whether or not the given coordinates are outside of the range of the map //
bool not_out_of_bounds(char **map, int r, int c, int height, int width);


// a boolean helper function that checks whether or not the given coordinates are in blank space, in other words, not on a track or station //
bool not_off_track( char **map, int r, int c);

//  a helper function that checks whether or not a line change is occuring at a station based on the current location symbol, the previous location symbol, and the twice previous location symbol //
void line_change_at_station(char ** map, int r, int c, int previous_r, int previous_c, int twice_previous_r, int twice_previous_c, int& linechange);

// a helper function that updates the three sets of coordinates based on the value of the direction //
void update_coordinates(int& r, int& c, int& previous_r, int& previous_c, int& twice_previous_r, int& twice_previous_c, Direction d_token);