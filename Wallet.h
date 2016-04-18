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
/**
 * This is a Wallet Class, each Wallet can include up to 5 pre defined currencies. 
 */
class Wallet{
private:
	Currency *types[5];
  	int numTypes = 0;
public:
	//Creates an instance of a Wallet that holds an array of five Currency pointers
	Wallet();
	//Checks if the Currency type already exists and returns its value in the array plus one
  	int typeExists(Currency *type) const;
  	//Adds a curency to the array, if it already exists it adds its value, and if it doesn't it will make a new wallet with it.
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
  	//removes a currency from the wallet
  	void remove(Currency* type);
  	//Deletes all values in types array
  	void removeAll();
  	//prints all values in the wallet.
  	void showContents();
  	//Checks if the wallet is empty
  	bool isEmpty() const;
};

#endif /* WALLET_H */
