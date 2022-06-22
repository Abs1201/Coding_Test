//  https://programmers.co.kr/learn/courses/30/lessons/42888
#include <iostream>
#include <string>
#include <vector>

//최종적으로 방을 개설한 사람이 보게 되는 메시지를 문자열 배열 형태로 return 
vector<string> solution(vector<string> record) {
    vector<string> answer;
	
	vector<string> acts = {"Enter", "Leave", "Change"};
	
	string tmp = "";
	
	vector<vector<string>> members;
	
	int count = 0;
	int j = 0;
	int k = 0;
	for(int i = 0; i < record.size(); i++){
		for(j = 0; record[i][j] != ' '; j++){
			//Enter .
		}
		for(k = j+1; record[i][k] != ' '; k++){
				tmp = tmp + record[i][k];	//tmp == uid1234
		}
	}
	
	
    return answer;

}

int main(void){
	
	vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid134","Enter uid1234 Prodo","Change uid4567 Ryan"};
	
	
	
	return 0;
}