/*
 -------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collection_g.h
 Auteur(s)   : Fabio Marques, Thomas Ricci, Vitor Vaz Afonso
 Date        : 08.04.2019

 But         : Definition et implémentation de la classe Collection

 Remarque(s) : -

 Compilateur : MinGW-g++ 6.3.0
               gcc (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609
 -------------------------------------------------------------------------------
*/
#ifndef COLLECTION_G_H
#define COLLECTION_G_H

#include <iostream>
#include <algorithm>
#include "exceptions.h"
#include "produit.h"

template<	
	typename T, 
	template <class, class = std::allocator<T>> class CONTENEUR 
>
class Collection;

template<	
	typename T, 
	template <class, class = std::allocator<T>> class CONTENEUR 
>
std::ostream& operator<< (std::ostream& out, const Collection<T, CONTENEUR>& c){
	out << "[";
	for(auto i = c.data.begin(); i != c.data.end(); ++i){
		out << *i;
		if(distance(i, c.data.end()) > 1)
			out << ", ";
	}
	out << "]";
	return out;
}

/**
 * 
 * Utilisable seulement par des conteneurs implémentant:
 * - les fonctions:
 *   - push_back
 *   - clear
 *   - begin
 *   - end
 */
template<	
	typename T, 
	template <class, class = std::allocator<T>> class CONTENEUR 
>
class Collection{
public:
	Collection();
	T& get(size_t indice);
	void ajouter(T elem);
	size_t taille();
	bool contient(const T& elem);
	void vider();
	template <typename Fn> void parcourir(Fn p);
	friend std::ostream& operator<< <>(
		std::ostream& out, const Collection<T, CONTENEUR>& p);
private:
	CONTENEUR<T> data;
	size_t _taille;
};

template<	
	typename T, 
	template <class, class = std::allocator<T>> class CONTENEUR 
>
Collection<T, CONTENEUR>::Collection(): _taille(0){}

template<	
	typename T, 
	template <class, class = std::allocator<T>> class CONTENEUR 
>
void Collection<T, CONTENEUR>::ajouter(T elem){
	data.push_back(elem);
	_taille++;
}

template<	
	typename T, 
	template <class, class = std::allocator<T>> class CONTENEUR 
>
T& Collection<T,CONTENEUR>::get(size_t indice){
	if(indice >= _taille){
		throw IndiceNonValide(
			"Erreur dans Collection::get : \n"
			"n doit etre strictement plus petit que collection.size()"
		);
	}
	auto i = data.begin();
	for(size_t x = 0; x < indice; ++x, ++i); //augmente i jusqu'à indice
	return *i;
}

template<	
	typename T, 
	template <class, class = std::allocator<T>> class CONTENEUR 
>
bool Collection<T,CONTENEUR>::contient(const T& elem){
	for(auto i = data.begin(); i != data.end(); ++i){
		if(*i == elem){
			return true;
		}
	}
	return false;
}

template<	
	typename T, 
	template <class, class = std::allocator<T>> class CONTENEUR 
>
size_t Collection<T,CONTENEUR>::taille(){
	return _taille;
}

template<	
	typename T, 
	template <class, class = std::allocator<T>> class CONTENEUR 
>
template<typename Fn>
void Collection<T,CONTENEUR>::parcourir(Fn p){
	for(auto i = data.begin(); i != data.end(); ++i){
		p(*i);
	}
}

template<	
	typename T, 
	template <class, class = std::allocator<T>> class CONTENEUR 
>
void Collection<T,CONTENEUR>::vider(){
	data.clear();
	_taille = 0;
}

#endif