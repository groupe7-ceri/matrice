/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
MAJ : 7 mai 2014
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
	cout<<"Matrice initialisée avec le fichier "<<nomFichier<<endl;
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
	// recopie des tableaux
	for(int i = 0; i < this->tailleFichier; i++)
	{
		this->tabX[i] = matrice.tabX[i];
		this->tabY[i] = matrice.tabY[i];
		this->tabVal[i] = matrice.tabVal[i];
	}
	this->afficher();
}
// Méthodes publiques
void Matrice::addition(Matrice &matrice) // faite par Alex et Dylan
{
	if((this->n == matrice.n) && (this->m == matrice.m)) // les 2 matrices sont de même taille
	{
		// addition des deux matrices
		cout<<"addition ok"<<endl;
	}
	else
		cout<<"La matrice ne peux pas etre additionnée car différence de taille"<<endl;
}
void Matrice::soustraction(Matrice &matrice) // faite par Alex et Dylan
{
	if((this->n == matrice.n) && (this->m == matrice.m)) // les 2 matrices sont de même taille
	{
		// soustraction des deux matrices
		cout<<"soustraction ok"<<endl;
	}
	else
		cout<<"La matrice ne peux pas etre soustraite car différence de taille"<<endl;
}
void Matrice::multiplication(Matrice &matrice) // faite par Alex et Dylan
{
	if((this->n == matrice.n) && (this->m == matrice.m)) // les 2 matrices sont de même taille
	{
		// multiplication des deux matrices
		cout<<"multiplication ok"<<endl;
	}
	else
		cout<<"La matrice ne peux pas etre multipliée car différence de taille"<<endl;
}
void Matrice::division(Matrice &matrice)
{
	if((this->n == matrice.n) && (this->m == matrice.m)) // les 2 matrices sont de même taille
	{
		// division des deux matrices
		cout<<"division ok"<<endl;
	}
	else
		cout<<"La matrice ne peux pas etre divisée car différence de taille"<<endl;
}
void Matrice::division(int constante)
{
	cout<<"Division de la matrice par une constante de valeur "<<constante<<endl;
}
void Matrice::factorisation()
{
	if(this->n == this->m) // matrice carré
	{
		cout<<"factorisation autorisé"<<endl;
		this->afficher();
	}
	else
		cout<<"Cas non traité pour le moment"<<endl;
}
void Matrice::afficher()
{
	int val;
	cout<<"Voici la matrice"<<endl;
	// affichage sous forme d'une matrice
	cout<<"   ";
	for(int j = 0; j < this->n; j++) // affichage du numéro des colonnes (même index j pour s'en rapeler)
		cout<<j<<" ";
	cout<<endl;
	for(int i = 0; i < this->m; i++)
	{
		cout<<i<<" |";
		for(int j = 0; j < this->n; j++)
		{
			val = this->getValeur(i, j); // récupération de la case actuelle
			if(val != -1) // si ce n'est pas une case vide
				cout<<val<<" "; // alors on affiche la valeur
			else
				cout<<"  ";
		}
		cout<<endl;
	}
}
// Méthodes privées
int Matrice::charToInt(char caractere) // conversion char -> int
{
	int valeur;
	valeur = caractere - '0';
	return valeur;
}
int Matrice::charToInt(char * caractere) // conversion char * -> int (surcharge de la méthode)
{
	int valeur;
	valeur = atoi(caractere);
	return valeur;
}
int Matrice::stringToInt(string caractere) // conversion string -> int
{
	int valeur;
	valeur = atoi(caractere.c_str());
	return valeur;
}
bool Matrice::creuse() // détermine si la matrice est creuse ou non
{
	bool creuse = false;
	float nbre = this->tailleFichier; // nombre de cases occupés, stocké dans un float pour division
	float maxi = this->max; // nombre total de case, stocké dans un float pour division
	float pc = nbre / maxi;
	pc *= 100;
	pc = 4; // tmp, pour essai de l'algo de comptage de case par colonne
	if(pc < 5)
	{
		// calcul du nombre de case occupé par colonne (il faut au moins 1 case / colonne)
		for(int i = 0; i < this->n; i++)
		{
			if(this->tabY[i] == "y")
			{
				creuse = true;
			}
		}
	}
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
int Matrice::getValeur(int x, int y)
{
	int val = -1;
	int i = 0;
	string X, Y;
	// conversion int -> string
	ostringstream oss;
	oss << x;
	X = oss.str();
	oss.str(""); // effacement du flux pour traiter y
	oss << y;
	Y = oss.str();
	while(i <= (this->tailleFichier - 2))
	{
		if((this->tabX[i] == X) && (this->tabY[i] == Y)) // si les deux cases correspondent
			val = this->tabVal[i]; // récupération de la valeur
		i++;
	}
	return val;
}
// Destructeur
Matrice::~Matrice()
{
	// dtor
}
