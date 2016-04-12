#include "Currency.h"

using namespace std;

Currency::Currency(){
	wholeVal = 0;
	fracVal = 0;
}
Currency::Currency(int w, int f){
	wholeVal = w;
	fracVal = f;
	simplify();
}
Currency Currency::operator+(Currency& other){
	wholeVal += other.wholeVal;
	fracVal += other.fracVal;
	simplify();
	return *this;
}
Currency Currency::operator-(Currency& other){
	Currency c = Currency(this->wholeVal, this->fracVal);
	c.wholeVal -= other.wholeVal;
	c.fracVal -= other.fracVal;
	try {
		c.simplify();
	}
	catch (string e) {
		throw e;
	}
	wholeVal = c.wholeVal;
	fracVal = c.fracVal;
	return *this;
}
istream& Currency::operator>> (istream& is){

}
ostream& Currency::operator<< (ostream& os){

}
double Currency::getValue() const{
	double value = 0;
	return value;
}
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