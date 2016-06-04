#include "Currency.h"
using namespace std;
#ifndef POUND_H
#define POUND_H

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