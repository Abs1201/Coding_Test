https://programmers.co.kr/learn/courses/30/lessons/42626
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville, int k){
	int answer = 0;
	sort(begin(scoville), end(scoville));
	
	int scovilleSize = scoville.size();
	// cout << "scovilleSize: " << scovilleSize << endl;
	// for(auto& e: scoville){
	// 	cout << e << " ";
	// }
	// cout << '\n';
	while(1){
		if(scoville[0] < k){
			if(scoville.size() > 1){
				scoville[0] = scoville[0]*2 + scoville[1];
				for(int i = 1; i <= scovilleSize-2; i++){
					scoville[i] = scoville[i+1];
				}
				scoville.resize(scoville.size()-1);
				answer++;
				
				sort(begin(scoville), end(scoville));
				
			}
			else{
				return -1;
			}
			
		}
		else{
			break;
		}
	}
	
	return answer;
}


int main(void){
	
	vector<int> scoville = {3,1,5,2,6,3,36}; //7
	
	int n = solution(scoville, 7);
	cout << n << endl;
	
	
	return 0;
}