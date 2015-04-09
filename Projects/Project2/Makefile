proj2: proj2.o CipherMessage.o Date.o
	g++ proj2.o CipherMessage.o Date.o -o proj2

proj2.o: proj2.cpp
	g++ -Wall -c proj2.cpp

Date.o: Date.cpp
	g++ -Wall -c Date.cpp

CipherMessage.o: CipherMessage.cpp Date.o
	g++ -Wall -c CipherMessage.cpp