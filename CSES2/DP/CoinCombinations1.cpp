#include <bits/stdc++.h>
using namespace std;

const int mxN=1e2, mxX=1e6, M=1e9+7;
int n, x, dp[mxX+1];
int c[mxN];
int main(void){
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> c[i];
    }
    dp[0]=1;
    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(i>=c[j]){
                dp[i]=(dp[i]+dp[i-c[j]])%M;
            }
        }
    }
    cout <<dp[x];



    return 0;
}