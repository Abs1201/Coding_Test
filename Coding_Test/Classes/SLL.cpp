#include <iostream>


class Node{
private:
	char c;
	int i;
	Node* nextNode;
public:
	Node(char c){}
	
	
	Node* createNode(int element) {
		Node* newNode = new Node;
		newNode->data = element;
		newNode->nextNode = NULL;

		return newNode;
	}
	
	
	
}


