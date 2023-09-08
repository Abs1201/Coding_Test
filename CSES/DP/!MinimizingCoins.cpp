#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=100, mxX=1e6;
int c[mxN];
vector<int> dp(mxX, 1e6);
//c[0]=1
int Solve(int n, int x){
    if(x==0) return 0;
    if(x<0) return 1e6;
    if(dp[x]!=1e6) return dp[x];
    int ans=1e6;
    for(int i=0; i<n; i++){
        ans=min(ans, Solve(n, x-c[i])+1);
    }
    dp[x]=ans;
    return ans;
}

int main(void){
    int n, x;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> c[i];
        dp[c[i]]=1;
    }
    int ans=Solve(n,x);
    if(ans==1e6){
        cout << -1;
        return 0;
    }
    cout << ans;

    return 0;
}