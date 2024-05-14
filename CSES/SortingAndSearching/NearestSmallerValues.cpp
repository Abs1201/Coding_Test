#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void){
    ll n;
    cin >> n;
    
    vector<pair<ll, ll>> v;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        v.push_back({a, i});
    }
    stack<pair<ll, ll>> s;
    vector<int> ans;
    for(int i=0; i<n; i++){
        pair<ll, ll> tmp;
        while(!s.empty()){
            tmp=s.top();
            if(v[i].first <= tmp.first){
                s.pop();
            }
            else break;
        }
        if(s.empty()){
            ans.push_back(0);
        }
        else{
            //cout << tmp.first << " " << tmp.second << endl;
            ans.push_back(tmp.second+1);
        }
        s.push(v[i]);
    }

    for(int a: ans){
        cout << a << " ";
    }
    cout << endl;

    return 0;
}