#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3, M=1e9+7;
string s[mxN];
int dp[mxN][mxN];
int main(void){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >>s[i];
    }
    dp[0][0]=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i){
                dp[i][j]+=dp[i-1][j];
            }
            if(j){
                dp[i][j]+=dp[i][j-1];
            }
            dp[i][j]%=M;
            if(s[i][j]=='*'){
                dp[i][j]=0;
            }
        }
    }
    cout << dp[n-1][n-1];

    return 0;
}