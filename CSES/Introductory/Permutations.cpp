#include <bits/stdc++.h>

using namespace std;


int main(void){

	int n;
	cin >> n;
	while(n!=1){
		if(n%2!=0){
			cout << n << " ";
			n *= 3+1;
		}
		else{
			cout << n << " ";
			n/=2;
		}
	}

	return 0;
}