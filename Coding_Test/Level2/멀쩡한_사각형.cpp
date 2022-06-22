#include <iostream>
#include <vector>

using namespace std;

int getBigger(int a, int b){return (a>b) ? a:b;}
int getSmaller(int a, int b){return (a<b) ? a:b;}

int getGCD(int a, int b){//최대공약수
	int big = getBigger(a,b);
	int small = getSmaller(a,b);
	
	vector<int> bigPrime;
	vector<int> smallPrime;
	
	for(int i = 1; i <= big/2; i++){
		if(big % i == 0) bigPrime.push_back(i); 
	}
	for(int i = 1; i <= small; i++){
		if(small % i == 0) smallPrime.push_back(i);
	}
	
	for(int i = smallPrime.size()-1; i >=1; i--){
		for(int j = 0; j < bigPrime.size(); j++){
			if(bigPrime[j] == smallPrime[i]){return smallPrime[i]; }
		}
	}
	
	return 0;
}

int solution(int w,int h) {
    int answer = 0;
	if(w <= 1 || h <= 1) return 0;

	int GCD = getGCD(w,h); //최대공약수
	w /= GCD;
	h /= GCD;
	
	int big = getBigger(w, h);
	int small = getSmaller(w, h);
	
	int result = big/small;
	int left = big%small;
	
	if(left == 0){
		answer = w*h*GCD*GCD-w*result*GCD;
	}
	else{
		answer = w*h*GCD*GCD - (result+1)*w*GCD;
	}
	
    return answer;
}

int main(void){
	
	cout << solution(1,1);
	
	
	return 0;
}