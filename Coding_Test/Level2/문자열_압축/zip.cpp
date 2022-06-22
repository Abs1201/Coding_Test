#include "LLS2.cpp"

int* solution(String s);



int main(void){
	
	String kakao = "KAKAO";
	
	int* arr = solution(kakao);
	for(int i = 0 ; *(arr+i) != 12345; i++){
		cout << *(arr+i) << endl;
	}
	
	return 0;
}

int* solution(String s){
	
	LinkedListStack dic;
	Node* newNode;
	Node node;
	
	int i = 0;
	for(i=0; i < 26; i++){
		dic.push(node.createNode((char)(i+65))); //미심쩍음
	}

	//cout << "testcode" << endl;
	dic.getList()->getNextNode()->getData_s().print();
	
	LinkedListStack keys;
	
	String inputString;
	String newString;
	int key;
	int stringLen = s.getStringLen();
	
	int count=0;
	int j = 0;
	while(count < stringLen && j < stringLen){
		//cout << "testcode" << endl;
		inputString = *(s.getString()+count);
		newString = inputString;
		while(dic.contains(newString)){
			//cout << "testcode3" << endl;
			count++;
			newString = inputString + *(s.getString()+count);
			if(dic.contains(newString)){
				inputString = newString;
			}
		}
		//cout << "testcode" << endl;
		dic.push(node.createNode(newString));
		key = dic.lastIndexOf(inputString);
		keys.push(node.createNode(key));
		j++;
	}
	
	int keySize = keys.getSize();
	int* answer = new int[keySize+1];
	Node* tmp = keys.getList();
	for(i=0; i < keySize; i++){
		*(answer+i) = tmp->getData_i();
		tmp = tmp->getNextNode();
	}
	*(answer+keySize) = 12345;
	
	
	
	return answer;
}	



