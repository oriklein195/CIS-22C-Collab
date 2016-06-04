#include "SinglyLinkedList.h"
#ifndef QUEUE_H
#define QUEUE_H
/**
Template class that inherits from SinglyLinkedList. Is able to enqueue, dequeue, and check if empty.
*/
template <class Type>
class Queue : protected SinglyLinkedList<Type>{
public:
	/**
	adds a data Type at the beginning of stack
	*/
	void enqueue(Type data){
		addFirst(data);
	};
	/**
	returns the last data type in your stack and removes it from there.
	*/
	Type dequeue(){
		Type data = get(getSize()-1);
		remove(getSize() - 1);
		return data;
	};
	/**
	returns true if empty
	*/
	bool isEmpty(){
		return (getSize() == 0);
	};
};
#endif // !QUEUE_H
