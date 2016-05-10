#include "Stack.h"

#ifndef INFIXCALC_H
#define INFIXCALC_H

class InfixCalc{
private:
	int size;
	Stack<int> operands;
	Stack<char> operators;
	char *expression;
	int precedence(char c){
		switch (c){
		case '(': case ')':
			return 0;
			break;
		case '+': case '-':
			return 1;
			break;
		case '*': case '/':
			return 2;
			break;
		}
	}
public:
	InfixCalc(){
		size = 0;
		expression = nullptr;
		operands = Stack<int>();
		operators = Stack<char>();
	}
	InfixCalc(int s, char* ex){
		size = s;
		for (int i = 0; i < size; i++)
			expression[i] = ex[i];
		operands = Stack<int>();
		operators = Stack<char>();
	}
};
#endif // !INFIXCALC_H
