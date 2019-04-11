#include <iostream>
#include <iomanip>
#include "produit.h"

using namespace std;

std::ostream& operator<<(std::ostream& out, const Produit& p){
   out << "("<< p.id << ", " << p.libelle << ", " << fixed << setprecision(2) << p.prix << ")";
   return out;
}
bool operator==(const Produit& lhs, const Produit& rhs){
   return lhs.id == rhs.id;
}