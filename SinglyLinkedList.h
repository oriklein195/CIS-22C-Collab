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
	void addFirst(ADTNode* newNode){
		newNode->next = head;
		head = newNode;
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
		int i = 0;
		ADTNode<Type>* pPre = nullptr;
		newNode->next = head;
		while (newNode->next != nullptr && i < index){
			pPre = newNode;
			newNode = newNode->next;
		}
		pPre->next = newNode;
		size++;
	}
	void addLast(ADTNode* newNode){
		rear->next = newNode;
		newNode->next = nullptr;
		rear = newNode;
		size++;
		if (size == 1)
			head = newNode;
	}
	void removeFirst(){
		if (size < 1)
			return;
		ADTNode<Type>* pLoc = head;
		head = head->next;
		delete pLoc;
		size--;
		if (size == 1)
			rear = head;
	}
	void remove(int index){
		if (index >= size){
			return;
		}
		if (index == 0){
			removeFirst();
			return;
		}
		int i = 0;
		ADTNode<Type>* pLoc = head;
		ADTNode<Type>* pPre = nullptr;
		while (pLoc->next != nullptr && i < index){
			pPre = pLoc;
			pLoc = pLoc->next;
		}
		pPre->next = pLoc->next;
		if (pPre->next == nullptr)
			rear = pPre;
		delete pLoc;
		size--;
	}
	ADTNode* get(int index){
		if (index >= size || index < 0){
			return;
		}
		ADTNode<Type>* pLoc = head;
		int i = 0;
		while (pLoc->next != nullptr && i < index){
			pLoc = pLoc->next;
		}
		return pLoc;
	}
	bool find(ADT);
	int getSize(){
		return size;
	}
	void empty(){
		int s = size;
		for (int i = 0; i < s; i++){
			removeFirst();
		}
	}

};

#endif // !SINGLYLINKEDLIST_H
