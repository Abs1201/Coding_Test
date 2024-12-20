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
    //bool ans1[mxN]={0}, ans2[mxN]={0};
    // default is 0
    // fill_n(ans1, mxN, 0);
    // fill_n(ans2, mxN, 0);
    vector<bool> ans1(mxN, 0);
    vector<bool> ans2(mxN, 0);
 
    for(ll i=0; i<n; i++){
        ll a, b;
        cin >> a>>b;
        v.push_back({a, b, i});
    }
    sort(v.begin(), v.end(), compare);
    
    ll max=v[0].at(1);
    for(int i=1; i<n; i++){
        if(v[i].at(1) <= max) ans2[v[i].at(2)]=1;
        else{
            max=v[i].at(1);
        }
    }

    ll min=v.rbegin()->at(1);
    for(int i=n-2; i>=0; i--){
        if(v[i].at(1)>=min) ans1[v[i].at(2)]=1;
        else{
            min=v[i].at(1);
        }
    }

    for(int i=0; i<n; i++){
        cout << ans1[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++){
        cout << ans2[i] << " ";
    }
 
    return 0;
}