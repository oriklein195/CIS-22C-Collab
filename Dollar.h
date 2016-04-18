#include "Currency.h"
using namespace std;
#ifndef DOLLAR_H
#define DOLLAR_H
/**
 * Creates a Dollar class that is derived from Currency.
 */
class Dollar : public Currency{
public:
	Dollar() :Currency(){
		wholeName = 'D';
		fracName = 'c';
	}
	Dollar(int w, int f) :Currency(w, f){
		wholeName = 'D';
		fracName = 'c';
	}
};
#endif /* DOLLAR_H */
