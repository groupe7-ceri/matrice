/**
 * \file gestion.h
 * \brief Génie logiciel - Projet Matrice - L2 INFORMATIQUE - Groupe TP2
 * \author Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
 * \date 28 mars 2014
 *
 * \date MAJ 11 Avril 2014
 *
 * Déclaration des méthodes de la classe Gestion
*/

// Bibliothèques / Librairie
#include <iostream>

// Classes
#include "matrice.h"

/**
 * \class Gestion
 * \brief Classe permettant de gérer les matrices
 *
 * Cette classe permet de gérer les matrices
*/

class Gestion
{
	Matrice tableau[]; // tableau des objets matrice à manipuler
	int nbre; // nombre de matrice maximum
public:
	Gestion(int);
	~Gestion();
};
