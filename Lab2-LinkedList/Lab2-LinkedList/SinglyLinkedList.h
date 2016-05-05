#include "ADTNode.h"
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
using namespace std;
/*
Template class that creates a singly linked list with the ability to add a node anywhere, remove from anywhere,
empty, extract data from node.
head is an ADTNode pointer that points to the first node in the list, without holding data
rear is an ADTNode pointer that points to the last node in the list, without holding data
index of first node is 0, index of last node is size -1.
*/
template<class Type>
class SinglyLinkedList{
private:
	int size;
	ADTNode<Type>* head;
	ADTNode<Type>* rear;
public:
	/**
	Creates an instance of a SinglyLinkedList
	*/
	SinglyLinkedList(){
		size = 0;
		head = nullptr;
		rear = nullptr;
	}
	/**
	adds a node to beginning of the list, head will point to that node
	*/
	void addFirst(Type data){
		ADTNode<Type>* newNode = new ADTNode<Type>(data);
		newNode->next = head;
		head = newNode;
		size++;
		if (size == 1)
			rear = newNode;
	}
	/**
	adds a node after the node specified at that index
	*/
	void addAfter(Type data, int index){
		ADTNode<Type>* newNode = new ADTNode<Type>(data);
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
	/**
	adds a node at the size index
	*/
	void addLast(Type data){
		ADTNode<Type>* newNode = new ADTNode<Type>(data);
		rear->next = newNode;
		newNode->next = nullptr;
		rear = newNode;
		size++;
		if (size == 1)
			head = newNode;
	}
	/**
	deletes node from existance
	*/
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
	/**
	deletes node from existance at indicated index
	*/
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
	/**
	extracts data from node at specified index
	*/
	Type get(int index){
		ADTNode<Type>* pLoc = head;
		int i = 0;
		while (pLoc->next != nullptr && i < index){
			pLoc = pLoc->next;
		}
		return pLoc->getData();
	}
	int find(Type data){

	}
	/**
	returns size
	*/
	int getSize(){
		return size;
	}
	/**
	deletes all nodes
	*/
	void empty(){
		int s = size;
		for (int i = 0; i < s; i++){
			removeFirst();
		}
		head = nullptr;
		rear = nullptr;
	}

};

#endif // !SINGLYLINKEDLIST_H