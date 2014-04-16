/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
MAJ : 16 avril 2014
Fichier matrice.cpp
Implémentation des méthodes de la classe Matrice */

#include "matrice.h"

using namespace std;

// Constructeur
Matrice::Matrice(string nomFichier)
{
	n = 3; // valeurs temporaires
	m = 3;
	int tailleFichier = 0; // compteur du nombre de ligne
	int j = 0;
	// Lit le fichier
	const char * nom = nomFichier.c_str(); // conversion string => const char *
	ifstream fichier(nom);
	if((fichier != NULL) && (fichier)) // si le fichier existe et non vide
	{
		// lecture de la taille de la matrice (première ligne)
		string taille;
		fichier >> taille;
		// comptage du nombre de ligne
		string ligne;
		while(getline(fichier, ligne))
			tailleFichier++;
		// Initialisation des trois tableaux
		// tailleFichier - 1 car on commence à la 2eme ligne
		tabX = new string[tailleFichier - 1];
		tabY = new string[tailleFichier - 1];
		tabVal = new int[tailleFichier - 1];
		for(int i = 0; i < (tailleFichier - 1); i++)
		{
			this->tabX[i] = "x";
			this->tabY[i] = "y";
			this->tabVal[i] = 0;
		}
		// initialisation du tableau OK
		// Algo lecture des lignes
		fichier.clear();
		fichier.seekg(0, ios::beg); // retour au début du fichier
		for(int i = 0; i < tailleFichier; i++)
		{
			getline(fichier, ligne);
			if(ligne.find("size=", 0) != 0) // la première ligne est ignorée (car elle contient "size=" à la première occurence
			{
				cout<<ligne[0]<<"_"<<ligne[2]<<"_"<<ligne[4]; // tmp
				//string l = ligne[0];
				//string c = ligne[2];
				//this->tabVal[i] = atoi(ligne[4]);
			}
			cout<<endl;
		}
		// Initialise la matrice
		this->tabX[0] = "0";
		this->tabX[1] = "0";
		this->tabX[2] = "1";
		this->tabX[3] = "2";
		this->tabX[4] = "2";
		this->tabY[0] = "1";
		this->tabY[1] = "2";
		this->tabY[2] = "0";
		this->tabY[3] = "1";
		this->tabY[4] = "2";
		this->tabVal[0] = 1;
		this->tabVal[1] = 2;
		this->tabVal[2] = 3;
		this->tabVal[3] = 5;
		this->tabVal[4] = 7;
		fichier.close(); // Fermeture du fichier
	}
}
// Méthodes publiques
Matrice Matrice::addition(Matrice &matrice)
{
}
Matrice soustraction(Matrice &matrice)
{
}
Matrice multiplifcation(Matrice &matrice)
{
}
Matrice division(Matrice &matrice)
{
}
Matrice factorisation()
{
}
// Méthodes privées
// Setteurs
void Matrice::setTabX(string &tabX, int taille)
{
	
}
void Matrice::setTabY(string &tabY, int taille)
{
}
void Matrice::setTabVal(int &tabVal, int taille)
{
}
// Getteurs
Matrice Matrice::getMatrice()
{
}
// Destructeur
Matrice::~Matrice()
{
	// dtor
}
