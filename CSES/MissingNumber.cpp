#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){

	ll n, s=0;
	cin >> n;
	for(int i = 0 ;i < n-1; i++){
		int in;
		cin >> in;
		s+= in;
		
	}
	
	cout << n*(n+1)/2 -s;
	
	
	return 0;
}