#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void){

	int n;
	cin >> n;
	long long ans = n*(n+1) / 2;
	for(int i = 0; i < n-1; i++){
		int in;
		cin >> in;
		ans-=in;
	}
	cout << ans;
	
	
	return 0;
}