#include <iostream>
#include "String.cpp"
using namespace std;


String solution(int n, int t, int m, int p); // 진법(n), 미리구할 숫자 개수(t), 게임인원수(m), 내 순번(p)
String shiftNum(int num, int notation);		//진수변환기  num(10) -> ?(notation)

int main(void){
	
	
	String a = solution(16,16,2,2);
	a.print();
	
	return 0;
}


String solution(int n, int t, int m, int p){ //notationArr을 m개씩 쪼개기(문자열쪼개기) -> 쪼갠문자열에서 p번째꺼만 추출
	
	String notationArr;
	int len = 0;
	String tmp;
	int tmpLen;
	for(int i = 0; i < t*m; i++){
		if(len < t*m){
			tmp = shiftNum(i,n);
			tmpLen = tmp.getStringLen();
			len += tmpLen;
			notationArr = notationArr + tmp;
			
		}
		else{ break; }
	}
	
	char* key = new char[t+1]; //끝에 '\0'
	for(int i = 0; i < t; i++){
		*(key+i) = *(notationArr.getString() + (p-1));
		//cout << "i: " << i << " " << *(key+i) << endl;
		notationArr = notationArr.SubString(m);
		//cout << "i: " << i << " ";notationArr.print();
	}
	*(key+t) = '\0';
	String answer = key;
	
	
	
	return answer;
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