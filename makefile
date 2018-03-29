testlist: main.o	
	g++ -std=c++11 main.o -o testlist

all:
	
main.o: main.cpp intlist.h
	g++ -std=c++11 -c -Os main.cpp -o main.o

debug:
	g++ -std=c++11 -g -O0 main.cpp -o main.o

clean:
	rm -f *.o testlist