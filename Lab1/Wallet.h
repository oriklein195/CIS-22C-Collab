#include "Currency.h"
#include "Dollar.h"
#include "Euro.h"
#include "Pound.h"
#include "Yen.h"
#include "Shekel.h"

#ifndef WALLET_H
#define WALLET_H
using namespace std;

class Wallet{
private:
  Currency types[5];
  int numTypes;
public:
  Wallet();
  bool typeExists(Currency type) const;
  void add(Currency type);
  void remove(Currency type);
  void removeAll();
  bool isEmpty() const;
};

#endif /* WALLET_H */
