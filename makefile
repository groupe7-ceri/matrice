all: matrice.o

matrice.o: matrice.cpp matrice.h
	g++ -c matrice.cpp

clean:
	rm -f *.cpp~
	rm -f *.h~
	rm -f *.o
