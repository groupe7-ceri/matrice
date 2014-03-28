/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
MAJ : 28 mars 2014
Fichier gestion.h
Déclaration des méthodes de la classe Gestion */

// Bibliothèques / Librairie
#include <iostream>

// Classes
#include "matrice.h"

class Gestion
{
	Matrice tableau[]; // tableau des objets matrice à manipuler
	int nbre; // nombre de matrice maximum
public:
	Gestion(int);
	~Gestion();
};
