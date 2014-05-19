/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
MAJ : 13 mai 2014
Fichier matrice.cpp
Implémentation des méthodes de la classe Matrice */

#include "matrice.h"

using namespace std;

// Constructeurs
Matrice::Matrice(int n, int m) // constructeur matrice vide
{
	this->n = n;
	this->m = m;
	this->max = this->n * this->m;
	this->tailleFichier = this->max; // peut contenir toutes les valeurs
	// Initialisation des trois tableaux
	tabX = new string[this->tailleFichier - 1]; // tailleFichier - 1 car on commence à la 2eme ligne
	tabY = new string[this->tailleFichier - 1];
	tabVal = new int[this->tailleFichier - 1];
	for(int i = 0; i < (this->tailleFichier - 1); i++)
	{
		this->tabX[i] = "x";
		this->tabY[i] = "y";
		this->tabVal[i] = 0;
	}
}
Matrice::Matrice(string nomFichier) // construit une matrice à partir d'un fichier
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
		int tailleChaine = taille.length();
		int posEgal;
		for(int i = 0; i < tailleChaine; i++)
		{
			if(taille[i] == '=')
			{
				posEgal = i; // sauvegarde de la position du signe =
				break;
			}
		}
		// lecture de n
		string N = "";
		int j = posEgal + 1;
		while(taille[j] != '-')
		{
			N += taille[j]; // concatene les chiffres
			j++;
		}
		int posTiret = j;
		this->n = this->stringToInt(N);
		// lecture de m
		string M = "";
		int k = posTiret + 1;
		while(taille[k] != '\0')
		{
			M += taille[k]; // concatene les chiffres
			k++;
		}
		this->m = this->stringToInt(M);
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
		tabX = new string[this->tailleFichier - 1]; // tailleFichier - 1 car on commence à la 2eme ligne
		tabY = new string[this->tailleFichier - 1];
		tabVal = new int[this->tailleFichier - 1];
		for(int i = 0; i < (this->tailleFichier - 1); i++)
		{
			this->tabX[i] = "x";
			this->tabY[i] = "y";
			this->tabVal[i] = 0;
		}
		fichier.clear(); // retour au début du fichier
		fichier.seekg(0, ios::beg);
		// Lecture des lignes et stockage dans les trois tableaux
		int i = 0;
		j = 0;
		int pos = 0; // position dans les tableaux
		string X = "", Y = "", tmp = ""; // tmp stocke la valeur de la case au format string, avant conversion en int
		int valeur;
		while(getline(fichier, ligne))
		{
			if(ligne.find("size=", 0) != 0) // la 1e ligne (contenant size=) n'est pas lu
			{
				X = ""; // réinitialisation des index i et j et des variables X, Y et tmp
				Y = "";
				tmp = "";
				i = 0;
				j = 0;
				// lecture de X
				while(ligne[i] != ' ')
				{
					X += ligne[i];
					i++;
				}
				// lecture de Y
				int j = i + 1; // déplacement de l'index
				while(ligne[j] != ' ')
				{
					Y += ligne[j];
					j++;
				}
				// lecture de la valeur
				int k = j + 1; // déplacement de l'index
				while(ligne[k] != '\0')
				{
					tmp += ligne[k];
					k++;
				}
				valeur = this->stringToInt(tmp);
				// stockage
				this->tabX[pos] = X;
				this->tabY[pos] = Y;
				this->tabVal[pos] = valeur;
				pos++;
			}
			
		}
		fichier.close(); // Fermeture du fichier
	}
	// récapitulatif
	cout<<"Matrice créée :"<<endl;
	cout<<" - n : "<<this->n<<endl;
	cout<<" - m : "<<this->m<<endl;
	cout<<"Type : ";
	if(this->creuse())
		cout<<"creuse"<<endl;
	else
		cout<<"pleine"<<endl;
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
	cout<<"Matrice copiée :"<<endl;
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
void Matrice::multiplication(int constante) // fini
{
	cout<<"multiplication de la matrice par la constante "<<constante<<endl;
	for(int i = 0; i < (this->tailleFichier - 1); i++)
	{
		this->tabVal[i] *= constante;
	}
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
void Matrice::division(int constante) // fini
{
	cout<<"Division de la matrice par une constante de valeur "<<constante<<endl;
	for(int i = 0; i < (this->tailleFichier - 1); i++)
	{
		this->tabVal[i] /= constante;
	}
}
void Matrice::factorisation()
{
	if(this->estCarre()) // matrice carré
	{
		cout<<"factorisation autorisé"<<endl;
	}
	else
		cout<<"Cas non traité pour le moment"<<endl;
}
void Matrice::inverse()
{
	if(this->estCarre()) // matrice carré
	{
	}
}
void Matrice::transposee() // fini
{
	if(this->estCarre()) // matrice carré
	{
		Matrice t(this->n, this->m); // création d'une matrice vide temporaire de taille n x m
		for(int i = 0; i < this->m; i++)
		{
			for(int j = 0; j < this->n; j++)
			{
				int val = this->getValeur(i, j); // récupère la valeur de la case [i][j]
				t.setValeur(j, i, val); // stocke la valeur de la case [j][i] dans la matrice temporaire
			}
		}
		/*for(int i = 0; i < (t.getMax() - 1); i++) // décommenter pour débug
		{
			cout<<t.getX(i)<<"_"<<t.getY(i)<<"_"<<t.getVal(i)<<endl;
		}//*/
		// recopie dans la matrice d'origine
		for(int i = 0; i < t.getTaille(true); i++) // getTaille(true) renvoi le nombre réel de cases occupées
		{
			this->tabX[i] = t.getX(i);
			this->tabY[i] = t.getY(i);
			this->tabVal[i] = t.getVal(i);
		}
		cout<<"La matrice a été transposée"<<endl;
	}
	else
		cout<<"Cas non traité pour le moment"<<endl;
}
void Matrice::afficher() // fini
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
int Matrice::determinant()
{
	return 0;
}
void Matrice::sauvegarde(string nom)
{
	string X, Y;
	int valeur;
	ofstream fichier(nom.c_str(), ios::out | ios::trunc); // on efface le fichier et on le recrée
	if((fichier != NULL) && (fichier)) // le fichier existe et a bien été ouvert
	{
		fichier<<"size="<<this->n<<"-"<<this->m<<endl;
		for(int i = 0; i < (this->tailleFichier - 1); i++)
		{
			X = this->tabX[i];
			Y = this->tabY[i];
			valeur = this->tabVal[i];
			fichier<<X<<"_"<<Y<<"_"<<valeur<<endl;
		}
		fichier.close(); // fermeture du fichier
		cout<<"Matrice sauvegardée dans le fichier "<<nom<<endl;
	}
	else
		cout<<"Erreur dans l'ouverture du fichier, la matrice n'a pas été sauvegardée"<<endl;
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
string Matrice::intToString(int valeur)
{
	string caractere;
	ostringstream oss;
	oss << valeur;
	caractere = oss.str();
	return caractere;
}
bool Matrice::creuse() // détermine si la matrice est creuse ou non
{
	bool creuse = false;
	float nbre = this->tailleFichier; // nombre de cases occupés, stocké dans un float pour division
	float maxi = this->max; // nombre total de case, stocké dans un float pour division
	float pc = nbre / maxi;
	pc *= 100;
	if(pc < 5)
	{
		// calcul du nombre de case occupé par colonne (il faut au moins 1 case / colonne)
		for(int i = 0; i < (this->tailleFichier - 1); i++)
		{
			if(this->tabY[i] == "y")
			{
				creuse = true;
			}
		}
	}
	return creuse;
}
bool Matrice::estCarre()
{
	if(this->n == this->m)
		return true;
	else
		return false;
}
// Setteurs
void Matrice::setValeur(int x, int y, int valeur) // terminé
{
	int i = 0;
	int valeurCase = this->getValeur(x, y); // valeur de la case
	// protection "anti" dépassement de la grille
	if(x > this->n)
		x = (this->n - 1);
	if(y > this->m)
		y = (this->m - 1);
	string X = this->intToString(x); // conversion de la valeur x
	string Y = this->intToString(y); // conversion de la valeur y
	if((valeur != -1) && (valeur != 0)) // la valeur peut être stockée
	{
		int valeurCase = this->getValeur(x, y); // lis la valeur de la case
		//cout<<"insertion : "<<X<<"_"<<Y<<"_"<<valeur<<endl;
		if(valeurCase == -1) // la case n'existe pas
		{
			// crée la case
			//cout<<"insertion : "<<X<<"_"<<Y<<"_"<<valeur<<endl; // tmp
			while(i <= (this->tailleFichier - 1))
			{
				//cout<<"["<<this->tabX[i]<<"]["<<this->tabY[i]<<"] = "<<this->tabVal[i]<<endl;
				if((this->tabX[i] == "x") && (this->tabY[i] == "y")) // ligne i vide, les suivantes sont vide
				{
					this->tabX[i] = X;
					this->tabY[i] = Y;
					this->tabVal[i] = valeur;
					break;
				}
				i++;
			}
		}
		else // la case existe
		{
			// remplace la valeur
			int index = -1;
			while(i <= (this->tailleFichier - 2)) // recherche de l'index correspondant à X et Y
			{
				if((this->tabX[i] == X) && (this->tabY[i] == Y)) // si les deux cases correspondent
				{
					this->tabVal[i] = valeur;
				}
				i++;
			}

		}
	}
}
// Getteurs
int Matrice::getValeur(int x, int y)
{
	int val = -1;
	int i = 0;
	string X, Y;
	// conversion int -> string
	X = this->intToString(x);
	Y = this->intToString(y);
	while(i <= (this->tailleFichier - 2))
	{
		if((this->tabX[i] == X) && (this->tabY[i] == Y)) // si les deux cases correspondent
			val = this->tabVal[i]; // récupération de la valeur
		i++;
	}
	return val;
}
string Matrice::getX(int i)
{
	string x = this->tabX[i];
	return x;
}
string Matrice::getY(int i)
{
	string y = this->tabY[i];
	return y;
}
int Matrice::getVal(int i)
{
	int val = this->tabVal[i];
	return val;
}
int Matrice::getTaille(bool reel = false)
{
	if(!reel) // par défaut, retourne la taille du fichier
		return this->tailleFichier;
	else // compte réellement le nbre de cases
	{
		int nbre = 0;
		for(int i = 0; i < this->max; i++)
		{
			if((this->tabX[i] == "x") && (this->tabY[i] == "y") && (this->tabVal[i] == 0)) // ligne vide
			{
				nbre = i; // sauvegarde du compteur
				break; // sortie de la boucle
			}
		}
		return nbre; // nombre réel de cases occupées
	}
}
int Matrice::getMax()
{
	return this->max;
}
// Destructeur
Matrice::~Matrice()
{
	// dtor
}
