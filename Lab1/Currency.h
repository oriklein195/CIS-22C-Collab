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
  Currency operator+(Currency& other);
  Currency operator-(Currency& other);
  istream& operator>>(istream& is);
  ostream& operator<<(ostream& os);
  double getValue() const;
};


#endif /* CURRENCY_H */
