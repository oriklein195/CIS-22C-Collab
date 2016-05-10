#include "Stack.h"

#ifndef INFIXCALC_H
#define INFIXCALC_H

class InfixCalc{
private:
	int size;
	Stack<char> operands;
	Stack<char> operators;
	char *expression;
public:
	InfixCalc(){
		size = 0;
		expression = nullptr;
		operands = Stack<char>();
		operators = Stack<char>();
	}
	InfixCalc(int s, char* ex){
		size = s;
		for (int i = 0; i < size; i++)
			expression[i] = ex[i];
		operands = Stack<char>();
		operators = Stack<char>();

	}
};
#endif // !INFIXCALC_H
