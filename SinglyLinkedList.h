#include "ADTNode.h"
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
using namespace std;

template<class Type>
class SinglyLinkedList{
private:
	int size;
	ADTNode* head;
	ADTNode* rear;
public:
	SinglyLinkedList(){
		size = 0;
		head = nullptr;
		rear = nullptr;
	}
	void addFirst(ADTNode* node){
		node->next = head;
		head = node;
		size++;
		if (size == 1)
			rear = node;
	}
	void addAfter(ADTNode* newNode, int index){
		if (index > size){
			return;
		}
		if (index == size){
			addLast(newNode);
			return;
		}
		if (index == 0){
			addFirst(newNode);
			return;
		}
	}
	void addLast(ADTNode* newNode){

	}
	void removeFirst() :
	void remove(ADT);
	void removeLast();
	ADTNode get(int index);
	Bool find(ADT);
	Int size();
	Void empty();

};

#endif // !SINGLYLINKEDLIST_H
