#include "Currency.h"
#include "Wallet.h"
#include <iostream>
#include <typeinfo>
#include <string>
#include <time.h>
using namespace std;

int main(){
	Wallet user = Wallet();
	srand(time(NULL));
  //User enters up to 5 pre-defined currencies
	bool quit = true;Pound
	bool picks[5] = { 0, 0, 0, 0, 0 };
	do {
		int choice; 
		cout << "Please choose up to five Currencies (separate each number by space): " << endl;
		cout << "1 = Dollars\n2 = Pound\n3 = Shekel\n4 = Yen\n5 = Euro\n6 = that's it\n";
		cin >> choice;
		switch (choice) {
		case 1:
			user.add<Dollar>(Dollar());
			picks[0] = true;
			break;
		case 2:
			user.add<>(Pound());
			picks[1] = true;
			break;
		case 3:
			user.add<Shekel>(Shekel());
			picks[2] = true;
			break;
		case 4:
			user.add<Yen>(Yen());
			picks[3] = true;
			break;
		case 5:
			user.add<Euro>(Euro());
			picks[4] = true;
			break;
		case 6:
			quit = false;
			break;
		default:
			cout << "wrong input, try again\n";
			break;
		}
	} while (quit);
  //Random number generator to add and remove currencies.
	if (picks[0]){
		user.add<Dollar>(Dollar(rand() % 500, rand() % 100));
		user.add<Dollar>(Dollar(rand() % 500, rand() % 100));
	} 
	if (picks[1]){
		user.add<Pound>(Pound(rand() % 500, rand() % 100));
		user.add<Pound>(Pound(rand() % 500, rand() % 100));
	}
	if (picks[2]){
		user.add<Shekel>(Shekel(rand() % 500, rand() % 100));
		user.add<Shekel>(Shekel(rand() % 500, rand() % 100));
	}
	if (picks[3]){
		user.add<Yen>(Yen(rand() % 500, rand() % 100));
		user.add<Yen>(Yen(rand() % 500, rand() % 100));
	}
	if (picks[4]){
		user.add<Euro>(Euro(rand() % 500, rand() % 100));
		user.add<Euro>(Euro(rand() % 500, rand() % 100));
	}
	//print total value on wallet
	cout << "Checking addition" << endl;
	user.showContents();
  //remove all money and print
	cout << "Removing all" << endl;
	user.removeAll();

	system("pause");
	return 0;
}
