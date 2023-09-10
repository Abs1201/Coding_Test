#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=1e5, mxM=2e5, mxC=1e9;
int n, m;
vector<array<ll,2>> adj[mxN], 
ll ans[mxN];
bool vis[mxN];

int main(void){
    cin >> n >> m;
    //n: node, m: line
    for(int i=0, a, b, c; i<m; i++){
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    //priority_queue<array<ll,2>, vector<array<ll,2>, greater<array<ll,2>>> pq;
    memset(ans, 0x3f, ans.size());
    for(int i=0; i<n; i++){
        if(!vis[i]){
            for(int j=0; j<adj[i].size(); j++){
                ans[adj[i][0]]=min(ans[i],adj[i][1]);
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << ans[i];
    }

    return 0;
}