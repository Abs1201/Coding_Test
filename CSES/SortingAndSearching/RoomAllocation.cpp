#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int mxN=2e5;

bool compare(array<ll,4> a, array<ll,4> b){
    return a[2] < b[2];
}

int main(void){
    vector<array<ll,4>> ms;
    ll n;
    cin >> n;
    for(ll i=0, a, b; i<n; i++){
        cin >> a >> b;
        ms.push_back({a, b, i, 0});
    }
    sort(ms.begin(), ms.end());
    
    vector<ll> v(1,0);
    vector<array<ll,4>>::iterator it;
    for(it=ms.begin(); it!=ms.end(); it++){
        ll t=it->at(1);
        for(int i=0; i<v.size(); i++){
            if(v[i]<t){
                v[i]=t;
                it->at(3)=i;
                continue;
            }
            if(i==v.size()-1){
                v.push_back(t);
                it->at(3)=i;
            }
        }
    }
    sort(ms.begin(), ms.end(), compare);
    for(it=ms.begin(); it!=ms.end(); it++){
        cout << it->at(3) << " ";
    }
    cout << endl;

    


    return 0;
}