#include <bits/stdc++.h>
using namespace std;
const int mxN=1e6;


int main(void){
	int n;
	cin >> n;
	int sum=n*(n+1)/2;
	if(sum&1){
		cout << "NO";
		return 0;
	}
	sum/=2;
	set<int> s1, s2;
	int t=n;
	for(int i=1, j=n; i<j; i++){
		if(sum<t){
			s1.insert(j);
			t+=j;
			j--;
		}
		else if(sum>t){

		}
		else{
			
		}
	}
	// 1 2 3 yes
	// 1 2 3 4 yes
	// 1 2 3 4 5 no
	// 1 2 3 4 5 6 7 yes
	//division of sum/2
	if()

	return 0;
}