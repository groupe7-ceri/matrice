/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome (CdP) - Dylan Hernandez - Alexandre Tarbis
MAJ : 20 mai 2014
Fichier matrice.cpp
Implémentation des méthodes de la classe Matrice */

#include "matrice.h"

using namespace std;

// Constructeurs

/* Constructeur Matrice(int, int)
 * Construit une matrice vide de n par m éléments
 * Sert aux méthodes de calcul pour créer des matrices de stockage temporaire.
*/
Matrice::Matrice(int n, int m) // constructeur matrice vide
{
	this->n = n;
	this->m = m;
	this->max = this->n * this->m;
	this->tailleFichier = this->max; // peut contenir toutes les valeurs
	// Initialisation des trois tableaux de données
	tabX = new string[this->tailleFichier - 1]; // tailleFichier - 1 car on commence à la 2eme ligne
	tabY = new string[this->tailleFichier - 1];
	tabVal = new int[this->tailleFichier - 1];
	for(int i = 0; i < (this->tailleFichier - 1); i++) // valeurs par défaut
	{
		this->tabX[i] = "x";
		this->tabY[i] = "y";
		this->tabVal[i] = 0;
	}
}
/* Constructeur Matrice(string)
 * Construit une matrice à partir d'un fichier texte au format Matrice
*/
Matrice::Matrice(string nomFichier) // construit une matrice à partir d'un fichier
{
	int j = 0;
	int separateur = 6; // position du séparateur (par défaut, il est sur le caractère 6)
	int c1 = -1, c2 = -1;
	// initialisation des attributs de la classe
	this->tailleFichier = 0;
	this->n = -1;
	this->m = -1;
	this->max = -1;
	cout<<"Matrice initialisée avec le fichier "<<nomFichier<<endl;
	// Lecture le fichier
	ifstream fichier(nomFichier.c_str()); // ouverture du fichier (parametre en const char * donc conversion
	if((fichier != NULL) && (fichier)) // si le fichier existe (non NULL) et non vide
	{
		// lecture de la taille de la matrice (première ligne)
		string taille, ligne, N = "", M = "";
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
		int j = posEgal + 1;
		while(taille[j] != '-')
		{
			N += taille[j]; // concatène les chiffres de n
			j++;
		}
		int posTiret = j;
		this->n = this->stringToInt(N); // conversion string => int via méthode perso
		// lecture de m
		int k = posTiret + 1;
		while(taille[k] != '\0')
		{
			M += taille[k]; // concatène les chiffres de n
			k++;
		}
		this->m = this->stringToInt(M); // conversion string => int via méthode perso
		this->max = this->n * this->m; // calcul du nombre de valeurs maximale
		// comptage du nombre de ligne du fichier
		while(getline(fichier, ligne))
			this->tailleFichier++;
		if(this->tailleFichier == 0) 
		{
			cout<<"Erreur de lecture du fichier, arret du programme"<<endl;
			exit(4); // arret du programme
		}
		// Initialisation des trois tableaux
		tabX = new string[this->tailleFichier - 1]; // tailleFichier - 1 car on commence à la 2eme ligne (la première est size=XX-XX)
		tabY = new string[this->tailleFichier - 1];
		tabVal = new int[this->tailleFichier - 1];
		for(int i = 0; i < (this->tailleFichier - 1); i++) // valeurs par défaut
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
				valeur = this->stringToInt(tmp); // conversion string => int
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
/* Constructeur Matrice(Matrice &)
 * Permet de recopier un objet de type Matrice
 * Utilisé pour les sauvegardes d'objets
 * La matrice est passée par référence
*/
Matrice::Matrice(Matrice &matrice)
{
	this->n = matrice.n;
	this->m = matrice.m;
	this->max = matrice.max;
	this->tailleFichier = matrice.tailleFichier;
	// Initialisation des trois tableaux
	tabX = new string[tailleFichier - 1]; // tailleFichier - 1 car on commence à la 2eme ligne
	tabY = new string[tailleFichier - 1];
	tabVal = new int[tailleFichier - 1];
	for(int i = 0; i < (tailleFichier - 1); i++) // valeurs par défaut
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
	cout<<"Matrice recopiée :"<<endl;
	this->afficher();
}
// Méthodes publiques
/* Méthode publique addition de deux matrices
 * Paramètre : référence de la matrice avec laquelle la matrice actuelle est additionnée. 
 * Résultat : matrice actuelle = matrice actuelle + matrice passée en référence
 * */
void Matrice::addition(Matrice &matrice) // faite par Alex et Dylan - développement en cours
{
	if((this->n == matrice.n) && (this->m == matrice.m)) // les 2 matrices sont de même taille
	{
		// addition des deux matrices
	}
	else
		cout<<"La matrice ne peux pas etre additionnée car différence de taille"<<endl;
}
/* Méthode publique soustraction de deux matrices
 * Paramètre : référence de la matrice avec laquelle la matrice actuelle est soustraite. 
 * Résultat : matrice actuelle = matrice actuelle - matrice passée en référence
 * */
void Matrice::soustraction(Matrice &matrice) // faite par Alex et Dylan - développement en cours
{
	if((this->n == matrice.n) && (this->m == matrice.m)) // les 2 matrices sont de même taille
	{
		// soustraction des deux matrices
	}
	else
		cout<<"La matrice ne peux pas etre soustraite car différence de taille"<<endl;
}
/* Méthode publique multiplication de deux matrices
 * Paramètre : référence de la matrice avec laquelle la matrice actuelle est multipliée. 
 * Résultat : matrice actuelle = matrice actuelle * matrice passée en référence
 * */
void Matrice::multiplication(Matrice &matrice) // faite par Alex et Dylan - développement en cours
{
	if((this->n == matrice.n) && (this->m == matrice.m)) // les 2 matrices sont de même taille
	{
		// multiplication des deux matrices
		cout<<"multiplication ok"<<endl;
	}
	else
		cout<<"La matrice ne peux pas etre multipliée car différence de taille"<<endl;
}
/* Méthode publique multiplication de la matrice par une constante
 * Paramètre : constante (entier) avec laquelle la matrice actuelle est multipliée. 
 * Résultat : matrice actuelle = matrice actuelle * constante
 * */
void Matrice::multiplication(int constante) // fini
{
	cout<<"multiplication de la matrice par la constante "<<constante<<endl;
	for(int i = 0; i < (this->tailleFichier - 1); i++)
		this->tabVal[i] *= constante;
}
/* Méthode publique division de deux matrices
 * Paramètre : référence de la matrice avec laquelle la matrice actuelle est divisée. 
 * Résultat : matrice actuelle = matrice actuelle / matrice passée en référence
 * */
void Matrice::division(Matrice &matrice)
{
	if((this->n == matrice.n) && (this->m == matrice.m)) // les 2 matrices sont de même taille
	{
		// division des deux matrices
	}
	else
		cout<<"La matrice ne peux pas etre divisée car différence de taille"<<endl;
}
/* Méthode publique division de la matrice par une constante
 * Paramètre : constante (entier) avec laquelle la matrice actuelle est divisée. 
 * Résultat : matrice actuelle = matrice actuelle / constante
 * */
void Matrice::division(int constante) // fini
{
	cout<<"Division de la matrice par une constante de valeur "<<constante<<endl;
	for(int i = 0; i < (this->tailleFichier - 1); i++)
		this->tabVal[i] /= constante;
}
/* Méthode publique factorisation de la matrice
 * Permet de factoriser la matrice actuelle
 * Paramètre : aucun
 * Résultat : matrice actuelle factorisée
 * */
void Matrice::factorisation()
{
	if(this->estCarre()) // matrice carré
	{
		// factorisation
	}
	else
		cout<<"Cas non traité pour le moment"<<endl;
}
/* Méthode publique inverse de la matrice
 * Permet d'inverser la matrice actuelle
 * Paramètre : aucun
 * Résultat : matrice actuelle factorisée
 * */
void Matrice::inverse()
{
	if(this->estCarre()) // matrice carré
	{
	}
}
/* Méthode publique transposée de la matrice
 * Permet d'effectuer la matrice actuelle
 * Paramètre : aucun
 * Résultat : matrice actuelle transposée
 * */
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
		// recopie dans la matrice d'origine
		for(int i = 0; i < t.getTaille(true); i++) // getTaille(true) renvoi le nombre réel de cases occupées
		{
			this->tabX[i] = t.getX(i);
			this->tabY[i] = t.getY(i);
			this->tabVal[i] = t.getVal(i);
		}
		cout<<"La matrice a été transposée"<<endl;
	}
}
/* Méthode publique affichage de la matrice
 * Permet d'afficher la matrice actuelle
 * Paramètre : aucun
 * */
