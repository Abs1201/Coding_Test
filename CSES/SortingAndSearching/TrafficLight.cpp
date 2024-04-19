#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int mxN=2e5;

int main(void){
    ll x, n;
    cin >> x >> n;
    ll p[mxN];
    for(int i=0; i<n; i++){
        cin >> p[i];
    }

    set<pair<ll, ll>> ranges;
    multiset<ll> lens;

    ranges.insert({0,x});
    lens.insert(x);
    set<pair<ll,ll>>::iterator it;

    for(int i=0; i<n; i++){
        it=ranges.upper_bound({p[i], 0});
        it--;
        ll start=it->first;
        ll end=it->second;
        ranges.erase(it);
        ranges.insert({start, p[i]});
        ranges.insert({p[i], end});
        lens.erase(lens.find(end-start));
        lens.insert(p[i]-start);
        lens.insert(end-p[i]);
        cout << *lens.rbegin() << " ";
    }

    // set<array<ll,2>> tmp;
    // set<array<ll,3>>::iterator it2;
    // ll one=it->first;
    // ll two=it->second;
    // ll three=it->third;

    return 0;
}