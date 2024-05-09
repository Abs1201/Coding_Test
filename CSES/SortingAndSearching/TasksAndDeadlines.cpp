//Tasks and Deadlines
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int mxN=1e6;
 
int main(void){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> v;
    for(ll i=0; i<n; i++){
        ll a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
 
    ll timeSum=0, rewards=0;
    for(ll i=0; i<n; i++){
        timeSum+=v[i].first;
        rewards+=(v[i].second-timeSum);
    }
 
    cout << rewards;
 
    return 0;
