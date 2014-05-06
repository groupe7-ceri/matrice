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
	// initialisation des variables
	this->tailleFichier = 0;
	// Lit le fichier
	const char * nom = nomFichier.c_str(); // conversion string => const char *
	ifstream fichier(nom);
	if((fichier != NULL) && (fichier)) // si le fichier existe et non vide
	{
		// lecture de la taille de la matrice (première ligne)
		string taille;
		fichier >> taille; // extraction de la première ligne
		// traitement de la première ligne (n et m)
		//cout<<"n : "<<taille[5]<<" - m : "<<taille[7]<<endl; // tmp
		cout<<"taille : "<<taille.size()<<endl;
		if(taille.size() > 8)
		{
			cout<<"n ou m est à 2 chiffres"<<endl;
			// algo a faire
		}
		else // la valeur de n et de m contient un seul chiffre
		{
			this->n = this->charToInt(taille[5]);
			this->m = this->charToInt(taille[7]);
		}
		cout<<"n : "<<this->n<<" - m : "<<this->m<<endl; // tmp
		this->max = this->n * this->m; // calcul du nombre de valeurs maximal
		// comptage du nombre de ligne
		string ligne;
		while(getline(fichier, ligne))
			this->tailleFichier++;
		if(this->tailleFichier ==	 0) 
		{
			cout<<"Erreur de lecture du fichier, arret du programme"<<endl;
			exit(4); // arret du programme
		}
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
		// Algo lecture des lignes et stockage dans les trois tableaux
		fichier.clear();
		fichier.seekg(0, ios::beg); // retour au début du fichier
		int i = 0;
		while(getline(fichier, ligne))
		{
			if(ligne.find("size=", 0) != 0) // la 1e ligne (contenant size=) n'est pas lu
			{
				//cout<<"ligne "<<i<<" : "<<ligne<<endl;
				char l = ligne[0];
				this->tabX[i] = l;
				char c = ligne[2];
				this->tabY[i] = c;
				this->tabVal[i] = this->charToInt(ligne[4]);
				cout<<i<<" : "<<this->tabX[i]<<"_"<<this->tabY[i]<<"_"<<this->tabVal[i]<<endl; // tmp, pour débug
				i++;
			}
			
		}
		fichier.close(); // Fermeture du fichier
	}
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
	cout<<"Voici la matrice :"<<endl;
	string x, y;
	int val;
	for(int i = 0; i < (this->tailleFichier - 1); i++)
	{
		x = tabX[i]; // récupération de la valeur X
		y = tabY[i]; // récupération de la valeur Y
		val = tabVal[i]; // récupération de la valeur
		cout<<"i : "<<i<<" - ["<<x<<"]["<<y<<"] val : "<<val<<endl;
	}
	
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
