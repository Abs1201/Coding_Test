//array description
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M=1e9+7, mxN=1e5, mxM=100;
int n ,m, a[mxN];
ll dp[mxN][mxM];

int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i], --a[i];
    }
    for(int i=0; i<n; i++){
        if(i){
            
        }
        else{
            for(int j=0; j<m; j++){
                dp[0][j]=1;
            }
            dp[i]
        }
    }
    ll ans;
    for(int i=0; i<m; i++){
        ans+=dp[n-1][i];
    }

    return 0;
}