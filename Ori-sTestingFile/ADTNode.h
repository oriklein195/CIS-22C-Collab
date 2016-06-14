#ifndef ADTNODE_H
#define ADTNODE_H

template<class Type>
class ADTNode{
private:
	Type data;
public:
	ADTNode* right;
	ADTNode* left;
	ADTNode* next;
    int key;
	ADTNode(Type t){
		data = t;
		right = nullptr;
		left = nullptr;
        next = nullptr;
        key = t.getId();
	}
	void setData(Type d){ data = d; }
    int getKey(){ return key; }
	Type getData(){ return data; }
};
#endif // !ADTNODE_H
