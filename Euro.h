#include "Currency.h"
using namespace std;
#ifndef EURO_H
#define EURO_H
/**
 * Creates a Euro class that is derived from Currency.
 */
class Euro : public Currency{
public:
	Euro() :Currency(){
		wholeName = 'E';
		fracName = 'c';
	}
	Euro(int w, int f) :Currency(w, f){
		wholeName = 'E';
		fracName = 'c';
	}
};
#endif /* DOLLAR_H */
