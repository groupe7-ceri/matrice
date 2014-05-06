/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
MAJ : 6 mai 2014
Fichier matrice.h
Déclaration des méthodes de la classe Matrice */

#ifndef __MATRICE__
#define __MATRICE__

// Librairies
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdlib.h> // fonction atoi()

class Matrice
{
	int n, m; // taille de la matrice (n colonnes et m lignes)
	int tailleFichier; // nombre de lignes
	int max; // nombre de valeur maximale
	std::string *tabX;
	std::string *tabY;
	int *tabVal;
private:
	int charToInt(char); // conversion char vers int
	int charToInt(char *); // conversion char * vers int (surcharge)
public:
	Matrice(std::string);
	Matrice(Matrice &); // constructeur de recopie
	~Matrice();
	void addition(Matrice &);
	void soustraction(Matrice &);
	void multiplication(Matrice &);
	void division(Matrice &);
	void factorisation();
	void afficher();
	// Setteurs
	void setTabX(std::string &, int);
	void setTabY(std::string &, int);
	void setTabVal(int &, int);
	// Getteurs
	Matrice getMatrice(); // retourne la matrice courante
};
#endif
