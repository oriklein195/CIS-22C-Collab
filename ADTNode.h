#ifndef ADTNODE_H
#define ADTNODE_H

template<class Type>
class ADTNode{
private: 
	Type data;
public:
	ADTptr* next;
	ADTNode(Type t){
		data = t;
		next = nullptr;
	}
};
#endif // !ADTNODE_H
