/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
MAJ : 6 mai 2014
Fichier matrice.cpp
Implémentation des méthodes de la classe Matrice */

#include "matrice.h"

using namespace std;

// Constructeur
Matrice::Matrice(string nomFichier)
{
	int j = 0;
	int separateur = 6; // position du séparateur (par défaut, il est sur le caractère 6)
	int c1 = -1, c2 = -1;
	// initialisation des variables
	this->tailleFichier = 0;
	this->n = -1;
	this->m = -1;
	this->max = -1;
	// Lit le fichier
	const char * nom = nomFichier.c_str(); // conversion string => const char *
	ifstream fichier(nom); // ouverture du fichier
	if((fichier != NULL) && (fichier)) // si le fichier existe et non vide
	{
		// lecture de la taille de la matrice (première ligne)
		string taille;
		fichier >> taille; // extraction de la première ligne
		// traitement de la première ligne (n et m)
		// lecture de n
		c1 = this->charToInt(taille[5]);
		if(taille[6] != '-') // si la lettre 6 n'est pas un séparateur
		{
			c2 = this->charToInt(taille[6]);
			c1 *= 10; // concatène c1 et c2
			c1 += c2;
			separateur = 7; // séparateur sur le caractère 7
		}
		this->n = c1; // stockage de la valeur définitive c1 de n
		// lecture de m
		c1 = this->charToInt(taille[separateur + 1]); // réassignation de c1 et de c2
		if(taille[separateur + 2] != '\0') // si la case existe, c'est qu'il y a un chiffre
		{
			c2 = this->charToInt(taille[separateur + 2]);
			c1 *= 10; // concatène c1 et c2
			c1 += c2;
		}
		this->m = c1;  // stockage de la valeur définitive c1 de m
		this->max = this->n * this->m; // calcul du nombre de valeurs maximale
		// comptage du nombre de ligne
		string ligne;
		while(getline(fichier, ligne))
			this->tailleFichier++;
		if(this->tailleFichier == 0) 
		{
			cout<<"Erreur de lecture du fichier, arret du programme"<<endl;
			exit(4); // arret du programme
		}
		// Initialisation des trois tableaux
		tabX = new string[tailleFichier - 1]; // tailleFichier - 1 car on commence à la 2eme ligne
		tabY = new string[tailleFichier - 1];
		tabVal = new int[tailleFichier - 1];
		for(int i = 0; i < (tailleFichier - 1); i++)
		{
			this->tabX[i] = "x";
			this->tabY[i] = "y";
			this->tabVal[i] = 0;
		}
		fichier.clear(); // retour au début du fichier
		fichier.seekg(0, ios::beg);
		// Lecture des lignes et stockage dans les trois tableaux
		int i = 0;
		while(getline(fichier, ligne))
		{
			if(ligne.find("size=", 0) != 0) // la 1e ligne (contenant size=) n'est pas lu
			{
				char l = ligne[0];
				this->tabX[i] = l;
				char c = ligne[2];
				this->tabY[i] = c;
				this->tabVal[i] = this->charToInt(ligne[4]);
				i++;
			}
			
		}
		fichier.close(); // Fermeture du fichier
	}
	// récapitulatif
	cout<<"Matrice créée :"<<endl;
	cout<<" - n : "<<this->n<<endl;
	cout<<" - m : "<<this->m<<endl;
	if(this->creuse())
		cout<<"Matrice creuse"<<endl;
	else
		cout<<"Matrice pleine"<<endl;
}
Matrice::Matrice(Matrice &matrice) // constructeur de recopie
{
	this->n = matrice.n;
	this->m = matrice.m;
	this->max = matrice.max;
	this->tailleFichier = matrice.tailleFichier;
	// Initialisation des trois tableaux
	tabX = new string[tailleFichier - 1]; // tailleFichier - 1 car on commence à la 2eme ligne
	tabY = new string[tailleFichier - 1];
	tabVal = new int[tailleFichier - 1];
	for(int i = 0; i < (tailleFichier - 1); i++)
	{
		this->tabX[i] = "x";
		this->tabY[i] = "y";
		this->tabVal[i] = 0;
	}
	// recopie tabX
	for(int i = 0; i < this->tailleFichier; i++)
	{
		this->tabX[i] = matrice.tabX[i];
		this->tabY[i] = matrice.tabY[i];
		this->tabVal[i] = matrice.tabVal[i];
	}
	// recopie tabY
	// recopie tabVal
}
// Méthodes publiques
void Matrice::addition(Matrice &matrice)
{
}
void Matrice::soustraction(Matrice &matrice)
{
}
void Matrice::multiplication(Matrice &matrice)
{
}
void Matrice::division(Matrice &matrice)
{
}
void Matrice::factorisation()
{
}
void Matrice::afficher()
{
	string x, y;
	int val;
	cout<<"Voici la matrice :"<<endl;
	for(int i = 0; i < (this->tailleFichier - 1); i++)
	{
		x = tabX[i]; // récupération de la valeur X
		y = tabY[i]; // récupération de la valeur Y
		val = tabVal[i]; // récupération de la valeur
		cout<<"i : "<<i<<" - ["<<x<<"]["<<y<<"] val : "<<val<<endl; // affichage temporaire
	}
	// affichage sous forme d'une matrice
}
// Méthodes privées
int Matrice::charToInt(char caractere)
{
	int valeur;
	valeur = caractere - '0';
	return valeur;
}
int Matrice::charToInt(char * caractere)
{
	int valeur;
	valeur = atoi(caractere);
	return valeur;
}
bool Matrice::creuse() // détermine si la matrice est creuse ou non
{
	bool creuse = false;
	int nbre = this->tailleFichier; // nombre de cases occupés
	float pc = 50 / 100;
	cout<<"max : "<<this->max<<" / nb : "<<nbre<<" = ";
	printf("pc : %.2f \n", pc); // instruction C pour affichage
	// calcul du nombre de case occupé par colonne (il faut au moins 1 case / colonne)
	return creuse;
}
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
int Matrice::getMax()
{
	if(this->max > 0)
		return this->max;
	else
		return 0;
}
int Matrice::getTaille()
{
	return this->tailleFichier;
}
// Destructeur
Matrice::~Matrice()
{
	// dtor
}