void Matrice::afficher() // fini
{
	int val;
	cout<<"Voici la matrice"<<endl<<"   ";
	for(int j = 0; j < this->n; j++) // affichage du numéro des colonnes (même index j pour s'en rapeler)
		cout<<(j + 1)<<" ";
	cout<<endl;
	for(int i = 0; i < this->m; i++)
	{
		int l = i + 1; // permet d'afficher dynamiquement le nombre de lignes
		if(l < 10)
			cout<<l<<" |";
		else
			cout<<l<<"|";
		for(int j = 0; j < this->n; j++)
		{
			val = this->getValeur(i, j); // récupération de la case actuelle
			if(val != 0) // si ce n'est pas une case vide
				cout<<val<<" "; // alors on affiche la valeur
			else
				cout<<"  ";
		}
		cout<<endl;
	}
}
/* Méthode publique calcul du déterminant de la matrice
 * Permet de calculer le déterminant de la matrice actuelle
 * Paramètre : booléen indiquant si la méthode a été appelé par récursivité
 * Retourne le déterminant de la matrice
 * */
int Matrice::determinant(bool recursif) // méthode en cours de développement
{
	int det = 0;
	if(recursif) // la méthode a déja été appelé en récursif
	{
		cout<<"récursif"<<endl; // temporaire
		if((this->n == 2) && (this->m == 2))
		{
			cout<<"2x2"<<endl; // temporaire
			int a = this->getValeur(0, 0);
			int b = this->getValeur(0, 1);
			int c = this->getValeur(1, 0);
			int d = this->getValeur(1, 1);
			det = (a * d) - (b * c);
			return det;
		}
		else
		{
			cout<<"récursivité"<<endl; // temporaire
			this->n--;
			this->m--;
			int valeurDet = this->determinant(true);
			return valeurDet;
		}
	}
	else
	{
		if((this->n == 2) && (this->m == 2)) // si la matrice est déjà 2 x 2
		{
			// calcul déterminant
		}
		else
		{ 
			// extraction de la première ligne de la matrice
			int i = 0;
			while(this->tabX[i] == "0") // tant qu'on est sur la colonne 0
			{
				cout<<"["<<this->tabX[i]<<"]["<<this->tabY[i]<<"] : "<<this->tabVal[i]<<endl; // temporaire
				i++;
			}
			int *premiereLigne = new int[i]; // sauvegarde les valeurs de la première ligne
			 // lecture des colonnes
			int valeurDet = this->determinant(true);
		}
	}
	return det;
}
/* Méthode publique sauvegarde de la matrice actuelle
 * Permet de sauvegarder la matrice actuelle au format Matrice dans un fichier texte
 * Paramètre : nom (string) du fichier texte
 * */
