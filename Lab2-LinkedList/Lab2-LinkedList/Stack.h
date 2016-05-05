#include "SinglyLinkedList.h"
#ifndef STACK_H
#define STACK_H
/**
Template class that inherits from SinglyLinkedList. Is able to pop, push, and check if empty.
*/
template <class Type>
class Stack : protected SinglyLinkedList<Type>{
public:
	/**
	adds a data Type at the beginning of stack
	*/
	void push(Type data){
		addFirst(data);
	};
	/**
	returns the last data type in your stack and removes it from there.
	*/
	Type pop(){
		Type data = get(0);
		removeFirst();
		return data;
	};
	/**
	returns true if empty
	*/
	bool isEmpty(){
		return (getSize() == 0);
	};
};
#endif // !STACK_H
