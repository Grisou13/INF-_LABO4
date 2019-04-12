#include "produit.h"
#include "exceptions.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Produit::Produit(unsigned id, const string& libelle, double prix)
try : id(id), libelle(libelle) {
   setPrix(prix);
}catch(...){
   throw PrixNonValide("Erreur dans Produit::Produit : \n"
                       "le prix doit etre >= 5 cts !");
}

void Produit::setPrix(double prix) {
   if (prix < 0.05) {
      throw PrixNonValide("Erreur dans Produit::setPrix : \n"
                          "le prix doit etre >= 5 cts !");
   }

   this->prix = prix;
}
double Produit::getPrix() const{
   return prix;
}
ostream& operator<<(ostream& out, const Produit& p) {
   return out  << "("
               << p.id
               << ", \"" << p.libelle << "\""
               << ", " << fixed << setprecision(2) << p.prix
               << ")";
}

bool operator==(const Produit& lhs, const Produit& rhs) {
   return lhs.id == rhs.id && lhs.libelle == rhs.libelle && lhs.prix == rhs.prix;
}