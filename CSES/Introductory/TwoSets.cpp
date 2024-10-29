#include <bits/stdc++.h>

using namespace std;

#define ll long

const int mxN=1e6;


int main(void){
	ll n;
	cin >> n;
	ll sum=n*(n+1)/2;
	if(sum&1){
		cout << "NO";
		return 0;
	}
	ll target = sum/2;
	vector<int> v1, v2;
	for(int i=n; i>=1; i--){
		if(target>=i){
			v1.push_back(i);
			target-=i;
		}
		else{
			v2.push_back(i);
		}
	}
	cout << "YES" << endl;
	cout << v1.size() << endl;
	for(int i:v1){
		cout << i << " ";
	}
	cout << endl;
	cout << v2.size() << endl;
	for(int i:v2){
		cout << i << " ";
	}

	return 0;
}