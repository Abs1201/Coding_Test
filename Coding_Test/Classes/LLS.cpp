//Linked List Stack
// #include "Stack.h"

// typedef struct tagNode{
// 	String data;
// 	struct tagNode* nextNode;
// }Node;

// typedef struct tagLinkedListStack{
// 	Node* List;
// 	Node* Top;
// }LinkedListStack;


//#include <iostream>
#include "String.cpp"

typedef struct tagNode{
	String data;
	struct tagNode* nextNode;
	struct tagNode* prevNode;
	//struct tagNode* prevNode;
}Node;

typedef struct tagLinkedListStack{
	Node* List;
	Node* Top;
}LinkedListStack;

void createStack(LinkedListStack** stack);
void destroyStack(LinkedListStack* stack);

Node* createNode(const char* data);
Node* createNode(char* data);
void destroyNode(Node* node);

void push(LinkedListStack* stack, Node* newNode);
Node* pop(LinkedListStack* stack);

Node* getTop(LinkedListStack* stack);
int getSize(LinkedListStack* stack);
bool isEmpty(LinkedListStack* stack);




void createStack(LinkedListStack** stack){
	*stack = new LinkedListStack;
	(*stack)->List = NULL;
	(*stack)->Top = NULL;
}
void destroyStack(LinkedListStack* stack){
	while(!isEmpty(stack)){
		Node* popped = pop(stack);
		destroyNode(popped);
	}
	delete stack;
}

Node* createNode(const char* data){
	Node* newNode = new Node;
	newNode->data = data;
	
	newNode->nextNode = NULL;
	newNode->prevNode = NULL;
	
	return newNode;
}
void destroyNode(Node* node){	//해제 오류 가능성
	delete node;
}

void push(LinkedListStack* stack, Node* newNode){
	if(stack->List == NULL){
		stack->List = newNode;
	}
	else{
		Node* tmp = stack->List;
		while(tmp->nextNode != NULL){
			tmp = tmp->nextNode;
		}
		tmp->nextNode = newNode;
		newNode->prevNode = tmp;
	}
	stack->Top = newNode;
}
Node* pop(LinkedListStack* stack){
	Node* topNode = stack->Top;
	if(stack->List == stack->Top){
		stack->List = NULL;
		stack->Top = NULL;
	}
	else{
		Node* tmp = stack->List;
		while(tmp != NULL && tmp->nextNode != stack->Top){
			tmp = tmp->nextNode;
		}
		stack->Top = tmp;
		tmp->nextNode = NULL;
	}
	return topNode;
}

Node* getTop(LinkedListStack* stack){
	return stack->Top;
}
int getSize(LinkedListStack* stack){
	int count = 0;
	Node* tmp = stack->List;
	while(tmp != NULL){
		tmp = tmp->nextNode;
		count++;
	}
	return count;
}
bool isEmpty(LinkedListStack* stack){
	if(stack->List == NULL){
		return 1;
	}
	return 0;
}

