#include "Currency.h"
//#include <string>
using namespace std;

void Currency::simplify(){
	if (fracVal > 99){
		wholeVal += fracVal / 100;
		fracVal = fracVal % 100;
	}
	else if (fracVal < 0){
		fracVal *= -1;
		wholeVal -= fracVal / 100 - 1;
		fracVal = 100 - (fracVal % 100);
		simplify();
	}
	if (wholeVal < 0 || fracVal < 0){
		throw "Can't have negative " + wholeName;
	}
}
Currency::Currency(){
	wholeVal = 0;
	fracVal = 0;
}
Currency::Currency(int w, int f){
	wholeVal = w;
	fracVal = f;
	simplify();
}
Currency operator+(const Currency& first, const Currency& other){
	int wV, fV;
	wV = first.wholeVal + other.wholeVal;
	fV = first.fracVal + other.fracVal;
	Currency c = Currency(wV, fV);
	c.simplify();
	c.wholeName = first.wholeName;
	c.fracName = first.fracName;
	return c;
}
Currency operator-(const Currency& first, const Currency& other){
	Currency c = Currency(first.wholeVal, first.fracVal);
	c.wholeVal -= other.wholeVal;
	c.fracVal -= other.fracVal;
	try {
		c.simplify();
	}
	catch (string e) {
		throw e;
	}
	return c;
}
istream& operator>> (istream& is, Currency& c){
	char wN, fN;
	int wV, fV;
	is >> wV >> wN >> fV >> fN;
	c = Currency(wV, fV);

	return is;
}
ostream& operator<<(ostream& os, const Currency& c){
	os << c.wholeVal << " " << c.wholeName << " " << c.fracVal << " " << c.fracName << endl;
	return os;
}
double Currency::getValue() const{
	double value = wholeVal + fracVal / 100.0;
	return value;
}