#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(void){
    ll n;
    cin >> n;
    vector<ll> v;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        v.push_back(a);
    }
 
    map<ll, ll> m;
    m[0]=1;
    ll pref=0;
    ll cnt=0;
    for(int i=0; i<n; i++){
        pref=((pref+v[i])%n+n)%n;
        cnt+=m[pref];
        m[pref]++;
    }
 
    /*
    4
    5 -65 -67 -67
    5 -60 -127 -194
    1 0 -3 -2
    */
 
    cout << cnt;
 
 
 
    return 0;
}