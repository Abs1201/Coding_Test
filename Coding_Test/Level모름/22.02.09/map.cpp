#include <iostream>
#include <cstdio>
#include "String.cpp"
using namespace std;

String* map(int n, int* arr1, int* arr2);
String shiftNum(int num, int notation);
void shifter(String& s, int size);
String* bind(String s1, String s2);


int main(void){
	
	int n =5;
	int arr1[5] = {9,20,28,18,11};
	int arr2[5] = {30,1,21,17,28};
	String* tmp = new String[n];
	tmp = map(n,arr1,arr2);
	
	for(int i = 0; i < n; i++){
		tmp[i].print();
	}
	
	return 0;
}

String* map(int n, int* arr1, int* arr2){
	String* newArr1 = new String[n];
	String* newArr2 = new String[n];
	String* newArr = new String[n];
	
	for(int i = 0; i < n; i++){
		*(newArr1 + i) = shiftNum(*(arr1+i), 2);
		shifter(*(newArr1+i), n);
		*(newArr2 + i) = shiftNum(*(arr2+i), 2);
		shifter(*(newArr2+i), n);
		
		// newArr1[i].print();
		// newArr2[i].print();
		//bind(*(newArr1+i), *(newArr2+i))->print();
		*(newArr+i) = *bind(*(newArr1+i), *(newArr2+i));
		
		// for(int j = 0; j < n; j++){
		// 	newArr1[j].print();
		// 	newArr2[j].print();
		// 	*(newArr+i) = *(bind(*(newArr1+i), *(newArr2+i)));
		// 	newArr[]
		// }
	}
	return newArr;
}

String shiftNum(int num, int notation){	
	if( num  < 0 ) return "응 너 장기백";
	if( notation < 2 || notation > 16) return "응 너 장기백";
	char intToChar[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	char* b = new char[50];
	int count = 0;
	while(num >= notation){
		b[count] = intToChar[num%notation];
		num = num/notation;
		count++;
	}
	b[count] = intToChar[num];
	b[++count] == '\0';
	
	String newString = b;
	newString = newString.reverse();
	
	return newString;
}

void shifter(String& s, int size){
	while(s.getStringLen() < size){
		s = s.Insert('0', 0);
	}
}
String* bind(String s1, String s2){
	String* a = new String;
	*a = "#####";
	//s1.print();
	//s2.print();
	int stringLen = s1.getStringLen();
	for(int j = 0; j < stringLen; j++){
		//cout << *(s1.getString()+j) << " " << *(s2.getString()+j) << endl;
		
		if(*(s1.getString()+j) == '0' && *(s2.getString()+j) =='0'){
			*a = a->Remove(j,1);
			*a = a->Insert(' ',j);
		}
		//a->print();
	}
	return a;
}












