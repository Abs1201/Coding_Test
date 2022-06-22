//#include <bits/stdc.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int lower(int a, int b){
	return (a<b) ? a:b;
}

int min(const vector<int> times, int condition = 0){
	if(times.size() < 2){
		if(times.size() < 1){
			return 0;
		}
		return times[0];
	}
	int min = times[0];
	int tmp = 0;
	
	for(int i = 1; i < times.size(); i++){
		tmp = min;
		min = lower(min, times[i]);
		if(min < condition){
			min = tmp;
		}
	}
	
	return min;
}


long long solution(int n, vector<int> times) {
    long long answer = 0;
	
	
    return answer;
}

int main(void){
	
	int num = 6;
	vector <int>times {7,10,3,6,3,5,8,3};
	
	long long answer = solution(num, times);
	
	//cout << answer << endl;
	
	cout << min(times, 3);
	
	
	
	return 0;
}