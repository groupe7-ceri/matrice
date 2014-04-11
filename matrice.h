/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
MAJ : 11 avril 2014
Fichier matrice.h
Déclaration des méthodes de la classe Matrice */

#ifndef __MATRICE__
#define __MATRICE__

// Librairies
#include <iostream>
#include <string>
#include <fstream>

class Matrice
{
	int n, m; // taille de la matrice (n colonnes et m lignes)
	std::string *tabX;
	std::string *tabY;
	int *tabVal;
private:
public:
	Matrice(std::string);
	~Matrice();
	Matrice addition(Matrice &);
	Matrice soustraction(Matrice &);
	Matrice multiplifcation(Matrice &);
	Matrice division(Matrice &);
	Matrice factorisation();
	// Setteurs
	// Getteurs
	Matrice getMatrice(); // retourne la matrice courante
};
#endif
