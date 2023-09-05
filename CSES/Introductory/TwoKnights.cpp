#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){

	ll n;
	cin >> n;
	ll total,sub;
	for(ll i = 1; i <= n; i++){
		total = i*i*(i*i-1)/2;
		sub = 4*(i-1)*(i-2);
		cout << total-sub << endl;
	}

	return 0;
}