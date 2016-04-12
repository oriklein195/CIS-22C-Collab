#include "Currency.h"
using namespace std;
#ifndef DOLLAR_H
#define DOLLAR_H

class Dollar : public Currency{
public:
	Dollar(){
		Currency();
		wholeName = "Dollars";
		fracName = "Cents";
	}
	Dollar(int w, int f){
		Currency(w, f);
		wholeName = "Dollars";
		fracName = "Cents";
	}
};
#endif /* DOLLAR_H */