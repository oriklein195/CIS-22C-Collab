#ifndef ADTNODE_H
#define ADTNODE_H
/**
Template class that can contain any data and return it. 
Also contains a pointer to the next node or null.

*/
template<class Type>
class ADTNode{
private:
	Type data;
public:
	ADTNode* next;
	ADTNode(Type t){
		data = t;
		next = nullptr;
	}
	Type getData(){ return data; };
};
#endif // !ADTNODE_H