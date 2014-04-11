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
	cout<<"constructeur avec "<<nomFichier<<endl; // tmp
	// Lit le fichier
	const char * nom = nomFichier.c_str(); // conversion string => const char *
	ifstream fichier(nom);
	if((fichier != NULL) && (fichier)) // si le fichier existe et non vide
	{
		cout<<"Fichier ouvert"<<endl;
		// Lit la taille de la matrice (n : colonnes - m : lignes) sur la première ligne
		// Initialisation des trois tableaux
		// Algo lecture des lignes
		// Initialise la matrice
		fichier.close(); // Fermeture du fichier
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
