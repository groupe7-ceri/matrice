/* Génie logiciel - Projet Matrice
L2 INFORMATIQUE - Groupe TP2
Auteur : Jérémie Décome - Dylan Hernandez - Alexandre Tarbis
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
	cout<<"Programme de test de la librairie"<<endl;
	//Matrice m1("matrix.txt"); // 3x3
	Matrice m2("matrice.txt"); // 7x7
	//Matrice m3("matrice3.txt"); // 3x3
	//m1.afficher();
	//m1.factorisation();
	//m2.afficher();
	m2.transposee();
	return 0;
}
#endif
