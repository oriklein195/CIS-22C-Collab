#include <string>
#include <vector>
#include <iostream>
#include "BoxInterface.h"
#include "ToyBox.h"
#include "MagicBox.h"
#include "PlainBox.h"
using namespace std;

int main(){

	BoxInterface<string> *toys = new ToyBox<string>("buzz", BLACK);
	BoxInterface<string> *tricks;

	//toys->setItem("buzz");
	//tricks->setItem("cards");

	//cout << toys->getItem() << endl;
	//cout << tricks->getItem() << endl;

	system("pause");
	return 0;
}