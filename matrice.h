/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
MAJ : 7 mai 2014
Fichier matrice.h
Déclaration des méthodes de la classe Matrice */

#ifndef __MATRICE__
#define __MATRICE__

// Librairies
#include <iostream>
#include <string>
#include <cstring>
#include <fstream> // permet de gérer les fichiers
#include <vector>
#include <stdlib.h> // fonction atoi()
#include <sstream> // conversion int -> string

class Matrice
{
	int n, m; // taille de la matrice (n colonnes et m lignes)
	int tailleFichier; // nombre de lignes
	int max; // nombre de valeurs maximale
	std::string *tabX;
	std::string *tabY;
	int *tabVal;
private:
	int charToInt(char); // conversion char vers int
	int charToInt(char *); // conversion char * vers int (surcharge)
	int stringToInt(std::string); // conversion string vers int
	std::string intToString(int); // conversion int vers string
	bool creuse(); // détermine si c'est une matrice creuse (true) ou non (false)
	bool estCarre(); // indique si la matrice est carré (true) ou non (false)
	// Setteurs
	void setValeur(int, int, int);
	// Getteurs
	int getValeur(int, int); // retourne la valeur des coordonnées en paramètres (le passer en privé ?)
	std::string getX(int); // retourne la valeur X du tableau tabX
	std::string getY(int); // retourne la valeur Y du tableau tabY
	int getVal(int); // retourne la valeur Val du tableau tabVal
	int getTaille(bool); // retourne la taille de la matrice (attribut tailleFichier) (false) ou réel (true)
	int getMax(); // retourne le nombre maximal de cases (attribut max)
public:
	Matrice(int, int); // construit une matrice neutre de n x m
	Matrice(std::string);
	Matrice(Matrice &); // constructeur de recopie
	~Matrice();
	void addition(Matrice &);
	void soustraction(Matrice &);
	void multiplication(Matrice &);
	void multiplication(int); // multiplie la matrice par une constante (surcharge)
	void division(Matrice &);
	void division(int); // divise la matrice par une constante (surcharge)
	void factorisation();
	void transposee(); // effectue la transposée de la matrice
	void inverse(); // effectue l'inverse de la matrice
	void afficher();
	int determinant(); // calcul le déterminant de la matrice
	void sauvegarde(std::string); // permet de sauvegarder une matrice dans un fichier
};
#endif
