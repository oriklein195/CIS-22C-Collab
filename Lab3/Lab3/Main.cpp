#include "InfixCalc.h"
#include <cstring>
#include <iostream>

int main(){
	int choice;
	string expression;
	InfixCalc ic;
	do{
		cout << "please choose:\n1) Test an operation\n2) Quit\n";
		cin >> choice;
		if (choice == 1){
			cout << "Please enter an expression that includes =,-,*,/,(,), no spaces and only single digit numbers: ";
			cin >> expression;
			ic = InfixCalc(expression.length(), expression);
			if (ic.checkSyntax())
				cout << "The result is: " << ic.evaluate() << endl;
			else
				cout << "Wrong syntax!\n";
		}
	} while (choice != 2);
	system("pause");
	return 0;

}