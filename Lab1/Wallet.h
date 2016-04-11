#ifndef WALLET_H
#define WALLET_H
using namespace std;

class Wallet{
private:
  Currency types[5];
  int numTypes;
public:
  bool typeExists(Currency type) const;
  void add(Currency type);
  void remove(Currency type);
  void removeAll();
  bool isEmpty() const;
}

#endif /* WALLET_H */
