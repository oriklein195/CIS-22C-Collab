#ifndef BST_H
#define BST_H

#include "ADTNode.h"

template <class Type>
class BST{
private:
	ADTNode<Type>* root = nullptr;
	int size = 0;
public:
	BST(){

	}
	/**
	Use recursion to insert a node into an AVL tree
	@Pre: 	root is pointer to first node in AVL tree/subtree
	@pre:	newData is pointer to new node to be inserted
	@post:	new node has been inserted
	@return:	root returned recursively up the tree
	*/
	ADTNode<Type>* insert(ADTNode<Type>* subRoot, Type data){
		ADTNode<Type>* newNode = new ADTNode<Type>(data);
		if (subRoot == nullptr){
			subRoot = newNode;
			size++;
			return subRoot;
		} if (data < subRoot->getData()){
			subRoot->left = (subRoot->left, data);
			if (getHeight(subRoot->left) > getHeight(subRoot->right) + 1){
				// leftbalance(subRoot)
			}
		}
		else {
			subRoot->right = insert(subRoot->right, data);
			if (getHeight(subRoot->right) > getHeight(subRoot->left) + 1){
				// rightbalance(subRoot)
			}
		}
		size++;
		return subRoot;
	}

	/**
	This algorithm is entered when the root is left high(the left subtree is higher than the right subtree).
	@pre:	root is a pointer to the root of the subtree
	@post:	root has been updated (if necessary)
	*/
	ADTNode<Type>* leftBalance(ADTNode<Type>* subRoot){
		if (getHeight(subRoot->left) > getHeight(subRoot->right) + 1){
			subRoot = rotateRight(subRoot);
		} else {
			subRoot->left = (subRoot->left);
			subRoot = rotateRight(subRoot);
		}
		return subRoot;
	}

	/**
	This algorithm is entered when the root is right high(the right subtree is higher than the left subtree).
	@pre:	root is a pointer to the root of the subtree
	@post:	root has been updated (if necessary)
	*/
	ADTNode<Type>* rightBalance(ADTNode<Type>* subRoot){
		if (getHeight(subRoot->right) > getHeight(subRoot->left) + 1){
			subRoot = rotateLeft(subRoot);
		}
		else {
			subRoot->right = (subRoot->right);
			subRoot = rotateLeft(subRoot);
		}
		return subRoot;
	}
	/**
	This algorithm exchanges pointers to rotate the tree right
	@pre:	root points to tree to be rotated
	@post:	node rotated and root updated
	*/
	ADTNode<Type>* rotateRight(ADTNode<Type>* subRoot){
		ADTNode<Type>* tempRoot = subRoot->right;
		subRoot->right = subRoot->right->left;
		subRoot = tempRoot;
		return subRoot;
	}

	/**
	This algorithm exchanges pointers to rotate the tree left
	@pre:	root points to tree to be rotated
	@post:	node rotated and root updated
	*/
	ADTNode<Type>* rotateRight(ADTNode<Type>* subRoot){
		ADTNode<Type>* tempRoot = subRoot->left;
		subRoot->left = subRoot->left->right;
		subRoot = tempRoot;
		return subRoot;
	}

	int getHeight(ADTNode<Type>* subRoot){
		if (subRoot->left == nullptr && subRoot->right == nullptr){
			return 1;
		}
		if (subRoot->left == nullptr){
			return (1 + getHeight(subRoot->right));
		}
		if (subRoot->right == nullptr){
			return (1 + getHeight(subRoot->left));
		}
		int r = getHeight(subRoot->right);
		int l = getHeight(subRoot->left);
		if (r > l){
			return r + 1;
		}
		return l + 1;
	}

	bool isEmpty(){
		return !size;
	}

};


#endif // !BST_H
