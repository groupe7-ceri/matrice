/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
MAJ : 11 avril 2014
Fichier matrice.h
Déclaration des méthodes de la classe Matrice */

// Librairies
#include <iostream>
#include <string>
#include <fstream>

class Matrice
{
	int taille;
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
