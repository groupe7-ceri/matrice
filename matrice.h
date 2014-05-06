<<<<<<< HEAD
/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
MAJ : 6 mai 2014
Fichier matrice.h
Déclaration des méthodes de la classe Matrice */
=======
/**
 * \file matrice.h
 * \brief Génie logiciel - Projet Matrice - L2 INFORMATIQUE - Groupe TP2
 * \author Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
 * \date 28 mars 2014
 *
 * \date MAJ 11 Avril 2014
 *
 * Déclaration des méthodes de la classe Matrice
*/
>>>>>>> e36d8e7174aeda5b036045619a6b18c2aeac25fd

#ifndef __MATRICE__
#define __MATRICE__

// Librairies
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdlib.h> // fonction atoi()

/**
 * \class Matrice
 * \brief Classe représentant la matrice
 *
 * La classe gère les différentes opérations possibles sur la matrice
*/

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
<<<<<<< HEAD
	Matrice(std::string);
	Matrice(Matrice &); // constructeur de recopie
	~Matrice();
	void addition(Matrice &);
	void soustraction(Matrice &);
	void multiplication(Matrice &);
	void division(Matrice &);
	void factorisation();
	void afficher();
=======

	Matrice(std::string);/** * \brief Constructeur * Constructeur de la class Matrice *\param Un nom de fichier texte */
	~Matrice(); /** * \brief Destructeur * Destructeur de la classe Matrice */
	void addition(Matrice &); /** * \brief Addition * Fonction additionnant 2 matrices * \param Matrice */
	void soustraction(Matrice &); /** * \brief Soustraction * Fonction soustrayant  2 matrices * \param Matrice */
	void multiplifcation(Matrice &); /** * \brief AMultiplicationn * Fonction Fonction mutliyant 2 matrices * \param Matrice */
	void division(Matrice &); /** * \brief Division * Fonction divisant 2 matrices * \param Matrice */
	void factorisation(); /** * \brief Factorisation * Fonction factorisant une matrices */
>>>>>>> e36d8e7174aeda5b036045619a6b18c2aeac25fd
	// Setteurs
	void setTabX(std::string &, int);
	void setTabY(std::string &, int);
	void setTabVal(int &, int);
	// Getteurs
	Matrice getMatrice(); /** * \brief getMatrice * Fonction retournant la matrice courante * \param Matrice */
};
#endif
