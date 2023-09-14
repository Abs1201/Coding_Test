#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=1e6;
int dp[mxN+1];

int main(void){
    ll n;
    cin >> n;
    //
    ll n2=n, tmp, ans=0;
    while(n>0){
        tmp=0;
        while(n2>0){
            tmp=max(tmp, tmp%10);
            n2/=10;
        }
        n-=tmp;
        n2=n;
        ans++;
    }
    cout << ans;

    return 0;
}