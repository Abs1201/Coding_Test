#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=2e5;
int n, k[mxN];

int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> k[i];
    }

    map<ll, ll> mp;
    ll start=0, ans=0;
    for(ll end=0; end<n; end++){
        //ntg
        if(mp.find(k[end])==mp.end()){
            mp.insert({k[end], end});
        }
        else{
            if(mp[k[end]]>=start)
                start=mp[k[end]]+1;
            mp[k[end]]=end;
            ans=max(ans, end-start+1);
        }
    }
    cout << ans;
    

    return 0;
}