#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=1e5, mxM=2e5, mxC=1e9;
int n, m;
vector<array<ll,2>> adj[mxN], 
ll d[mxN];
bool vis[mxN];

int main(void){
    cin >> n >> m;
    //n: node, m: line
    for(int i=0, a, b, c; i<m; i++){
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back({c, b});
    }
    priority_queue<array<ll,2>, vector<array<ll,2>, greater<array<ll,2>>> pq;

    pq.push({0,0});
    memset(d, 0x3f, sizeof(d));
    d[0]=0;
    while(pq.size()){
        array<ll,2> u =pq.top();
        pq.pop();
        if(u[0]>d[u[1]]){//가중치 비교.
            continue;
        }
        for(array<ll,2> v: adj[u[0]]){
            if(d[v[1]]>d[u[1]]+v[0]){
                d[v[1]]=d[u[1]]+v[0];
                pq.push({d[v[1],v[1]]});
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << d[i] << " ";
    }

    return 0;
}