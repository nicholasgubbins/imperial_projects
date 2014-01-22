enigma:  checkfile.o implementation.o rotors.o plugboard.o reflector.o machine.o main.o
	g++ -Wall -g main.o implementation.o machine.o checkfile.o rotors.o plugboard.o reflector.o  -o enigma
main.o: main.cpp implementation.o machine.o rotors.o plugboard.o reflector.o errors.h enigma.h machine.hpp 
	g++ -Wall -g -c main.cpp
implementation.o: implementation.cpp enigma.h
	g++ -Wall -g -c implementation.cpp
checkfile.o: checkfile.cpp errors.h enigma.h
	g++ -Wall -g -c checkfile.cpp
machine.o: machine.cpp machine.hpp errors.h enigma.h rotors.hpp plugboard.hpp reflector.hpp
	g++ -Wall -g -c machine.cpp
rotors.o: rotors.cpp enigma.h rotors.hpp implementation.o
	g++ -Wall -g -c rotors.cpp
plugboard.o: plugboard.cpp enigma.h plugboard.hpp implementation.o
	g++ -Wall -g -c plugboard.cpp
reflector.o: reflector.cpp enigma.h reflector.hpp implementation.o
	g++ -Wall -g -c reflector.cpp

clean:
	rm -f enigma *.o