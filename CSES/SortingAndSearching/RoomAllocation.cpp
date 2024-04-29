#include <bits/stdc++.h>
#define ll long long 
using namespace std;
 
const int mxN=2e5;
 
int main(void){
    ll n;
    cin >> n;
    vector<array<ll, 3>> v;
    for(ll i=0; i<n; i++){
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b, i});
    }
    sort(v.begin(), v.end());
    
    ll ans[mxN];
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    int roomCnt=0;
    for(ll i=0; i<n; i++){
        if(pq.empty() || pq.top().first >= v[i].at(0)){
            roomCnt++;
            pq.push({v[i].at(1), roomCnt});
            ans[v[i].at(2)]=roomCnt;
        }
        else{
            // cout << "pqF: " << pq.top().first << endl;
            // cout << "vat0: " << v[i].at(0) << endl;
            ll roomNum=pq.top().second;
            pq.pop();
            pq.push({v[i].at(1), roomNum});
            ans[v[i].at(2)]=roomNum;
        }
    }
    
    cout << roomCnt << endl;
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}