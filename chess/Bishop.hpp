class Bishop: public Piece{
public:
    Bishop(bool _white);
    void validMoves(const Location loc, std::vector<Location> &possibleMoves, std::map<Location, Piece *> board);
};