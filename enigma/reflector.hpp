class Reflector {
private:
    int cablearraylen;
    int cablearray[ALPHA_LENGTH];
    
public:
    Reflector(char file[]);
    void convertLetter(Letter &input);
};
