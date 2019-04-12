#ifndef PRODUIT_H
#define PRODUIT_H

#include <ostream>

class Produit{

friend std::ostream& operator<<(std::ostream& out, const Produit& p);
friend bool operator==(const Produit& lhs, const Produit& rhs);
public:
   Produit(unsigned id, const std::string& libelle, double prix);
   void setPrix(double prix);

private:
   unsigned id;
   std::string libelle;
   double prix;
};

#endif