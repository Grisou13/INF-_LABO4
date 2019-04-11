#include <iostream>
#include "exceptions.h"
#ifndef PRODUIT_H
#define PRODUIT_H

class Produit{
   public:
   Produit(unsigned id, std::string libelle, double prix) : id(id), libelle(libelle){
      setPrix(prix);
   };
   ~Produit() = default;
   void setPrix(double prix){
      if(!prixValid(prix))
         throw PrixNonValide("Le prix doit etre >= 0.05");
      this->prix = prix;
   };
   double getPrix(){
      return prix;
   };
   friend std::ostream& operator<<(std::ostream& out, const Produit& p);
   friend bool operator==(const Produit& lhs, const Produit& rhs);
   private:
      bool prixValid(double p){
         if(p >= 0.05)
            return true;
         return false;
      }
      unsigned id;
      std::string libelle;
      double prix;
};


#endif