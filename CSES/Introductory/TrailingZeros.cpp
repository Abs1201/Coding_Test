#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){

	int n;
    cin >> n;
    int ans=0;
    for(int i=5; i<=n; i*=5){
        ans+=n/i;
    }
    cout << ans;
	
	return 0;
}