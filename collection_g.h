#include <iostream>
#include "exceptions.h"
#include "produit.h"
#ifndef COLLECTION_G_H
#define COLLECTION_G_H

template<typename T, template <class, class = std::allocator<T>> class CONTENEUR >
class Collection;

template<typename T, template <class, class = std::allocator<T>> class CONTENEUR >
std::ostream& operator<< (std::ostream& out, const Collection<T, CONTENEUR>& p){
   out << "[";
   for(auto i = p.data.begin(); i != p.data.end(); ++i){
      out << *i;
      if(distance(i, p.data.end()) > 1)
         out << ", ";
   }
   out << "]";
   return out;
}

/**
 * 
 * Utilisable seulement par des conteneur implémentant std::allocator
 * 
 */
template<typename T, template <class, class = std::allocator<T>> class CONTENEUR >
class Collection{
   public:
      Collection();
      ~Collection() = default;
      T& get(size_t indice);
      void ajouter(T elem);
      size_t taille();
      bool contient(const T& elem);
      void vider();
      template <typename Predicat> void parcourir(Predicat p);
      friend std::ostream& operator<< <>(std::ostream& out, const Collection<T, CONTENEUR>& p);
   private:
      CONTENEUR<T> data;
      size_t _taille;
};

template<typename T, template <class, class = std::allocator<T>> class CONTENEUR >
Collection<T, CONTENEUR>::Collection(): _taille(0){

}




template<typename T, template <class, class = std::allocator<T>> class CONTENEUR >
void Collection<T, CONTENEUR>::ajouter(T elem){
   data.push_back(elem);
   //data[_taille] = elem;
   _taille++;
}

template<typename T, template <class, class = std::allocator<T>> class CONTENEUR >
T& Collection<T,CONTENEUR>::get(size_t indice){
   if(indice >= _taille){
      throw IndiceNonValide("n doit etre strictement plus petit que collection.size()");
   }
   auto i = data.begin();
   for(size_t x = 0; x < indice; ++x, ++i); //augmente i jusqu'à indice
   return *i;
}

template<typename T, template <class, class = std::allocator<T>> class CONTENEUR >
bool Collection<T,CONTENEUR>::contient(const T& elem){
   for(auto i = data.begin(); i != data.end(); ++i){
      if(*i == elem){
         return true;
      }
   }
   return false;
}

template<typename T, template <class, class = std::allocator<T>> class CONTENEUR >
size_t Collection<T,CONTENEUR>::taille(){
   return _taille;
}

template<typename T, template <class, class = std::allocator<T>> class CONTENEUR >
template<typename Fn>
void Collection<T,CONTENEUR>::parcourir(Fn p){
   for(auto i = data.begin(); i != data.end(); ++i){
      p(*i);
   }
}

template<typename T, template <class, class = std::allocator<T>> class CONTENEUR >
void Collection<T,CONTENEUR>::vider(){
   data.clear();
   _taille = 0;
}

// template <> Collection<char, std::vector>;
// template <> Collection<Produit, std::list>;
#endif