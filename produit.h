/*
 -------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.h
 Auteur(s)   : Fabio Marques, Thomas Ricci, Vitor Vaz Afonso
 Date        : 08.04.2019

 But         : Definition de la classe produit

 Remarque(s) : -

 Compilateur : MinGW-g++ 6.3.0
               gcc (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609
 -------------------------------------------------------------------------------
*/
#ifndef PRODUIT_H
#define PRODUIT_H

#include <ostream>

class Produit{

friend std::ostream& operator<<(std::ostream& out, const Produit& p);
friend bool operator==(const Produit& lhs, const Produit& rhs);
public:
	Produit(unsigned id, const std::string& libelle, double prix);
	void setPrix(double prix);
	double getPrix() const;
private:
	unsigned id;
	std::string libelle;
	double prix;
};

#endif