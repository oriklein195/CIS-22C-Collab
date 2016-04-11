#ifndef CURRENCY_H
#define CURRENCY_H
#include <iostream>
using namespace std;

class Currency{
private:
  string wholeName, fracName;
  int wholeVal, fracVal;
public:
  Currency();
  Currency(int w, int f);
  Currency operator+();
  Currency operator-();
  Currency operator>>();
  Currency operator<<();
  double getValue() const;
}


#endif /* CURRENCY_H */
