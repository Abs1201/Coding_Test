#include "String.cpp"

class Node{
private:
	String data_s;
	int data_i;
	int index;
	Node* nextNode;
	Node* prevNode;
public:
	Node() : nextNode(NULL), prevNode(NULL){}
	Node(String data_s, int data_i = 0, int index = 0) : data_s(data_s), data_i(data_i), index(index), nextNode(NULL), prevNode(NULL){}
	Node(int data_i, int index = 0) : data_i(data_i), index(index){}
	
	String getData_s(){
		return data_s;
	}
	int getData_i(){
		return data_i;
	}
	int getIndex(){
		return index;
	}
	Node* getNextNode(){
		return nextNode;
	}
	Node* getPrevNode(){
		return prevNode;
	}
	
	void setData_s(String newData){
		data_s = newData;
	}
	void setData_i(int newData){
		data_i = newData;
	}
	void setIndex(int newIndex){
		index = newIndex;
	}
	void setNextNode(Node* newNextNode){
		nextNode = newNextNode;
	}
	void setPrevNode(Node* newPrevNode){
		prevNode = newPrevNode;
	}
	
	
	Node* createNode(const char* data){
		Node* newNode = new Node;
		newNode->data_s = data;

		newNode->nextNode = NULL;
		newNode->prevNode = NULL;

		return newNode;
	}
	Node* createNode(String data){
		Node* newNode = new Node;
		newNode->data_s = data;

		newNode->nextNode = NULL;
		newNode->prevNode = NULL;

		return newNode;
	}
	Node* createNode(char data){
		Node* newNode = new Node;
		newNode->data_s = data;
		newNode->nextNode = NULL;
		newNode->prevNode = NULL;

		return newNode;
	}
	Node* createNode(int data){
		Node* newNode = new Node;
		newNode->data_i = data;
		newNode->nextNode = NULL;

		return newNode;
	}
};

class LinkedListStack{
private:
	Node* List;
	Node* Top;
public:
	LinkedListStack() : List(NULL), Top(NULL){}
	
	Node* getList(){
		return this->List;
	}
	Node* getTop(){
		return this->Top;
	}
	
	void setList(Node* newList){
		Node* tmp = this->List;
		tmp->getNextNode()->setPrevNode(newList);
		newList->setNextNode(tmp->getNextNode());
		this->List = newList;
		delete tmp;
	}
	void setTop(Node* newTop){
		Node* tmp = this->Top;
		tmp->getPrevNode()->setNextNode(newTop);
		newTop->setPrevNode(tmp->getPrevNode());
		this->Top = newTop;
		delete tmp;
	}
	
	
	void push(Node* newNode){
		if(this->List == NULL){
			this->List = newNode;
			newNode->setIndex(1);
		}
		else{
			Node* tmp = this->List;
			while(tmp->getNextNode() != NULL){
				tmp = tmp->getNextNode();
			}
			tmp->setNextNode(newNode);
			newNode->setPrevNode(tmp);
			newNode->setIndex(tmp->getIndex()+1);
		}
		this->Top=newNode;
	}
	void push(Node& newNode){ // Node 복사생성자 만들기?
		if(this->List == NULL){
			this->List = &newNode;
			newNode.setIndex(1);
		}
		else{
			Node* tmp = this->List;
			while(tmp->getNextNode() != NULL){
				tmp = tmp->getNextNode();
			}
			tmp->setNextNode(&newNode);
			newNode.setPrevNode(tmp);
			newNode.setIndex(tmp->getIndex()+1);
		}
		this->Top=&newNode;
	}
	Node* pop(){
		Node* topNode = this->Top;
		if(this->List == this->Top){
			this->List == NULL;
			this->Top == NULL;
		}
		else{
			Node* tmp = this->List;
			while(tmp != NULL && tmp->getNextNode() != this->Top){
				tmp->getData_s().print();
				
				tmp = tmp->getNextNode();

			}
			this->Top = tmp;
			tmp->setNextNode(NULL);
		}
		return topNode;
	}
	int getSize(){
		int count = 0;
		Node* tmp = this->List;
		while(tmp != NULL){
			tmp = tmp->getNextNode();
			count++;
		}
		return count;
	}
	bool isEmpty(){
		if(this->List == NULL){
			return 1;
		}
		return 0;
	}
	
	int lastIndexOf(String s){
		Node* tmp = this->Top;
		while(tmp->getPrevNode() != NULL && tmp->getData_s() != s){
			tmp = tmp->getPrevNode();
		}
		if(tmp->getPrevNode() == NULL){
			if(tmp->getData_s() != s){
				return -1;
			}
		}
		return tmp->getIndex();
	}
	String getData_s(int index){
		Node* tmp = this->List;
		for(int i = 0; i < index; i++){
			tmp = tmp->getNextNode();
		}
		return tmp->getData_s();
	}
	bool contains(String& s){
		Node* tmp = this->Top;
		while(tmp->getPrevNode() != NULL && tmp->getData_s() != s){
			tmp = tmp->getPrevNode();
		}
		if(tmp->getPrevNode() == NULL){
			if(tmp->getData_s() != s){
				return 0;
			}
		}
		return 1;
	}
	
	~LinkedListStack(){
		delete this->Top;
		delete this->List;
	}
	
};










