#include "Currency.h"
using namespace std;
#ifndef YEN_H
#define YEN_H

class Yen : public Currency{
public:
	Yen(){
		Currency();
		wholeName = "Yen";
		fracName = "Sen";
	}
	Yen(int w, int f){
		Currency(w, f);
		wholeName = "Yen";
		fracName = "Sen";
	}
};
#endif /* YEN_H */