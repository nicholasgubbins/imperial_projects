chess: ChessMain.o Implementation.o ChessBoard.o Piece.o Rook.o King.o Queen.o Pawn.o Bishop.o Knight.o
	g++ -g -Wall ChessMain.o Implementation.o ChessBoard.o Piece.o Rook.o King.o Queen.o Pawn.o Bishop.o Knight.o -o chess
ChessMain.o: ChessMain.cpp ChessBoard.o ChessBoard.hpp
	g++ -g -Wall -c ChessMain.cpp -o ChessMain.o
Implementation.o: Implementation.cpp Implementation.h
	g++ -g -Wall -c Implementation.cpp -o Implementation.o
ChessBoard.o: ChessBoard.cpp Chessboard.hpp Implementation.o Piece.o Rook.o King.o Knight.o Queen.o Pawn.o Bishop.o
	g++ -g -Wall -c ChessBoard.cpp -o ChessBoard.o
Piece.o: Piece.cpp Piece.hpp Implementation.o
	g++ -g -Wall -c Piece.cpp -o Piece.o
Rook.o: Rook.cpp Rook.hpp Piece.o Piece.hpp
	g++ -g -Wall -c Rook.cpp -o Rook.o
King.o: King.cpp King.hpp Piece.o Piece.hpp
	g++ -g -Wall -c King.cpp -o King.o
Knight.o: Knight.cpp Knight.hpp Piece.o Piece.hpp
	g++ -g -Wall -c Knight.cpp -o Knight.o
Queen.o: Queen.cpp Queen.hpp Piece.o Piece.hpp
	g++ -g -Wall -c Queen.cpp -o Queen.o
Bishop.o: Bishop.cpp Bishop.hpp Piece.o Piece.hpp
	g++ -g -Wall -c Bishop.cpp -o Bishop.o
Pawn.o: Pawn.cpp Pawn.hpp Piece.o Piece.hpp
	g++ -g -Wall -c Pawn.cpp -o Pawn.o
clean:
	rm -f chess *.o
