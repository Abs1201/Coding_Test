#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int mxN=2e5;
 
bool compare(array<ll, 3> a1, array<ll, 3> a2){
    if(a1.at(0)!=a2.at(0)) return a1.at(0)<a2.at(0);
    return a1.at(1)>a2.at(1);
}
 
int main(void){
    ll n;
    cin >> n;
    
    vector<array<ll,3>> v;
    bool ans1[mxN]={0}, ans2[mxN]={0};
    // default is 0
    // fill_n(ans1, mxN, 0);
    // fill_n(ans2, mxN, 0);
 
    for(ll i=0; i<n; i++){
        ll a, b;
        cin >> a>>b;
        v.push_back({a, b, i});
    }
    sort(v.begin(), v.end(), compare);
    
    ll max=v[0].at(1);
    for(int i=1; i<n; i++){
        if(v[i].at(1) <)
    }
 
 
    return 0;
}