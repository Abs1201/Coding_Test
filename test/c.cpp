//Array Description
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=1e5, mxM=100, M=1e9+7;
int n, m, arr[mxN], dp[mxN+1][mxM+2];

int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    memset(dp[0], 1, 4*(mxM+2));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i-1]){
                dp[i][j]
            }
            else{

            }
        }
    }

    int ans=0;
    for(int v: dp[n]){
        ans+=v;
    }
    cout << ans;


    return 0;
}