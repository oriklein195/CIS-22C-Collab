#include "Currency.h"
#include "Dollar.h"
#include "Euro.h"
#include "Pound.h"
#include "Yen.h"
#include "Shekel.h"
#include "Currency.h"
#ifndef WALLET_H
#define WALLET_H
using namespace std;

class Wallet{
private:
	Currency *types[5];
  int numTypes = 0;
public:
	Wallet();
  int typeExists(Currency *type) const;
  template <class Type> void add(Type t){
	  int i = typeExists(&t);
	  if (i){
		i--;
		types[i] = new Type((t + *types[i]).getWholeVal(), (t + *types[i]).getFracVal());
	  }  else if (numTypes != 5){
		  types[numTypes] = new Type(t.getWholeVal(), t.getFracVal());
		  numTypes++;
	  }
	  return;
  }
  void remove(Currency* type);
  void removeAll();
  void showContents();
  bool isEmpty() const;
};

#endif /* WALLET_H */
