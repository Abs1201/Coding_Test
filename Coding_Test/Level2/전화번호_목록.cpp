// https://programmers.co.kr/learn/courses/30/lessons/42577
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int getLen(string s){
	int count = 0;
	
	for(int i =0; s[i] != '\0'; i++){
		count++;
	}
	return count;
}



bool isIncludeFirst(string& s1, string& s2){
	int stringLen1 = getLen(s1);
	int stringLen2 = getLen(s2);
	if(stringLen1 == 0 || stringLen2 == 0) return 0;
	int i = 0;
	bool tmp = 1;
	while(s1[i] != '\0' && s2[i] != '\0'){
		if(s2[i] == s1[i]){
			tmp &= 1;
			cout << s2[i] << " " << s1[i] << endl;
		}
		else{
			tmp = 0;
		}
		i++;
	}
	
	return tmp;
}

bool solution(vector<string>& phone_book) {
    bool answer = 0;
	int phone_book_len = phone_book.size();
	
	for(int i = 0; i < (phone_book_len-1); i++){
		for(int j = i+1; j < phone_book_len; j++){
			answer = isIncludeFirst(phone_book[j], phone_book[i]);
			if(answer == 1) return 1;
		}
	}
	
    return 0;
}

int main(void){
	
	vector<string> phone_book = {"119", "97674223", "12195524421"};
	
	cout << solution(phone_book) << endl;
	
	return 0;
}