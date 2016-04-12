#include "Currency.h"
using namespace std;
#ifndef SHEKEL_H
#define SHEKEL_H

class Shekel : public Currency{
public:
	Shekel(){
		Currency();
		wholeName = "Shekel";
		fracName = "Agorot";
	}
	Shekel(int w, int f){
		Currency(w, f);
		wholeName = "Shekel";
		fracName = "Agorot";
	}
};
#endif /* DOLLAR_H */