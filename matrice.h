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

#ifndef __MATRICE__
#define __MATRICE__

// Librairies
#include <iostream>
#include <string>
#include <fstream>

/**
 * \class Matrice
 * \brief Classe représentant la matrice
 *
 * La classe gère les différentes opérations possibles sur la matrice
*/

class Matrice
{
	int n, m; // taille de la matrice (n colonnes et m lignes)
	std::string *tabX;
	std::string *tabY;
	int *tabVal;
private:
public:

	Matrice(std::string);/** * \brief Constructeur * Constructeur de la class Matrice *\param Un nom de fichier texte */
	~Matrice(); /** * \brief Destructeur * Destructeur de la classe Matrice */
	void addition(Matrice &); /** * \brief Addition * Fonction additionnant 2 matrices * \param Matrice */
	void soustraction(Matrice &); /** * \brief Soustraction * Fonction soustrayant  2 matrices * \param Matrice */
	void multiplifcation(Matrice &); /** * \brief AMultiplicationn * Fonction Fonction mutliyant 2 matrices * \param Matrice */
	void division(Matrice &); /** * \brief Division * Fonction divisant 2 matrices * \param Matrice */
	void factorisation(); /** * \brief Factorisation * Fonction factorisant une matrices */
	// Setteurs
	// Getteurs
	Matrice getMatrice(); /** * \brief getMatrice * Fonction retournant la matrice courante * \param Matrice */
};
#endif
