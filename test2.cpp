#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN = 2e5+5;
ll dp[mxN];
 
 
 
int main(void){
    
    
    int n; cin>>n;

    // ll a[n+1] = {0};
    // for (int i = 1; i <= n; i++) 
    //     cin>>a[i];
    // sort(a, a+n+1);
    // dp[0] = 1;
    // for (int i = 1; i <= n; i++) {
    //     if (dp[i-1] < a[i]) return cout<<dp[i-1], 0;
    //     dp[i] = dp[i-1] + a[i];
    // }
    // cout<<dp[n];
 
    n=5;
    int a[n];
    iota(a,a+n, 0);
    for(int i: a){
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}
