#include <iostream>
#include "produit.h"
#include <iomanip>
#include "exceptions.h"

Produit::Produit(unsigned id, const std::string& libelle, double prix) : id(id), libelle(libelle) {
   setPrix(prix);
}

void Produit::setPrix(double prix) {
   if (prix < 0.05) {
      throw PrixNonValide("le prix doit etre >= 5 cts !");
   }

   this->prix = prix;
}

std::ostream& operator<<(std::ostream& out, const Produit& p) {
   return out  << "("
               << p.id
               << ", \"" << p.libelle << "\""
               << ", " << std::fixed << std::setprecision(2) << p.prix
               << ")";
}

bool operator==(const Produit& lhs, const Produit& rhs) {
   return lhs.id == rhs.id && lhs.libelle == rhs.libelle && lhs.prix == rhs.prix;
}