#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){

	ll n;
	cin >> n;

	ll ans = 1;
	for(int i = 0 ; i < n; i++){
		ans=ans*2%(ll)(1e9+7);
	}
	cout << ans;
	
	return 0;
}