/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
MAJ : 11 avril 2014
Fichier matrice.cpp
Implémentation des méthodes de la classe Matrice */

#include "matrice.h"

using namespace std;

// Constructeur
Matrice::Matrice(string nomFichier)
{
	// Lit le fichier
	const char * nom = nomFichier.c_str(); // conversion string => const char *
	ifstream fichier(nom);
	if((fichier != NULL) && (fichier)) // si le fichier existe et non vide
	{
		// Lit la taille de la matrice (nombre de lignes) => this->taille
		// Initialisation des trois tableaux
		// Algo lecture des lignes
		// Initialise la matrice
	}
}
// Méthodes publiques
// Méthodes privées
// Setteurs
// Getteurs

// Destructeur
Matrice::~Matrice()
{
	// dtor
}
