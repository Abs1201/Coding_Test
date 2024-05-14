#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void){
    ll n,x;
    cin >> n >> x;
    
    vector<ll> v;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        v.push_back(a);
    }
    ll count=0;
    ll prev=0;
    map<ll, ll> m;
    m[0]=1;
    for(int i=0;i <n; i++){
        prev+=v[i];
        count+=m[prev-x];
        m[prev]++;
    }

    cout << count;


    return 0;
}