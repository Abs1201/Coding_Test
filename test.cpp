#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e5;
int n, m;
ll d[mxN]; 
vector<array<ll, 2>> adj[mxN];

int main(void){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back({c,b});
    }

    d[0]=0;
    priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
    pq.push({0,0});
    while(pq.size()){
        array<ll,2> v=pq.top();
        pq.pop();
        if(v[0] > d[v[1]]){
            continue;
        }
        for(array<ll,2> ar: )
    }
    
    return 0;
}