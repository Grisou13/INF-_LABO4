#include <stdexcept>
#include <string>

#ifndef EXCEPTION_H
#define EXCEPTION_H

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