#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN=2e5;

int main(void){
    ll n;
    cin >> n;
    vector<array<ll, 3>> v;
    for(ll i=0, a, b; i<n; i++){
        cin >> a >> b;
        v.push_back({a, b, i});
    }
    sort(v.begin(), v.end());

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    int roomCnt=0;        
    ll ans[mxN];
    for(int i=0; i<n; i++){
        ll t=v[i].at(1);
        ll idx=v[i].at(2);
        if(pq.empty() || pq.top().first >=t){
            roomCnt++;
            pq.push({t, roomCnt});
            ans[idx]=roomCnt;
        }
        else{
            ll bIdx=pq.top().second;
            pq.pop();
            pq.push({t, bIdx});
            ans[idx]=bIdx;
        }
    }

    cout << roomCnt << endl;
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }


    return 0;
}