void Matrice::sauvegarde(string nom)
{
	string X, Y;
	int valeur;
	ofstream fichier(nom.c_str(), ios::out | ios::trunc); // on efface le fichier et on le recrée
	if((fichier != NULL) && (fichier)) // le fichier existe et a bien été ouvert
	{
		fichier<<"size="<<this->n<<"-"<<this->m<<endl; // écriture de la taille de la matrice (n x m=
		for(int i = 0; i < (this->tailleFichier - 1); i++)
		{
			X = this->tabX[i]; // lecture de la valeur X (ligne)
			Y = this->tabY[i]; // lecture de la valeur Y (colonne)
			valeur = this->tabVal[i];
			fichier<<X<<" "<<Y<<" "<<valeur<<endl;
		}
		fichier.close(); // fermeture du fichier
		cout<<"Matrice sauvegardée dans le fichier "<<nom<<endl;
	}
	else
		cout<<"Erreur dans l'ouverture du fichier, la matrice n'a pas été sauvegardée"<<endl;
}
// Méthodes privées
/* Méthode privée conversion de char en int
 * Permet de convertir un caractère au format char en int
 * Paramètre : caractère à convertir (char)
 * Retourne l'entier converti
 * */
int Matrice::charToInt(char caractere) 
{
	int valeur;
	valeur = caractere - '0';
	return valeur;
}
/* Méthode privée conversion de char * en int (surcharge de la méthode)
 * Permet de convertir un caractère au format char * en int
 * Paramètre : caractère à convertir (char *)
 * Retourne l'entier converti
 * */
