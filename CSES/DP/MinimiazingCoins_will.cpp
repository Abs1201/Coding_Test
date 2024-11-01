#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=100, mxX=1e6;
int n, c[mxN], x;
ll dp[mxX+1];

int main(void){
    int n, x;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> c[i];
    }
    for(int i=1; i<=x; i++){
        dp[i]=1e9;
        for(int j=0; j<n; j++){
            if(i>=c[j]){
                dp[i]=min(dp[i], dp[i-c[j]]+1);
            }
        }
    }
    if(dp[x]==1e9){
        cout << -1;
        return 0;
    }
    cout << dp[x];

    return 0;
}