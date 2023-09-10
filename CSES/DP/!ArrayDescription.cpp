#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=1e5, mxM=1e2, M=1e9+7;
int n, m, x[mxN], dp[mxN+1][mxM+2]={};

int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1){
                cout << "i: " << i;
                dp[i][j]=1;
                //continue;
            }
            // if(x[i-1]==0){
            //     for(int k=j; k<=m; k++){
            //         dp[i][k]=dp[i-1][k-1]+dp[i-1][k]+dp[i-1][k+1];
            //     }
            // }
            // else{
            //     dp[i][x[i-1]]=dp[i-1][x[i-1]-1]+dp[i-1][x[i-1]]+dp[i-1][x[i-1]+1];
            // }
        }
        cout << '\n';
    }
    ll ans=0;
    for(int j=1; j<=n+1; j++){
        for(int i=1; i<=m; i++){
            cout << dp[1][i] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    // cout << ans;
      
    return 0;
}