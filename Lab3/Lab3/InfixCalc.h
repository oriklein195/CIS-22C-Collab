#include "Stack.h"
#include <string>
#ifndef INFIXCALC_H
#define INFIXCALC_H

class InfixCalc{
private:
	int size;
	Stack<int> operands;
	Stack<char> operators;
	string expression;
	void execute(){
		int val1, val2;
		char c;
		try {
			val2 = operands.pop();
			val1 = operands.pop();
			c = operators.pop();
		}
		catch (string s){
			throw s;
		}
		
		switch (c){
		case '+':
			operands.push(val1 + val2);
			break;
		case '-':
			operands.push(val1 - val2);
			break;
		case '*':
			operands.push(val1 * val2);
			break;
		case '/':
			if (val2 != 0)
				operands.push(val1 / val2);
			else
				throw "Can't divide by 0";
			break;
		default:
			throw "Invalid operator: '" + c + '\'';
			break;
		}
	}
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
		expression = "";
		operands = Stack<int>();
		operators = Stack<char>();
	}
	InfixCalc(int s, string ex){
		size = s;
		expression = ex;
		operands = Stack<int>();
		operators = Stack<char>();
	}
	int evaluate(){
		for (int i = 0; i < size; i++){
			char c = expression.at(i);
			switch (c){
			case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
				operands.push(c - '0');
				break;
			case '(':
				operators.push(c);
				break;
			case '+': case '-': case '*': case '/':
				if (operators.isEmpty())
					operators.push(c);
				else if (precedence(c) > precedence(operators.peek()))
					operators.push(c);
				else {
					while (!operators.isEmpty() && precedence(c) <= precedence(operators.peek()))
						execute();
					operators.push(c);
				}
				break;
			case ')':
				while (operators.peek() != '(')
					execute();
				operators.pop();
				break;
			}
		}
		while (!operators.isEmpty())
			execute();
		return operands.pop();
	}
	bool checkSyntax(){
		int pCount = 0;
		bool nextIsVal = true;
		for (int i = 0; i < size; i++){
			char c = expression.at(i);
			switch (c){
			case '(':
				pCount++;
				break;
			case ')':
				if (pCount <= 0)
					return false;
				break;
			case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
				if (nextIsVal)
					nextIsVal = false;
				else
					return false;
				break;
			case '+': case '-': case '*': case '/':
				if (!nextIsVal)
					nextIsVal = true;
				else
					return false;
				break;
			default:
				return false;
				break;
			}
		}
		return true;

	}
};
#endif // !INFIXCALC_H
