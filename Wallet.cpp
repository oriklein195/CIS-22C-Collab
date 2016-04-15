#include "Wallet.h"

using namespace std;

Wallet::Wallet(){

}
int Wallet::typeExists(Currency* type) const{
	string str = typeid(*type).name();
	for (int i = 0; i < numTypes; i++){
		if (str.compare(typeid(*types[i]).name())== 0)
			return i+1;
	}
	return 0;
	
}
void Wallet::remove(Currency* type){
	int i = typeExists(type);
	if (i){
		i--;
		delete types[i];
		for (int j = i; j < numTypes - 1; j++)
			types[j] = types[j + 1];
		numTypes--;
	}
}
void Wallet::removeAll(){
	for (int i = 0; i < numTypes; i++){
		delete types[i];
	}
	numTypes = 0;
}
void Wallet::showContents(){
	for (int i = 0; i < numTypes; i++){
		cout << *types[i];
	}
}
bool Wallet::isEmpty() const{
	return !numTypes;
}