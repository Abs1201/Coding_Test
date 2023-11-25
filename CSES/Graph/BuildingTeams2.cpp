#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=1e5, mxm=2e5;
vector<int> adj[mxN];
int p[mxN], n , m;

void dfs(int u, int cu=0){
    if(p[u]<0){
        p[u]=cu;
        for(int v: adj[u]){
            dfs(v, cu^1);
        }
    }
    else{
        if(p[u]^cu){
            cout << "IMPOSSIBLE";
            exit(0);
        }
    }
}

int main(void){
    cin >> n >> m;
    for(int i=0, a, b; i<m; i++){
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(p, -1, 4*n);
    for(int i=0; i<n; i++){
        if(p[i]<0){
            dfs(i);
        }
    }
    for(int i=0; i<n; i++){
        cout << p[i]+1 << " ";
    }
    
    
    return 0;
}
