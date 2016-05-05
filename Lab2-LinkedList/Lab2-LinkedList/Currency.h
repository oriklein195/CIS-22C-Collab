#ifndef CURRENCY_H
#define CURRENCY_H
#include <iostream>
using namespace std;

class Currency{
protected:
	char wholeName, fracName;
	int wholeVal, fracVal;
	void simplify();
public:
	Currency();
	Currency(int w, int f);
	friend Currency operator+(const Currency& first, const Currency& other);
	friend Currency operator-(const Currency& first, const Currency& other);
	friend istream& operator>> (istream& is, Currency& c);
	friend ostream& operator<<(ostream& os, const Currency& c);
	virtual double getValue() const;
	int getWholeVal() const { return wholeVal; } 
	int getFracVal() const { return fracVal; }
};


#endif /* CURRENCY_H */