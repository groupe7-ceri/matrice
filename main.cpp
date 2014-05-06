/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
MAJ : 11 avril 2014
Fichier main.cpp
Fichier principal - Pour essai de la librairie durant son développement */

#ifndef __MAIN__
#define __MAIN__

#include "matrice.h"

using namespace std;

int main(void)
{
	cout<<"---- Projet GLOG Matrice ----"<<endl;
	cout<<"Programme de test de la librairie"<<endl;
	cout<<"Pour info, le nom du fichier est : matrix.txt"<<endl;
	Matrice m1("matrix.txt");
	m1.afficher();
	return 0;
}
#endif
