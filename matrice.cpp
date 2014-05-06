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
	n = 3; /** Valeurs temporaires */
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
