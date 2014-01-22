class Plugboard {
private:
    int cablearraylen;
    int cablearray[ALPHA_LENGTH];
    
public:
    Plugboard(char file[]);
    void convertLetter(Letter &input);
};