#ifndef PRODUIT_H
#define PRODUIT_H

class Produit{
   Produit(unsigned id, std::string libelle, double prix);
   ~Produit();
   void setPrix(double prix);
   friend ostream& operator<<(ostream& out, const Produit& p);
   friend bool operator==(const Produit& lhs, const Produit& rhs);
};

#endif