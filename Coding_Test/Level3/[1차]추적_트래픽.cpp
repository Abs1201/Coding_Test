// https://programmers.co.kr/learn/courses/30/lessons/17676
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
	int tmpIndex = -1;
	for(int i = 0; i < lines.size(); i++){
		tmpIndex = lines[i].find(' ');
		cout << tmpIndex << endl;
		tmpIndex = lines[i].find(' ', 12);
		cout << tmpIndex << endl;
	}
	
	
	
	
	
	
	
	
    return answer;
}

int main(void){
	
	
	vector<string> lines = {"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"};
	
	int answer = solution(lines);
	
	
	return 0;
}