#include <iostream>

#ifndef COLLECTION_G_H
#define COLLECTION_G_H
/**
 * 
 * Utilisable seulement par des conteneur implémentant std::allocator
 * TODO: Utilisation avec array et tab[] ?
 */
template<typename T, template <typename> class CONTENEUR >
class Collection{
   public:
      Collection(): taille(0){};
      ~Collection() = default;
      T get(size_t indice);
      void ajouter(T elem);
      size_t taille();
      size_t size();
      bool contient(const T& elem);
      void vider();
      template <typename Predicat> void parcourir(Predicat p);
      friend std::ostream& operator<< <T>(std::ostream& out, const Collection<T>& p);
   private:
      CONTENEUR<T> data;
};

template<typename T, template <typename> class U >
void Collection<T, U>::ajouter(T elem){
   data[taille] = elem;
   taille++;
}

template<typename T, template <typename> class U >
T Collection<T,U>::get(size_t indice){
   if(indice >= taille){
      throw new IndiceNonValide("n doit etre strictement plus petit que collection.size()")
   }
   return *(data.begin()+indice);
}

template<typename T, template <typename> class U >
bool Collection<T,U>::contient(const T& elem){
   for(auto i = data.begin(); i != data.end(); ++i){
      if(*i == elem){
         return true;
      }
   }
   return false;
}

template<typename T, template <typename> class U >
size_t Collection<T,U>::taille(){
   taille;
}

template<typename T, template <typename> class U >
size_t Collection<T,U>::size(){
   data.max_size();
}

template<typename T, template <typename> class U >
template<typename Predicat>
void Collection<T,U>::parcourir(Predicat p){
   for(auto i = data.begin(); i != data.end(); ++i){
      p(*i)
   }
}

template <> Collection<char, std::vector>

#endif