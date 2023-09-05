#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){

	ll n;
	cin >> n;
    ll a=1;
    int ans=0;
	for(ll i = 1; i <= n; i++){
        a*=i;
        if(a>=10&&a%10==0){
            ans++;
        }
        a%=10;
    }
    cout << ans;
	
	return 0;
}