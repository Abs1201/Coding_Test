#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=2e5;

int main(void){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin>>sticks[i];
    }
    sort(sticks,sticks+n);
    ll ans=0;
    int c=sticks[n/2];
    for(int i=0; i<n; i++){
        ans+=abs(sticks[i]-c);
    }
    cout << ans;
    return 0;
} 