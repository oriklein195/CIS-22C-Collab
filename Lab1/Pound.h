#include "Currency.h"
using namespace std;
#ifndef POUND_H
#define POUND_H

class Pound : public Currency{
public:
	Pound(){
		Currency();
		wholeName = "Pounds";
		fracName = "Pence";
	}
	Pound(int w, int f){
		Currency(w, f);
		wholeName = "Pounds";
		fracName = "Pence";
	}
};
#endif /* DOLLAR_H */