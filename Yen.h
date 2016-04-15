#include "Currency.h"
using namespace std;
#ifndef YEN_H
#define YEN_H

class Yen : public Currency{
public:
	Yen() :Currency(){
		wholeName = 'Y';
		fracName = 's';
	}
	Yen(int w, int f) :Currency(w, f){
		wholeName = 'Y';
		fracName = 's';
	}
};
#endif /* YEN_H */