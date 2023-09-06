#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=2e5;

int main(void){
    int n;
    cin >> n;
    ll ans=-1e9, sum=-1e9;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        sum=max(a, sum+a);
        ans=max(sum, ans);

    }
    cout << ans;

    return 0;
} 