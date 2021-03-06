all: Driver.o Aux.o Hand.o TwoHands.o AlgRater.o Alg.o 
	g++ -Wall -std=c++11 Driver.o Aux.o Hand.o TwoHands.o AlgRater.o Alg.o -o AlgRater.out

Alg.o: Alg.cpp
	g++ -Wall -c -std=c++11 Alg.cpp

AlgRater.o: AlgRater.cpp
	g++ -Wall -c -std=c++11 AlgRater.cpp

TwoHands.o: TwoHands.cpp
	g++ -Wall -c -std=c++11 TwoHands.cpp
Hand.o: Hand.cpp
	g++ -Wall -c -std=c++11 Hand.cpp
Aux.o: Aux.cpp
	g++ -Wall -c -std=c++11 Aux.cpp
Driver.o: Driver.cpp
	g++ -Wall -c -std=c++11 Driver.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#

run:
	./AlgRater.out
