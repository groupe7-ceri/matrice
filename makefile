all: matrice.o gestion.o

matrice.o: matrice.cpp matrice.h
	g++ -c matrice.cpp

gestion.o: gestion.cpp gestion.h
	g++ -c gestion.cpp
