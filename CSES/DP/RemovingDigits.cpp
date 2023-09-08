#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=1e6;

int main(void){
    int n;
    cin >> n;
    ll dp[mxN+1];
    for(int i=1; i<=n; i++){
        dp[i]=1e9;
        int i2=i;
        while(i2){
            dp[i]=min(dp[i], dp[i-i2%10]+1);
            i2/=10;
        }
    }
    cout << dp[n];
    
    return 0;
}