#include <stdexcept>

#ifndef EXCEPTION_H
#define EXCEPTION_H

class IndiceNonValide: public out_of_range {};
class PrixNonValide : public invalid_argument {};
#endif