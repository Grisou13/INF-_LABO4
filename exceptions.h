/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : exceptions.h
 Auteur(s)   : Fabio Marques, Thomas Ricci, Vitor Vaz Afonso
 Date        : 08.04.2019

 But         : Definition des exceptions personaliése

 Remarque(s) : -

 Compilateur : MinGW-g++ 6.3.0
               gcc (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609
 -----------------------------------------------------------------------------------
*/

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <string>

class IndiceNonValide: public std::out_of_range {
public :
   explicit IndiceNonValide(const std::string& what_arg) : std::out_of_range(what_arg) {}	
   explicit IndiceNonValide(const char* what_arg) : std::out_of_range(what_arg) {}	
};


class PrixNonValide : public std::invalid_argument {
public :
   explicit PrixNonValide(const std::string& what_arg) : std::invalid_argument(what_arg) {}	
   explicit PrixNonValide(const char* what_arg) : std::invalid_argument(what_arg) {}	
};
#endif