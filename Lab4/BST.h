#ifndef BST_H
#define BST_H

#include "ADTNode.h"
#include<iostream>
#include<fstream>
#include<string>

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
	This algorithm deletes a node from an AVL tree and rebalances if necessary
	@Pre:	root is a pointer to a [sub]tree
			data is the key of node to be deleted
			success is a reference to a boolean variable
	@Post:	node deleted if found, tree unchanged if not.
			success set true or false
	@return:	pointer to root of [potential] new subtree
	*/
	ADTNode<Type>* AVLDelete(ADTNode<Type>* subRoot, Type data, bool success){
		if (subRoot == nullptr){
			success = false;
			return nullptr;
		}
		if (data < subRoot->getData()){
			int originalHeight = getHeight(root);
			subRoot->left = AVLDelete(subRoot->left, data, success);
			if (originalHeight > getHeight(root))
				subRoot = deleteLeftBalance(subRoot);
		}
		else if (data > subRoot->getData()) {
			int originalHeight = getHeight(root);
			subRoot->right = AVLDelete(subRoot->right, data, success);
			if (originalHeight > getHeight(root))
				subRoot = deleteRightBalance(subRoot);
		}
		else {
			ADTNode<Type>* newRoot = subRoot;
			ADTNode<Type>* tempNode = subRoot->left;
			if (subRoot->right == nullptr){
				success = true;
				return subRoot->left;
			}
			else if (subRoot->left == nullptr){
				success = true;
				return subRoot->right;
			}
			else {
				while (tempNode->right != nullptr)
					tempRoot = tempNode->right;
				Type largest = tempNode->getData();
				subRoot->setData(largest);
				int originalHeight = getHeight(root);
				subRoot->left = AVLDelete(subRoot->left, largest, success);
				if (originalHeight > getHeight(root))
					subRoot = deleteRightBalance(subRoot);
			}
		}
		return subRoot;
	}

	/**
	The [sub]tree is shorter after a deletion on the left branch.
	If necessary, balance the tree by rotating.
	@Pre:	tree is shorter
	@post	balance restored
	@return:	new root
	*/
	ADTNode<Type>* deleteRightBalance(ADTNode<Type>* subRoot){
		if (getHeight(subRoot->left) + 1 < getHeight(subRoot->right)){
			ADTNode<Type>* rightOfRight = subRoot->right;
			if (getHeight(rightOfRight->left) > getHeight(rightOfRight->right) + 1){
				ADTNode<Type>* leftOfRight = rightOfRight->left;
				subRoot->right = rotateRight(rightOfRight);
				subRoot = rotateLeft(subRoot);
			}
			else {
				subRoot = rotateLeft(subRoot);
			}
		}
		return subRoot;
	}

	/**
	The [sub]tree is shorter after a deletion on the right branch.
	If necessary, balance the tree by rotating.
	@Pre:	tree is shorter
	@post	balance restored
	@return:	new root
	*/
	ADTNode<Type>* deleteLeftBalance(ADTNode<Type>* subRoot){
		if (getHeight(subRoot->right) + 1 < getHeight(subRoot->left)){
			ADTNode<Type>* leftOfLeft = subRoot->left;
			if (getHeight(leftOfLeft->right) > getHeight(leftOfLeft->left) + 1){
				ADTNode<Type>* RightOfLeft = leftOfLeft->right;
				subRoot->left = rotateLeft(leftOfLeft);
				subRoot = rotateRight(subRoot);
			}
			else {
				subRoot = rotateRight(subRoot);
			}
		}
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
	ADTNode<Type>* rotateLeft(ADTNode<Type>* subRoot){
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

	/*!!!!!!!!**TOMER FILL THIS IN**!!!!!!!!!!*/

	/**
	This algorithm will put all data on the file in order requested
	@Pre:	outFile is 
			mode is set to 1 (pre-order), 2 (in-order), 3 (post-order), 4 (breadth-first)
	*/
	void writeToFile(int mode, ofstream& outFile){

	}

	bool isEmpty(){
		return !size;
	}

};


#endif // !BST_H
