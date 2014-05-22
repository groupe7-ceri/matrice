/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome (CdP) - Dylan Hernandez - Alexandre Tarbis
MAJ : 13 mai 2014
Fichier main.cpp
Fichier principal - Pour essai de la librairie durant son développement */

#ifndef __MAIN__
#define __MAIN__

#include "matrice.h"

using namespace std;

int main(void)
{
	cout<<"---- Projet GLOG Matrice ----"<<endl;
	cout<<"Programme de test de la librairie Matrice"<<endl;
	Matrice m1("m4x4.txt"); // création d'une matrice 4 x 4
	Matrice saveM1(m1); // sauvegarde de la matrice m1
	m1.afficher();
	cout<<"Essai de la méthode de calcul du déterminant de la matrice m1"<<endl;
	int det = m1.determinant(false); // false pour indiquer à la méthode que ce n'est pas un appel récursif
	cout<<"Le déterminant est de : "<<det<<endl;
	return 0;
}
#endif
