#include "Currency.h"
using namespace std;
#ifndef POUND_H
#define POUND_H
/**
 * Creates a Pound class that is derived from Currency.
 */
class Pound : public Currency{
public:
	Pound() :Currency(){
		wholeName = 'P';
		fracName = 'p';
	}
	Pound(int w, int f) :Currency(w, f){
		wholeName = 'P';
		fracName = 'p';
	}
};
#endif /* DOLLAR_H */
