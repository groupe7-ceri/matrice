<<<<<<< HEAD
/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
MAJ : 6 mai 2014
Fichier matrice.cpp
Implémentation des méthodes de la classe Matrice */
=======
/**
 * \file matrice.cpp
 * \brief Génie logiciel - Projet Matrice - L2 INFORMATIQUE - Groupe TP2
 * \author Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
 * \date 28 mars 2014
  *
 * \date MAJ 11 Avril 2014
 *
 * Implémentation des méthodes de la classe Matrice
*/
>>>>>>> 075c882961b5cc2e68b881959bf9153509d16d43

#include "matrice.h"

/** \namespace std */

using namespace std;

/**
 * \fn Matrice::Matrice (string nomFichier)
 * \brief Constructeur
 *
 * Ce constructeur appele un fichier.txt et récupère les données qu'il contient
 * afin de créer une matrice composer de trois tableau
 * Le premier tableau tabX contient le numéro de la colonne de la matrice
 * Le deuxième tableau tabY contient le numéro de la ligne de la matrice
 * Le troisième tableau tabVal contient le valeur correspondant à la case de la matrice définie par les
 * deux premiers tableaux
 *
 * \param nomFichier  Nom du fichier que le constructeur doit ouvrir
 *
 */
Matrice::Matrice(string nomFichier)
{
<<<<<<< HEAD
=======
	n = 3; /** Valeurs temporaires */
	m = 3;
	int tailleFichier = 0; // compteur du nombre de ligne
>>>>>>> 075c882961b5cc2e68b881959bf9153509d16d43
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
<<<<<<< HEAD
void Matrice::addition(Matrice &matrice)
=======

/**
 * \fn Matrice::addition (Matrice &matrice)
 * \brief Addition
 *
 * Fonction permettant l'addition de 2 matrices
 *
 * \param Une matrice
 *
 */

void Matrice::addition(Matrice &matrice)
{
    int i=0;
    while (i < (tailleFichier - 1))
    {
        if(tabX[i] == matrice->tabX[i] && tabY[i] == matrice->tabY[i])
        {
            if(tabVal[i] == 0)
            {
                if(matrice->tabVal[i] == 0) i++;
                else
                {
                    tabVal[i] = matrice->tabVal[i];
                    i++
                }
            }
            else
            {
                if(matrice->tabVal[i] == 0) i++;
                else
                {
                    tabVal[i] = tabVal[i] + matrice->tabVal[i];
                    i++;
                }
            }
        }
        else
        {
			if(tabX[i] == matrice->tabX[i])
			{
				if(tabY[i] < matrice->tabY[i])
				{
					insertion(tabX[i],tabY[i],tabVal[i],i);
					i++;
				}
				else
				{
					insertion(tabX[i],tabY[i],tabVal[i],i+1);
					i++;
				}
			}
			else if(tabX[i] < matrice->tabX[i])
			{
				insertion(tabX[i],tabY[i],tabVal[i],i);
				i++;
			}
			else if(tabX[i] < matrice->tabX[i])
			{
				insertion(tabX[i],tabY[i],tabVal[i],i+1);
				i++;
			}
        }
    }
}

/**
 * \fn Matrice::soustraction (Matrice &matrice)
 * \brief Soustraction
 *
 * Fonction permettant la soustraction de 2 matrices
 *
 * \param Une matrice
 *
 */

void Matrice::soustraction(Matrice &matrice)
>>>>>>> 075c882961b5cc2e68b881959bf9153509d16d43
{
    int i=0;
    while (i < (tailleFichier - 1))
    {
        if(tabX[i] == matrice->tabX[i] && tabY[i] == matrice->tabY[i])
        {
            if(tabVal[i] == 0)
            {
                if(matrice->tabVal[i] == 0) i++;
                else
                {
                    tabVal[i] = tabVal[i] - matrice->tabVal[i];
                    i++
                }
            }
            else
            {
                if(matrice->tabVal[i] == 0) i++;
                else
                {
                    tabVal[i] = tabVal[i] - matrice->tabVal[i];
                    i++;
                }
            }
        }
        else
        {
			if(tabX[i] == matrice->tabX[i])
			{
				if(tabY[i] < matrice->tabY[i])
				{
                    tabVal[i] = tabVal[i] - matrice->tabVal[i];
					insertion(tabX[i],tabY[i],tabVal[i],i);
					i++;
				}
				else
				{
                    tabVal[i] = tabVal[i] - matrice->tabVal[i];
					insertion(tabX,tabY,tabVal,i+1);
					i++;
				}
			}
			else if(tabX[i] < matrice->tabX[i])
			{
                tabVal[i] = tabVal[i] - matrice->tabVal[i];
				insertion(tabX,tabY,tabVal,i);
				i++;
			}
			else if(tabX[i] < matrice->tabX[i])
			{
                tabVal[i] = tabVal[i] - matrice->tabVal[i];
				insertion(tabX,tabY,tabVal,i+1);
				i++;
			}
        }
    }
}
<<<<<<< HEAD
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
=======

void Matrice::multiplication(Matrice &matrice)
{
}

void Matrice::division(Matrice &matrice)
{
}

void Matrice::factorisation()
{
}

/**
 * \fn Matrice::Insretion (string *tab1,string *tab2,int *tab3,int i)
 * \brief Insretion
 *
 * Fonction permettant la soustraction de 2 matrices
 *
 * \param 2 chaîne de caractère et duex entiers
 *
 */
Matrice Insertion(string s1,string s2,int s3,int i)
>>>>>>> 075c882961b5cc2e68b881959bf9153509d16d43
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
