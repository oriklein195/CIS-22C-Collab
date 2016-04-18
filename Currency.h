#ifndef CURRENCY_H
#define CURRENCY_H
#include <iostream>
using namespace std;
/**
 * This is the Currency base class. 
 * its name is an empty string.
 */
class Currency{
protected:
	char wholeName, fracName;
	int wholeVal, fracVal;
	//makes the currency "real world like" by making the fraction value between 0 and 99
	//Will throw an error if the final currency is negative
	void simplify();
public:
	//Creates an instance of currency with wholeVal = fracVal = 0
	Currency();
	//Creates an instance of currency with wholeVal = w;fracVal = f
	Currency(int w, int f);
	//Overrides the + operator so that it will add the value two currencies without changing them. 
	friend Currency operator+(const Currency& first, const Currency& other);
	//Overrides the - operator so that it will subtract the value two currencies without changing them.
	//Will throw an error if other is greater than first (the result is negative)
	friend Currency operator-(const Currency& first, const Currency& other);
	//Overrides the >> operator so that it will be able to read in a Currency easily.
	friend istream& operator>> (istream& is, Currency& c);
	//Overrides the << operator so that it will be able to write a representation of the Currency object.
	friend ostream& operator<<(ostream& os, const Currency& c);
	//returns the value of the Currency object as a double
	virtual double getValue() const;
	//returns the value of wholeVal
	int getWholeVal() const { return wholeVal; } 
	//returns the value of fracVal
	int getFracVal() const { return fracVal; }
};


#endif /* CURRENCY_H */
