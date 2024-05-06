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
    int ans1[mxN]={0,}, ans2[mxN]={0,};
    // default is 0
    // fill_n(ans1, mxN, 0);
    // fill_n(ans2, mxN, 0);
 
    for(ll i=0; i<n; i++){
        ll a, b;
        cin >> a>>b;
        v.push_back({a, b, i});
    }
    sort(v.begin(), v.end(), compare);
    multiset<int> ms;
    multiset<int>::iterator it;

    ll min=v.rbegin()->at(1);
    ms.insert(min);
    for(int i=n-2; i>=0; i--){
        if(v[i].at(1)>=min){
            int count=distance(ms.begin(), ms.upper_bound(v[i].at(1)));
            ans1[v[i].at(2)]=count;
        } 
        else{
            min=v[i].at(1);
        }
        ms.insert(v[i].at(1));
    }

    ms.clear();

    ll max=v[0].at(1);
    ms.insert(max);
    for(int i=1; i<n; i++){
        if(v[i].at(1) <= max){
            int count=distance(ms.lower_bound(v[i].at(1)), ms.end());
            ans2[v[i].at(2)]=count;
        }
        else{
            max=v[i].at(1);
        }
        ms.insert(v[i].at(1));
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