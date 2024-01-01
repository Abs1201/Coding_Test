#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e5, mxM=2e5;
int n,m;
vector<array<ll,2>> adj[mxN];
ll d[mxN];

int main(void){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back({c,b});
    }
    priority_queue<array<ll, 2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
    pq.push({0,0});
    d[0]=0;
    while(pq.size()){
        array<ll,2> u=pq.top();
        pq.pop();
        if(u[0]>d[d[1]]){
            continue;
        }
        for(array<ll,2> v: adj[u[1]]){
            if(d[v[1]] > )
        }
    }

    return 0;
}