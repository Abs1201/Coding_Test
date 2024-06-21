#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void){
    ll n,k;
    cin >> n >> k;
    vector<int> v;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        v.push_back(a);
    }
    map<ll, ll> m;
    ll cnt=0;
    ll start=0;
    ll sum=0;
    for(int i=0; i<n; i++){
        m[v[i]]++;
        sum++;
        while(m.size()>k){
            m[v[start]]--;
            if(m[v[start]]==0){
                m.erase(v[start]);
                sum--;
            }
            start++;
        }
        cnt+=sum;
    }
    cout << cnt; 



    return 0;
}