#ifndef ADTNODE_H
#define ADTNODE_H

template<class Type>
class ADTNode{
private:
	Type data;
public:
	ADTNode* right;
	ADTNode* left;
	ADTNode(Type t){
		data = t;
		right = nullptr;
		left = nullptr;
	}
	Type getData(){ return data; }
};
#endif // !ADTNODE_H