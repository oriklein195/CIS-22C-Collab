#include "Stack.h"
#include "Queue.h"
#include "Currency.h"
#include "Dollar.h"
#include "Pound.h"
#include "Yen.h"
#include "Euro.h"
#include "Shekel.h"
#include <string>
#include <iostream>
using namespace std;

int main(){

	cout << "Testing Stack of ints:\n";
	
	Stack<int> s1 = Stack<int>();
	int first = 1;
	int second = 2;
	int third = 3;
	s1.push(first);
	s1.push(second);
	s1.push(third);
	while (!s1.isEmpty()){
		cout << s1.pop() << ", ";
	}
	cout << "done!\n\n";

	cout << "Testing Stack of strings:\n";

	Stack<string> s2 = Stack<string>();
	string firstString = "First";
	string secondString = "Second";
	string thirdString = "Third";
	s2.push("Fourth");
	s2.push(thirdString);
	s2.push(secondString);
	s2.push(firstString);

	while (!s2.isEmpty()){
		cout << s2.pop() << ", ";
	}
	cout << "done!\n\n";

	cout << "Testing empty Stack of doubles:\n";

	Stack<double> s3 = Stack<double>();
	while (!s3.isEmpty()){
		cout << s3.pop() << ", ";
	}
	cout << "done!\n\n";

	cout << "Testing Queue of ints:\n";

	Queue<int> q1 = Queue<int>();
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);

	while (!q1.isEmpty()){
		cout << q1.dequeue() << ", ";
	}
	cout << "done!\n\n";

	cout << "Testing Queue of Dollars:\n";

	Queue<Dollar> q2 = Queue<Dollar>();
	Dollar d1 = Dollar(1, 50);
	Dollar d2 = Dollar(2, 50);
	Dollar d3 = Dollar(3, 50);
	q2.enqueue(d1);
	q2.enqueue(d2);
	q2.enqueue(d3);
	q2.enqueue(Dollar(5, 0));

	while (!q2.isEmpty()){
		cout << q2.dequeue() << ", ";
	}
	cout << "done!\n\n";

	cout << "Testing Stack of Dollars:\n";

	Stack<Dollar> s4 = Stack<Dollar>();
	s4.push(d1);
	s4.push(d2);
	s4.push(d3);
	q2.enqueue(Dollar(100, 99));
	q2.enqueue(Dollar(4, 20));
	q2.enqueue(Dollar(736, 27));
	s4.push(q2.dequeue());
	s4.push(q2.dequeue());
	s4.push(q2.dequeue());

	while (!s4.isEmpty()){
		cout << s4.pop() << ", ";
	}
	cout << "done!\n\n";

	cout << "Testing Stack of Yen:\n";

	Stack<Yen> s5 = Stack<Yen>();
	Yen y1 = Yen(1, 50);
	Yen y2 = Yen(2, 50);
	Yen y3 = Yen(3, 50);
	s5.push(y1);
	s5.push(y2);
	s5.push(y3);

	while (!s5.isEmpty()){
		cout << s5.pop() << ", ";
	}
	cout << "done!\n\n";

	cout << "Testing Queue of Yen:\n";
	Queue<Yen> q3 = Queue<Yen>();
	q3.enqueue(y1);
	q3.enqueue(y2);
	q3.enqueue(y3);


	while (!q3.isEmpty()){
		cout << q3.dequeue() << ", ";
	}
	cout << "done!\n\n";

	cout << "Testing Queue of Currency Pointers:\n";

	Queue<Currency*> q4 = Queue<Currency*>();
	q4.enqueue(new Yen(1, 55));
	q4.enqueue(new Dollar(66, 72));
	q4.enqueue(new Euro(4, 88));

	while (!q4.isEmpty()){
		cout << *(q4.dequeue()) << ", ";
	}
	cout << "done!\n\n";
	system("pause");
	return 0;
}