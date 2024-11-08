#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mxN=1e5, mxM=2e5;
int a, b;
int n, m, c[mxN];

vector<int> adj[mxN];

void dfs(int u, int cu=0){
    if(~c[u]){
        
    }
}

int main(void){
    cin >> n >> m;
    for(int i=0; i<3; i++){
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(c, -1, sizeof(int)*n);
    for(int i=0; i<n; i++){
        if(c[i] < 0){
            dfs(i);
        }
    }

    // 5 7
    // 2 4 1 2 7
    ll prev=0, count=0;
    map<ll, ll> m;
    m[0]=1;
    for(int i=0; i<n; i++){
        prev+=v[i];
        count+=m[prev-x];
        m[prev]++;
    }
    cout << count;


    return 0;
}