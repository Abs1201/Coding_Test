// https://programmers.co.kr/learn/courses/30/lessons/12973

#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    int answer = -1;
	if(s.size() == 1) return 0;
	else if(s.size() == 0) return 1;
	for(int i = 0; i < s.size()-1; i++){
		if(s[i] == s[i+1]){
			s = s.erase(i,2);
			if(s.empty()) return 1;
			else return solution(s);
		}
	}
	return 0;
}

int main(void){
	
	cout << solution("cdcd");
}