int Matrice::charToInt(char * caractere) 
{
	int valeur;
	valeur = atoi(caractere);
	return valeur;
}
/* Méthode privée conversion de string en int
 * Permet de convertir un caractère au format string en int
 * Paramètre : caractère à convertir (string)
 * Retourne l'entier converti
 * */
int Matrice::stringToInt(string caractere)
{
	int valeur;
	valeur = atoi(caractere.c_str());
	return valeur;
}
/* Méthode privée conversion de int en string
 * Permet de convertir un entier en chaine de caractère string
 * Paramètre : entier à convertir (int)
 * Retourne le caractère correspondant au format string
 * */
string Matrice::intToString(int valeur)
{
	string caractere;
	ostringstream oss;
	oss << valeur;
	caractere = oss.str();
	return caractere;
}
/* Méthode privée matrice creuse
 * Détermine si la matrice actuelle est creuse ou non
 * Paramètre : aucun
 * Retourne un booléen - creuse (true) - pleine (false)
 * */
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
		creuse = true;
		for(int i = 0; i < (this->tailleFichier - 1); i++)
		{
			if(this->tabY[i] == "y")
			{
				creuse = false;
			}
		}
	}
	return creuse;
}
/* Méthode privée matrice carrée
 * Détermine si la matrice actuelle est carrée ou non
 * Paramètre : aucun
 * Retourne un booléen - carrée (true) - autre (false)
 * */
bool Matrice::estCarre()
{
	if(this->n == this->m)
		return true;
	else
		return false;
}
// Setteurs privés
/* Méthode privée insertion d'une valeur avec ses coordonnées x et y
 * Permet d'insérer une valeur dans la matrice en fonction de ses coordonnées x et y
 * Paramètre : ligne x, colonne y et valeur de la case
 * */
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
		if(valeurCase == 0) // la case n'existe pas
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
// Getteurs privés
/* Méthode privée lecture de la valeur de la case [x][y]
 * Permet de lire la valeur de la case selon ses coordonnées x et y
 * Paramètre : ligne x et colonne y
 * Retourne la valeur de la case (entier)
 * */
int Matrice::getValeur(int x, int y)
{
	int val = 0;
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
/* Méthode privée lecture de la valeur X
 * Permet de lire la valeur du tableau X selon son index
 * Paramètre : index du tableau
 * Retourne la valeur X (string)
 * */
string Matrice::getX(int i)
{
	string x = this->tabX[i];
	return x;
}
/* Méthode privée lecture de la valeur Y
 * Permet de lire la valeur du tableau Y selon son index
 * Paramètre : index du tableau
 * Retourne la valeur Y (string)
 * */
string Matrice::getY(int i)
{
	string y = this->tabY[i];
	return y;
}
/* Méthode privée lecture de la valeur de la case
 * Permet de lire la valeur du tableau de valeur selon son index
 * Paramètre : index du tableau
 * Retourne la valeur de la case (int)
 * */
int Matrice::getVal(int i)
{
	int val = this->tabVal[i];
	return val;
}
/* Méthode privée lecture de la taille du tableau
 * Permet de connaitre la taille total de la matrice (via l'attribut tailleFichier) ou la taille réelle en comptant le nombre de cases occupées
 * Paramètre : booléen indiquant la taille demandée (true : taille de l'attribut - false : taille réelle)
 * Retourne la taille demandée (int)
 * */
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
/* Méthode privée lecture de l'attribut max
 * Permet de lire le nombre de cases maximum de la matrice
 * Paramètre : aucun
 * Retourne la valeur maximale (int)
 * */
int Matrice::getMax()
{
	return this->max;
}
// Destructeur
Matrice::~Matrice()
{
	// dtor
}
