#ifndef COLLECTION_G_H
#define COLLECTION_G_H
template<typename T, typename CONTENEUR >
class Collection{
   public:
      T get(size_T indice);
      void ajouter(T data);
      size_t taille;
      bool contient(T data);
      void vider();
      void parcourir(T& element);
      friend ostream& operator<<<T>(ostream& out, const Collection<T>& p);

};
#endif