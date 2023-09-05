#include <bits/stdc++.h>

using namespace std;

#define ll longlong

int main(void){

	ll n;
	cin >> n;
	ll total,sub;
	for(int i = 1; i <= n; i++){
		total = i*i*(i*i-1);
		sub = 4*(i-1)*(i-2);
		cout << total-sub << endl;
	}

	return 0;
}