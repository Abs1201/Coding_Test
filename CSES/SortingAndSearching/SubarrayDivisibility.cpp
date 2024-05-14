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
        pref=(pref+v[i])%n;
        cnt+=m[abs(pref)];
        m[abs(pref)]++;
    }
 
    /*
    3 1 2 7 4
    3 4 1 3 2
 
    1 -
    */
 
    cout << cnt;
 
 
 
    return 0;
}