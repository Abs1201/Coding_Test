#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN=1e5, mxM=2e5;
int n, m, p[mxN];
vector<int> adj[mxN], ans, vis[mxN];

void dfs(int u, int v){

}

int main(void){
    cin >> n >> m;
    for(int i=0, a, b; i<m; i++){
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    

    return 0;
}