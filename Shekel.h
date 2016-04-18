#include "Currency.h"
using namespace std;
#ifndef SHEKEL_H
#define SHEKEL_H
/**
 * Creates a Shekel class that is derived from Currency.
 */
class Shekel : public Currency{
public:
	Shekel() :Currency(){
		wholeName = 'S';
		fracName = 'a';
	}
	Shekel(int w, int f) :Currency(w, f){
		wholeName = 'S';
		fracName = 'a';
	}
};
#endif /* DOLLAR_H */
