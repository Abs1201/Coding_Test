#include "LinkedList.h"

typedef struct tagNode{
	int data;
	struct tagNode* nextNode;
}Node;


Node* createNode(int element) {
	Node* newNode = new Node;
	newNode->data = element;
	newNode->nextNode = NULL;

	return newNode;
}

void destroyNode(Node* Node){
	delete []Node;
}

void appendNode(Node** head, Node* newNode) {
	if (*head == NULL) {
		*head = newNode;
	}
	else {
		Node* tail = *head;
		while (tail->nextNode != NULL) {
			tail = tail->nextNode;
		}
		tail->nextNode = newNode;
	}
}

void insertAfter(Node* current, Node* newNode){
	newNode -> nextNode = current -> nextNode;
	current -> nextNode = newNode;
}

void removeNode(Node** head, Node* remove){
	if(*head == remove){
		*head = remove -> nextNode;
	}
	else{
		Node* current = *head;
		while(current != NULL && current -> nextNode != remove){
			current = current -> nextNode;
		}
		if(current != NULL){
			current -> nextNode = remove -> nextNode;
		}
	}
}

Node* getNodeAt(Node* head, int location){
	Node *current = head;
	
	while(current != NULL && (--location) >= 0){
		current = current -> nextNode;
	}
	return current;
}

int getNodeCount(Node* head){
	int count = 0;
	Node* current = head;
	
	while(current != NULL){
		current = current -> nextNode;
		count++;
	}
	return count;
}
