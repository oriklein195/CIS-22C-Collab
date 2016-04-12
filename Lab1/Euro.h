#include "Currency.h"
using namespace std;
#ifndef EURO_H
#define EURO_H

class Euro : public Currency{
public:
	Euro(){
		Currency();
		wholeName = "Euros";
		fracName = "Euro Cents";
	}
	Euro(int w, int f){
		Currency(w, f);
		wholeName = "Euros";
		fracName = "Euro Cents";
	}
};
#endif /* DOLLAR_H */