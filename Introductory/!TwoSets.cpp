#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){

	int n;
	cin >> n;
	ll sum = n*(n+1)/2;
	if(sum%2==1){
		cout << "NO";
		return 0;
	}

	//sum/2 if 7-> 14 make 14.
	// 1 2 4 5 
	ll s=0;
	vector<int> v1,v2;
	for(int i = 1; i <= n; i++){
		while(s!=sum/2){
			v1.append(i);
			s+=i;
		}
	}
	

	
	return 0;
}