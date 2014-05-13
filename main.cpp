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
	//Matrice m2("matrice.txt"); // 7x7
	//Matrice m3("matrice3.txt"); // 3x3
	//m2.afficher();
	//m2.transposee();
	int max = 7;
	Matrice t(max, max);
	int val = 0;
	for(int i = 0; i < max; i++)
	{
		for(int j = 0; j < max; j++)
		{
			cout<<"["<<i<<"]["<<j<<"] : ";
			cin>>val;
			t.setValeur(i, j, val);
		}
	}
	t.afficher();
	return 0;
}
#endif
