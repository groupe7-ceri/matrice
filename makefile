Matrice: main.o matrice.o
	g++ main.o matrice.o -o Matrice
all: main.o matrice.o

main.o: main.cpp
	g++ -c main.cpp

matrice.o: matrice.cpp matrice.h
	g++ -c matrice.cpp

clean:
	rm -f *.cpp~
	rm -f *.h~
	rm -f *.o
