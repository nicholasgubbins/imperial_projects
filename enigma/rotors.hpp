class Rotor {
private:
    int rotornum;
    bool next_to_rotate;
    int rotor_map[ALPHA_LENGTH];
    Rotor *last;
    int notch_location[ALPHA_LENGTH];

public:
    int rotation;
    void rotate();
    void rotation_check();
    Rotor(char file[], int _rotornum, Rotor *r);
    Rotor(char file[], int _rotornum);
    void convertLetter(Letter &input, bool goingleft);
};
