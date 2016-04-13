#ifndef CURRENCY_H
#define CURRENCY_H
#include <iostream>
using namespace std;

class Currency{
protected:
  string wholeName, fracName;
  int wholeVal, fracVal;
  void simplify();
public:
  Currency();
  Currency(int w, int f);
  virtual friend Currency operator+(const Currency& first, const Currency& other);
  virtual friend Currency operator-(const Currency& first, const Currency& other);
  friend istream& operator>> (istream& is, Currency& c);
  friend ostream& operator<<(ostream& os, const Currency& c);
  virtual double getValue() const;
};


#endif /* CURRENCY_H */
