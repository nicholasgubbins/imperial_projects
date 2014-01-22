class Reflector;
class Rotor;
class Plugboard;

class Machine {
    
private:
    int num_of_rotors;
    bool goingleft;
    Letter currentLet;
    //note that my enigma machine can only hold a maximum of 26 rotors//
    Rotor *rotorlist[ALPHA_LENGTH];
    int configurationcount;
    int configuration_array[ALPHA_LENGTH];
    Plugboard *plugboard;
    Reflector *reflector;
    
public:
    Machine(char **argv, int argc);
    int checkConfiguration();
    int runMachine();
    void clear();
};


