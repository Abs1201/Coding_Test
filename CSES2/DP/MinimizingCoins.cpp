#include <bits/stdc++.h>
using namespace std;

const int mxN=1e2, mxX=1e6;
int n, x, dp[mxX];
int c[mxN];
int main(void){
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
        cout <<-1;
    }
    else{
        cout << dp[x];
    }



    return 0;
}